/***************************************************************************
 *   Copyright (C) 2009 by zienek   *
 *   zienekp@wp.pl   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "trakkermodel.h"
#include "windows_512.h"

#include <complex.h>
#include <fftw3.h>
#include <math.h>

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <QByteArray>
#include <QDebug>
#include <QTime>

static const int windowPlotWidth      = 128;
static const int correlationPlotWidth = 512 ;
static const int windowedPlotWidth    = 252;
static const int inputPlotWidth       = 512;
static const int bufferSize           = 512;


QByteArray czop(const QByteArray & str){  // this function chop all characters from QByteArray which are not Digits
    QByteArray ret;

    Q_FOREACH(QChar c , str){
        if( ( c.isDigit() )||(c=='-'))
            ret += c;
    }
    return ret;
}

QVector<double> correlation(const QVector<double> in, int size, int offset1, int offset2){ // sigA and sigB must have the same size

    QVector<double> out;
    double tmp ;

    int          n = size        ;
    int delayLimit = bufferSize/2;   // +/- 256 = for 512 x 48000 x 1m distance
    int delay                    ;
    int        i = 0 ,     j = 0 , m = 0;
    double meanA = 0 , meanB = 0 ;
    double    sA = 0 ,    sB = 0 , sTmp = 0 ;
    double         normalize = 0 ;

    QVector<double>x;//(p_sigA);
    QVector<double>y;//(p_sigB);
    QVector<double> result;

    for(i = 0 ; i <bufferSize; i++){
        x.push_back( in.at(i + offset1*size));
        y.push_back( in.at(i + offset2*size));
    }

    for( i=0 ; i<n ; i++){
        meanA += x[i];
        meanB += y[i];
    }
    meanA = meanA/n;    // rescale mean value
    meanB = meanB/n;    // of both signals

    for ( i=0 ; i<n ; i++){
        sA += (x[i]-meanA) * (x[i]-meanA);
        sB += (y[i]-meanB) * (y[i]-meanB);
    }

    normalize = sqrt(sA*sB);

    out.clear();
    tmp = 0;
    for( delay = -delayLimit ; delay < delayLimit; delay++){
        sTmp = 0 ;
        for(m=0 ; m<n ; m++){
            j = m + delay;
            if ((j < 0) || (j>= n))
                continue;
                //sTmp += (p_sigA[m] - meanA) * (p_sigB[j%n] - meanB); //continue;
            else
                sTmp += (x[m] - meanA) * (y[j] - meanB);
        }
        tmp = sTmp/normalize;
        out.push_back(tmp);
        //qDebug() << out.at(delay);
    }

    return out;

}

trakkermodel::trakkermodel(){
    chosenSignals       = 0            ; // default draw correlation of signals (0) 1-2 ; (1) 1-3; (2) 1-4; (3) 2-3; (4) 2-4; (5) 3-4
    connectionState     = 0            ;
    continousCapturing  = false        ;
    continousCaptureReq = false        ;
    correlationType     = 0            ;
    stateOfHandling     = 0            ;
    tcpServerAddress    = "192.168.1.5";
    tcpPort             = 40000        ;
    windowType          = 0            ;
    samplingFreq        = 44000        ;
    b_capturingPause    = false        ;
    b_correlationDone   = false        ;
    b_signalPresent     = false        ;
    dataSlot            = 0            ;
    command             = 0x00000000   ;
    latchValue          = 0            ;  //between 0 and 1023 but precisely 512-1023

    corrColor.resize(6);
    corrColor.fill('b');
    corrVisible.resize(6);
    corrVisible.fill(FALSE);

    inputData.resize(4*2*bufferSize)   ;
    m_windowShape.resize(bufferSize)   ;

    q_pSocket = new QTcpSocket(this);

    connect ( q_pSocket, SIGNAL(readyRead()), this,SLOT(readTcp()));
}

trakkermodel::~trakkermodel(){
    q_pSocket->abort();
}


void trakkermodel::appendCorrToView(int posOfColor){
    char character;
    switch(posOfColor){
        case 0:
                character = 'b'; // blues
                break;
        case 1:
                character = 'r'; // red
                break;
        case 2:
                character = 'g'; //green
                break;
        case 3:
                character = 'k'; //blacK
                break;
        case 4:
                character = 'c'; // cyan
                break;
        case 5:
                character = 'm'; //magenta
                break;
        default:
                character = 'b'; // default blue
                break;
    }

    switch(chosenSignals){
        case 0:
                corrColor[0]   = character;
                corrVisible[0] = TRUE     ;
                break;
        case 1:
                corrColor[1]   = character;
                corrVisible[1] = TRUE     ;
                break;
        case 2:
                corrColor[2]   = character;
                corrVisible[2] = TRUE     ;
                break;
        case 3:
                corrColor[3]   = character;
                corrVisible[3] = TRUE     ;
                break;
        case 4:
                corrColor[4]   = character;
                corrVisible[4] = TRUE     ;
                break;

        case 5:
                corrColor[5]   = character;
                corrVisible[5] = TRUE     ;
                break;

        default:
                qDebug() << "Chosen signal ma wartosci spoza 0-5";
                break;
    }

}

void trakkermodel::clearDisplay(){
    emit sigDrawLine(0,0,0,0,0);
    emit sigDrawLine(1,0,0,0,0);
    emit sigDrawLine(2,0,0,0,0);
    emit sigDrawLine(3,0,0,0,0);
}

void trakkermodel::clearCorrView(){
     emit sigDrawLine (9,0,0,0,0);
     corrVisible.fill(FALSE,6);
}

void trakkermodel::displayInput(){

    sigDrawLine(0, 0, 0, 0, 128 ,'k');
    sigDrawLine(1, 0, 0, 0, 128 ,'k');
    sigDrawLine(2, 0, 0, 0, 128 ,'k');
    sigDrawLine(3, 0, 0, 0, 128 ,'k');

    for (int i = 0 ; i< inputPlotWidth -1 ; i++){
        emit sigDrawLine(0, i, m_triggeredData[i]/*[dataSlot]*//8, i+1,                                  m_triggeredData[i+1]/*[dataSlot]*//8 );
        if (m_triggeredData[i] < latchValue){
            b_capturingPause = true;
        }
        emit sigDrawLine(1, i, m_triggeredData[bufferSize+i]/*[dataSlot]*//8, i+1,                       m_triggeredData[bufferSize+i+1]/*[dataSlot]*//8 );
        emit sigDrawLine(2, i, m_triggeredData[bufferSize+bufferSize+i]/*[dataSlot]*//8, i+1,            m_triggeredData[bufferSize+bufferSize+i+1]/*[dataSlot]*//8 );
        emit sigDrawLine(3, i, m_triggeredData[bufferSize+bufferSize+bufferSize+i]/*[dataSlot]*//8, i+1, m_triggeredData[bufferSize+bufferSize+bufferSize+i+1]/*[dataSlot]*//8 );
    }
    sigDrawLine(0, 0, latchValue/8, 512, latchValue/8,'r');

}

