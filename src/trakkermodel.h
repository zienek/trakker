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
#ifndef TRAKKERMODEL_H
#define TRAKKERMODEL_H

#include <QObject>
#include <QWidget>
#include <QtNetwork/QTcpSocket>
#include <vector>

class QObject;
class QWidget;
class QTcpSocket;
class QString;

class trakkermodel :public QObject {
    Q_OBJECT
public:
    friend class trakkercontroller ;
    trakkermodel();
    ~trakkermodel();

public slots:

    void appendCorrToView(int);
    void displayCorrelation() ;
    void loadInput();
    void refreshInput();
    void runCorrelation();
    void runWindowing();
    void runTdoa();
    void saveCorrToBmp();
    void saveCorrToTxt();
    void saveInputToBmp();
    void saveInputToTxt();
    void setBitrate(int);
    void setConnection();
    void setDisconnection();
    void setContinousCapturing(bool);
    void setCorrelation(int);
    void setWindowing(int);
    void setSignals(int);
    void startTransfer();
    void stopTransfer();

    void setLatchValue(int);


private slots:
    void clearCorrView();
    void readTcp();
    void setStatus(QString, int);
    void tcpError( QAbstractSocket::SocketError socketError ) ;



private:
    void   handleInputData(bool);        // from Ethernet
    void   displayInput()       ;
    void   clearDisplay()       ;
    void   drawHyper(float, float, int);


    bool   continousCapturing        ;
    bool   continousCaptureReq       ;
    int    windowType                ;
    int    correlationType           ;
    int    chosenSignals             ;  // to draw proper correlation in drawCorrelationPlot(int)
    int    connectionState           ;
    bool   b_capturingPause          ;
    bool   b_correlationDone         ;
    bool   b_signalPresent           ;
    int    stateOfHandling           ;  // 0 - initial; 1 - started ; 2 - stopped ?
    //double windowedSignals   [512][4];
    float  correlatedSignals [512]   ;
    int    samplingFreq              ; // initial 44000
    int    dataSlot                  ;
    int    latchValue                ;
    int    samplesPerMeter           ; // for 44000 there are 130 samples per meter
    QByteArray command               ;

    QByteArray   inputData           ;
    QString      tcpServerAddress    ;   // initially 192.168.1.5 set inside constructor
    int          tcpPort             ;   // initially 40000 set inside constructor
    QTcpSocket   *q_pSocket          ;
    QList<QByteArray> m_data         ;
    QVector<short> m_parsedData      ;
    QVector<short> m_triggeredData   ;
    QVector<double>windowedSignals   ;
    QVector<double> m_windowShape    ;
    QVector<int>  m_delays           ;


    QVector<double> corr[10]         ;// (array position)signal1 - signal2;      (0)1-2; (1)1-3; (2)1-4; (3)2-3; (4)2-4; (5)3-4; (6)1-1; (7)2-2; (8)3-3; (9)4-4

    double fftResult[10][512]        ;// to save fft results

    QVector<bool> corrVisible        ;  // to be sure, what is visible on corr view; (0)1-2 ; (1)1-3; (2)1-4; (3)2-3; (4)2-4; (5)3-4
    QVector<char> corrColor          ;  // color for each correlation plot


signals:
    void sigDrawLine(int selectedWindow, int x1, int y1, int x2, int y2, char color = 'b',const QTransform & = QTransform(1,0,0,1,0,0) );
    void sigSetStatus(QString text, int sec);
    //void sigRequestForHandler();

};

#endif