void trakkermodel::displayCorrelation(){

    if (TRUE==b_correlationDone){
        for(int i = 0 ; i < correlationPlotWidth - 30 ; i++){ // draw result
            emit sigDrawLine(9, i , corr[chosenSignals].at(i) , i+1 , corr[chosenSignals].at(i+1) ,corrColor.at(chosenSignals) );
        }

    }else
        setStatus("Calculate CrossCorrelation first",4000);
}

void trakkermodel::handleInputData(bool doIt){ // handle data from ethernet

    if ( connectionState < 1 ){ // not connected or failed
        emit sigSetStatus("Connect to server via Ethernet before capturing data",4000);

    }else{
        if((connectionState == 1)&&(doIt)){ // is connected, and user want it
            //QByteArray command("",4);

            if ( -1 == q_pSocket->write(command))
                qDebug() << "error " ;

            command[0] = command[0]+1;
            //qDebug() << command;

            if(continousCaptureReq == 1)
                continousCapturing = 1;
            else
                continousCapturing = 0;
        }

    }
}

void trakkermodel::loadInput(){
    //qDebug() << "TODO: load input samples from txt file dialog";


    QString fName = QFileDialog::getOpenFileName(NULL,("Open File"), QDir::currentPath(),("Trakker Data (*.tra)"));
    if (QFile::exists(fName)){
        QFile f(fName);
        if (f.open(QIODevice::ReadOnly)){
            QDataStream in (&f);
            quint16 numberOfChannels  ;
            quint16 sizeOfEachChannel ;

            in >> numberOfChannels ;
            if (numberOfChannels != 4){
                QMessageBox mesBox;
                mesBox.setDefaultButton(QMessageBox::Ok);
                mesBox.setText("Wrong number of channels, or file corrupted.");
            }else{
                in >> sizeOfEachChannel ;
                if (sizeOfEachChannel != bufferSize){
                QMessageBox mesBox;
                mesBox.setDefaultButton(QMessageBox::Ok);
                mesBox.setText("Wrong length of channelsor file corrupted.");
                }
                else{
                    m_triggeredData.clear();
                    in >> m_triggeredData ;
                }
            }
            f.close();

            clearCorrView();
            b_signalPresent = true ;
            displayInput();
        }
    clearCorrView();
    }
}

void trakkermodel::refreshInput(){
    sigDrawLine(0, 0, 0, 0, 0 );
    sigDrawLine(1, 0, 0, 0, 0 );
    sigDrawLine(2, 0, 0, 0, 0 );
    sigDrawLine(3, 0, 0, 0, 0 );

    displayInput();
}

void trakkermodel::setBitrate(int number){ // command == 50 000 000 / bitrate
    switch(number){
        case 0:
            command = "1041"; // 48kbps
            break;
        case 1:
            command = "1134"; // 44.1 kbps
            break;
        case 2:
            command = "2083"; // 24kbps
            break;
        case 3:
            command = "1041"; //22.05 kbps
            break;
        case 4:
            command = "4166"; // 12kbps
            break;
        case 5:
            command = "5000"; // 10kbps
            break;
        case 6:
            command = "6250"; // 8kbps
            break;
        case 7:
            command = "8333"; //6kbps
            break;
        case 8:
            command = "8333"; //4kbps
            break;
        default:
            command = "1041";
            break;



    }

}

void trakkermodel::setLatchValue(int val){
    latchValue = val;
    if( b_signalPresent)
        refreshInput();
}

void trakkermodel::setWindowing(int window){   // type i.e. 0 rectangular; 1 triangular; 2 blackman; 3 hamming; 4 gauss; 5 nuttall; 6 blackman-hamming; 7 blackman-nuttall

    this->windowType = window ;

    switch (window)
    {

        case 7: // blackman Nuttall
                emit sigDrawLine(4, 0, 0, 0, 0); // clean display

                for(int i = 0 ; i < windowPlotWidth -1 ; i++){
                    emit sigDrawLine(4,i  ,99- 90*blackmanNuttallWindow[4*i] , i+1 ,99- 90*blackmanNuttallWindow[4*i + 4]);
                }
                break;

        case 6: // blackman-harris
                emit sigDrawLine(4, 0, 0, 0, 0); // clean display

                for(int i = 0 ; i < windowPlotWidth -1 ; i++){
                    emit sigDrawLine(4,i  ,99- 90*blackmanHarrisWindow[4*i] , i+1 ,99- 90*blackmanHarrisWindow[4*i + 4]);
                }
                break;

        case 5: // nuttall
                emit sigDrawLine(4, 0, 0, 0, 0); // clean display

                for(int i = 0 ; i < windowPlotWidth -1 ; i++){
                    emit sigDrawLine(4,i  ,99- 90*nuttallWindow[4*i] , i+1 ,99- 90*nuttallWindow[4*i + 4]);
                }
                break;

        case 4: // gauss
                emit sigDrawLine(4, 0, 0, 0, 0); // clean display

                for(int i = 0 ; i < windowPlotWidth -1 ; i++){
                    emit sigDrawLine(4,i  ,99- 90*gaussWindow[4*i] , i+1 ,99- 90*gaussWindow[4*i + 4]);
                }
                break;

        case 3: // hamming
                emit sigDrawLine(4, 0, 0, 0, 0); // clean display

                for(int i = 0 ; i < windowPlotWidth -1 ; i++){
                    emit sigDrawLine(4,i  ,99- 90*hammingWindow[4*i] , i+1 ,99- 90*hammingWindow[4*i + 4]);
                }
                break;

        case 2: // blackman
                emit sigDrawLine(4, 0, 0, 0, 0); // clean display

                for(int i = 0 ; i < windowPlotWidth -1 ; i++){
                    emit sigDrawLine(4,i  ,99- 90*blackmanWindow[4*i] , i+1 ,99- 90*blackmanWindow[4*i + 4]);
                }
                break;

        case 1:
                emit sigDrawLine(4, 0, 0, 0, 0);    // clean display

                for(int i = 0 ; i < windowPlotWidth -1 ; i++){
                    emit sigDrawLine(4,i  ,99- 90*triangularWindow[4*i] , i+1 ,99- 90*triangularWindow[4*i + 4]);
                }

                break;

        case 0:

        default:
                emit sigDrawLine(4, 0, 0, 0, 0);    //clean display

                emit sigDrawLine(4,  0,99, 10,99);    // draw lines
                emit sigDrawLine(4, 10,99, 10, 0);
                emit sigDrawLine(4, 10,0 ,118, 0);
                emit sigDrawLine(4,118,0 ,118,99);
                emit sigDrawLine(4,118,99,128,99);

                this->windowType = 0;
                qDebug("Default value in trakkermodel::setWindowing \n");
                break;

    }
}

void trakkermodel::setCorrelation(int type){
    this->correlationType = type ;
}

void trakkermodel::startTransfer(){ // this function should transfer data trough ethernet
    continousCapturing = continousCaptureReq ;
    setWindowing(windowType);
    b_capturingPause = false;
    handleInputData(TRUE);
}

void trakkermodel::stopTransfer(){ // this function should stop capturing data
    continousCapturing = 0 ;
    b_capturingPause = true;
    handleInputData(FALSE);
}

void trakkermodel::runCorrelation(){  // if all signals have to be processed ? or better (int int) choose 3 signals to process CrossCorrelation?

    int i = 0; // counter

    emit sigDrawLine(9,256,-250,256,250,'k');
    emit sigDrawLine(9,  0,0,510,  0,'k'); // crosshair

    for(i = 0 ; i < 10 ; i++){
        corr[i].clear();
    }

    b_correlationDone = TRUE ;

    fftw_complex /**ff1,*/ *ff2;  // made regarding to fftw3.pdf p.9
    fftw_plan fftplans[10];
    fftw_plan ifftplans[10];


    //ff1     = (fftw_complex *) fftw_malloc(sizeof(fftw_complex)*bufferSize) ;
    ff2     = (fftw_complex *) fftw_malloc(sizeof(fftw_complex)*bufferSize) ;


    switch (correlationType){
        case 0:
            corr[0] = correlation(windowedSignals,  bufferSize, 0, 1);
            corr[1] = correlation(windowedSignals,  bufferSize, 0, 2);
            corr[2] = correlation(windowedSignals,  bufferSize, 0, 3);
            corr[3] = correlation(windowedSignals,  bufferSize, 1, 2);
            corr[4] = correlation(windowedSignals,  bufferSize, 1, 3);
            corr[5] = correlation(windowedSignals,  bufferSize, 2, 3);
            for(i = 0 ; i < 6; i ++){
                fftplans[i]  = fftw_plan_dft_r2c_1d(bufferSize, &corr[i][0], ff2, FFTW_ESTIMATE);
                ifftplans[i] = fftw_plan_dft_c2r_1d(bufferSize, ff2, &corr[i][0], FFTW_ESTIMATE);
            }

            for (int j = 0 ; j < 6 ; ++j){
                fftw_execute(fftplans[j]);              // execute fft
                fftw_execute(ifftplans[j]);             // execute ifft

                fftw_destroy_plan( fftplans[j]);        // wash up dishes
                fftw_destroy_plan(ifftplans[j]);
            }


            break;
        case 1:
            corr[0] = correlation(windowedSignals,  bufferSize, 0, 1);
            corr[1] = correlation(windowedSignals,  bufferSize, 0, 2);
            corr[2] = correlation(windowedSignals,  bufferSize, 0, 3);
            corr[3] = correlation(windowedSignals,  bufferSize, 1, 2);
            corr[4] = correlation(windowedSignals,  bufferSize, 1, 3);
            corr[5] = correlation(windowedSignals,  bufferSize, 2, 3);
            for(i = 0 ; i < 6; i ++){
                fftplans[i]  = fftw_plan_dft_r2c_1d(bufferSize, &corr[i][0], ff2, FFTW_ESTIMATE);
                ifftplans[i] = fftw_plan_dft_c2r_1d(bufferSize, ff2, &corr[i][0], FFTW_ESTIMATE);
            }

            for (int j = 0 ; j < 6 ; ++j){
                fftw_execute(fftplans[j]);              // execute fft
                fftw_execute(ifftplans[j]);             // execute ifft

                fftw_destroy_plan( fftplans[j]);        // wash up dishes
                fftw_destroy_plan(ifftplans[j]);
            }


            break;
        case 2:



            break;
        case 3:



            break;
        case 4:



            break;
        case 5:



            break;
        default:


            break;
    }

//    corr11 = correlation(windowedSignals, bufferSize, 0, 0);
//    corr22 = correlation(windowedSignals, bufferSize, 1, 1);
//    corr33 = correlation(windowedSignals, bufferSize, 2, 2);
//    corr44 = correlation(windowedSignals, bufferSize, 3, 3);

    // for each corr make fft and save in another place in memory

//    for (int j = 0 ; j < 11; j++){
//        for (int i = 0 ; i < bufferSize; ++i){
//            ff1[i] = (double) windowedSignals[i][0];
//        }
//    }





   // displayCorrelation();

    //for (i = 0 ; i < bufferSize ; i++)
        //ff2[i] *= normFactor ;


//    for(int i = 0 ; i < correlationPlotWidth - 30 ; i++){ // draw result
//        //emit sigDrawLine(9,2*i  ,creal(ff2[2*i]) , 2*i+1, creal( ff2[2*i+1]));
//        //qDebug() << i ;
//        emit sigDrawLine(9, i , 512*corrOut.at(i) , i+1 , 512*corrOut.at(i+1) );
//    }
}

void trakkermodel::runWindowing(){
    windowedSignals.clear();
    windowedSignals.resize(2048);

    switch (this->windowType)
    {
        case 7:
            for(int i = 0 ; i < bufferSize ; ++i){
                this->windowedSignals[i             ] = 512 + blackmanHarrisWindow[i] * (m_triggeredData[i               ]/*[dataSlot]*/-512); // m_triggeredData contain 10 valid bits
                this->windowedSignals[i+bufferSize  ] = 512 + blackmanHarrisWindow[i] * (m_triggeredData[i + bufferSize  ]/*[dataSlot]*/-512); // so 1024 values
                this->windowedSignals[i+bufferSize*2] = 512 + blackmanHarrisWindow[i] * (m_triggeredData[i + bufferSize*2]/*[dataSlot]*/-512); // relative level '0' is
                this->windowedSignals[i+bufferSize*3] = 512 + blackmanHarrisWindow[i] * (m_triggeredData[i + bufferSize*3]/*[dataSlot]*/-512);
            }
            break;

        case 6:
            for(int i = 0 ; i < bufferSize ; ++i){
                this->windowedSignals[i             ] = 512 + blackmanNuttallWindow[i] * (m_triggeredData[i               ]/*[dataSlot]*/-512);
                this->windowedSignals[i+bufferSize  ] = 512 + blackmanNuttallWindow[i] * (m_triggeredData[i + bufferSize  ]/*[dataSlot]*/-512);
                this->windowedSignals[i+bufferSize*2] = 512 + blackmanNuttallWindow[i] * (m_triggeredData[i + bufferSize*2]/*[dataSlot]*/-512);
                this->windowedSignals[i+bufferSize*3] = 512 + blackmanNuttallWindow[i] * (m_triggeredData[i + bufferSize*3]/*[dataSlot]*/-512);
            }
            break;

        case 5:
            for(int i = 0 ; i < bufferSize ; ++i){
                this->windowedSignals[i             ] = 512 + nuttallWindow[i] * (m_triggeredData[i               ]/*[dataSlot]*/-512);
                this->windowedSignals[i+bufferSize  ] = 512 + nuttallWindow[i] * (m_triggeredData[i + bufferSize  ]/*[dataSlot]*/-512);
                this->windowedSignals[i+bufferSize*2] = 512 + nuttallWindow[i] * (m_triggeredData[i + bufferSize*2]/*[dataSlot]*/-512);
                this->windowedSignals[i+bufferSize*3] = 512 + nuttallWindow[i] * (m_triggeredData[i + bufferSize*3]/*[dataSlot]*/-512);
            }
            break;

        case 4:
            for(int i = 0 ; i < bufferSize ; ++i){
                this->windowedSignals[i             ] = 512 +  gaussWindow[i] * (m_triggeredData[i                ]/*[dataSlot]*/-512);
                this->windowedSignals[i+bufferSize  ] = 512 + gaussWindow[i] * (m_triggeredData[i + bufferSize   ]/*[dataSlot]*/-512);
                this->windowedSignals[i+bufferSize*2] = 512 + gaussWindow[i] * (m_triggeredData[i + bufferSize*2 ]/*[dataSlot]*/-512);
                this->windowedSignals[i+bufferSize*3] = 512 + gaussWindow[i] * (m_triggeredData[i + bufferSize*3 ]/*[dataSlot]*/-512);
            }
            break;

        case 3:
            for(int i = 0 ; i < bufferSize ; ++i){
                this->windowedSignals[i             ] = 512 + hammingWindow[i] * (m_triggeredData[i                ]/*[dataSlot]*/-512);
                this->windowedSignals[i+bufferSize  ] = 512 + hammingWindow[i] * (m_triggeredData[i + bufferSize   ]/*[dataSlot]*/-512);
                this->windowedSignals[i+bufferSize*2] = 512 + hammingWindow[i] * (m_triggeredData[i + bufferSize*2 ]/*[dataSlot]*/-512);
                this->windowedSignals[i+bufferSize*3] = 512 + hammingWindow[i] * (m_triggeredData[i + bufferSize*3 ]/*[dataSlot]*/-512);
            }
            break;

        case 2:
            for(int i = 0 ; i < bufferSize ; ++i){
                this->windowedSignals[i             ] = 512 + blackmanWindow[i] * (m_triggeredData[i                ]/*[dataSlot]*/-512);
                this->windowedSignals[i+bufferSize  ] = 512 + blackmanWindow[i] * (m_triggeredData[i + bufferSize   ]/*[dataSlot]*/-512);
                this->windowedSignals[i+bufferSize*2] = 512 + blackmanWindow[i] * (m_triggeredData[i + bufferSize*2 ]/*[dataSlot]*/-512);
                this->windowedSignals[i+bufferSize*3] = 512 + blackmanWindow[i] * (m_triggeredData[i + bufferSize*3 ]/*[dataSlot]*/-512);
            }
            break;

        case 1:
            for(int i = 0 ; i < bufferSize ; ++i){
                this->windowedSignals[i             ] = 512 + triangularWindow[i] *( m_triggeredData[i                ]/*[dataSlot]*/-512);
                this->windowedSignals[i+bufferSize  ] = 512 + triangularWindow[i] * (m_triggeredData[i + bufferSize   ]/*[dataSlot]*/-512);
                this->windowedSignals[i+bufferSize*2] = 512 + triangularWindow[i] * (m_triggeredData[i + bufferSize*2 ]/*[dataSlot]*/-512);
                this->windowedSignals[i+bufferSize*3] = 512 + triangularWindow[i] * (m_triggeredData[i + bufferSize*3 ]/*[dataSlot]*/-512);
            }
            break;

        case 0:
            for(int i = 0 ; i < bufferSize ; ++i){
                this->windowedSignals[i                ] = 512 + rectangularWindow[i] * (m_triggeredData[i                ]/*[dataSlot]*/-512);
                this->windowedSignals[i + bufferSize   ] = 512 + rectangularWindow[i] * (m_triggeredData[i + bufferSize   ]/*[dataSlot]*/-512);
                this->windowedSignals[i + bufferSize*2 ] = 512 + rectangularWindow[i] * (m_triggeredData[i + bufferSize*2 ]/*[dataSlot]*/-512);
                this->windowedSignals[i + bufferSize*3 ] = 512 + rectangularWindow[i] * (m_triggeredData[i + bufferSize*3 ]/*[dataSlot]*/-512);
            }
            break;

        default:
            qDebug("default value in trakkermodel::setWindowing function");
            break;
    } //end switch

    emit sigDrawLine(5,0,0,0,0); //clear windowedSignal plot area ;
    emit sigDrawLine(6,0,0,0,0); //clear windowedSignal plot area ;
    emit sigDrawLine(7,0,0,0,0); //clear windowedSignal plot area ;
    emit sigDrawLine(8,0,0,0,0); //clear windowedSignal plot area ;

    // emit sigDrawLine(5,0,64,250,64);  todo make a frame around window

    for(int i = 0 ; i < windowedPlotWidth -1 ; i++){
        emit sigDrawLine(5,i  ,127- this->windowedSignals[2*i]/8 , i+1 ,127- windowedSignals[2*i + 2]/8);
        emit sigDrawLine(6,i  ,127- this->windowedSignals[2*i+bufferSize  ]/8 , i+1 ,127- windowedSignals[2*i + 2+bufferSize  ]/8);
        emit sigDrawLine(7,i  ,127- this->windowedSignals[2*i+bufferSize*2]/8 , i+1 ,127- windowedSignals[2*i + 2+bufferSize*2]/8);
        emit sigDrawLine(8,i  ,127- this->windowedSignals[2*i+bufferSize*3]/8 , i+1 ,127- windowedSignals[2*i + 2+bufferSize*3]/8);
    }
}

void trakkermodel::saveCorrToBmp(){
    qDebug() << "TODO: save correlation coefficient  as bmp Dialog";
}

void trakkermodel::saveCorrToTxt(){
    qDebug() << "TODO: save correlation coefficient as txt Dialog";
    bool bExit;

    QString fName = QFileDialog::getOpenFileName(NULL,("Open File"), QDir::currentPath(),("Trakker Data (*.tra)"));
    if (QFile::exists(fName)){
        QMessageBox mesBox;
        mesBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        mesBox.setText("Do you want to overwrite?");
        if (mesBox.exec() != QMessageBox::Yes){
            bExit = true;
        }

    }
    if(!bExit){
        QFile f(fName);
        if (f.open(QIODevice::WriteOnly)){
            QDataStream out (&f);
            out << corr[0] ;
            out << corr[1] ;
            out << corr[2] ;
            out << corr[3] ;
            out << corr[4] ;
            out << corr[5] ;
        }
    }


}

void trakkermodel::saveInputToBmp(){
    qDebug() << "TODO: save input samples as bmp Dialog";
}

void trakkermodel::saveInputToTxt(){
    qDebug() << "TODO: save input samples as txt Dialog";
    bool bExit;
    QString fName = QFileDialog::getOpenFileName(NULL,("Open File"), QDir::currentPath(),("Trakker Data (*.tra)"));
    if (QFile::exists(fName)){
        QMessageBox mesBox;
        mesBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        mesBox.setText("Do you want to overwrite?");
        if (mesBox.exec() != QMessageBox::Yes){
            bExit = true;
        }

    }
    if(!bExit){
        QFile f(fName);
        if (f.open(QIODevice::WriteOnly)){
            QDataStream out (&f);

            out.setVersion(QDataStream::Qt_4_0);
            out << (quint16)4;                  //number of channels
            out << (quint16)bufferSize;         //size of each buffer
            //out << (quint16)m_triggeredData;    //data in short
            //foreach(short i, m_triggeredData){
            //    out << i;
            //}
            out << m_triggeredData;

            f.close();
        }
    }
}

void trakkermodel::setSignals(int whichSig){
    this->chosenSignals = whichSig ;
    //displayCorrelation();
}

void trakkermodel::setStatus(QString text, int sec){
    emit sigSetStatus(text, sec);
}

void trakkermodel::setConnection(){

    connect ( q_pSocket,SIGNAL( error ( QAbstractSocket::SocketError) ),this,SLOT(tcpError( QAbstractSocket::SocketError ))) ;

    if (connectionState == 1){ // connection already set sucesfully
        emit sigSetStatus("Already connected",2000);
    }
    else {
        if (connectionState < 1){ // connection not set ('0') or failed ('-1)        
            q_pSocket->connectToHost( tcpServerAddress, tcpPort);

            if (q_pSocket->waitForConnected(3000)==false){
                emit sigSetStatus("Failed to connect TCP Socket to server",2000);
                qDebug("Failed to connect inside setConnection\n");
                connectionState = -1 ;
            }else{
                emit sigSetStatus("TCP connection estabilished sucessfully",2000);
                connectionState = 1 ;
            }

        }
    }


}

void trakkermodel::setDisconnection(){
    q_pSocket->disconnectFromHost();
    //if(q_pSocket->disconnected())
    connectionState = 0 ;
}

void trakkermodel::tcpError( QAbstractSocket::SocketError socketError ) {
    qDebug() << socketError ;
}

void trakkermodel::setContinousCapturing(bool flag){   //TODO continous capturing
    this->continousCaptureReq  = !flag;
}

void trakkermodel::readTcp(){
    QByteArray m_tcpBuffer = q_pSocket->read(q_pSocket->bytesAvailable());

    if(b_capturingPause==false){
        if (m_tcpBuffer.size() % 2 == 0 ) { // if 'a' has even elements
            for ( int i = 0 ; i < m_tcpBuffer.size() - 1 ; i+=2 ) {
                unsigned char one =m_tcpBuffer.at(i);
                unsigned char two = m_tcpBuffer.at(i+1) ;
                m_parsedData.push_back( (short)((int)two)*256 + (int)one );
            }
        }else{ //if 'a' has odd elements
            for ( int i = 0 ; i < m_tcpBuffer.size() - 1 ; i+=2 ) {
                char one = m_tcpBuffer.at(i);
                char two = m_tcpBuffer.at(i+1) ;
                m_parsedData.push_back( (short)((int)two)*256 + (int)one );
                qDebug() << " m_parsedData has odd elements";
            }
        }

        if ( (4*bufferSize) < m_parsedData.size() ){ // if there is enough elements to fill the m_triggeredData data set - Just do it.

            //dataSlot = (dataSlot+1)%3;
            m_triggeredData/*[dataSlot]*/ = m_parsedData;
            m_triggeredData/*[dataSlot]*/.remove(2048 , m_parsedData.size()-2048  ) ;
            m_parsedData.remove(0, 2048);// erase elements rewritten to m_triggeredData

        clearDisplay();
        b_signalPresent = true ;
        displayInput();
        if (TRUE==continousCapturing)     // after each full data set ask kindly for next one
            handleInputData(TRUE);

        }
    }
}

