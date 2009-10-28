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
    void setWindowing(int);
    void setCorrelation(int);
    void setContinousCapturing(bool);
    void startTransfer();
    void stopTransfer();
    void runWindowing();
    void runCorrelation();
    void setConnection();
    void setDisconnection();
    void setStatus(QString, int);
    void tcpError( QAbstractSocket::SocketError socketError ) ;
    void readTcp();


private:
    void   handleInputData()  ;        // from Ethernet
    void   displayInput()     ;
    void   clearDisplay()     ;


    bool   continousCapturing        ;
    bool   continousCaptureReq       ;
    int    windowType                ;
    int    correlationType           ;
    int    connectionState           ;
    int    stateOfHandling           ;  // 0 - initial; 1 - started ; 2 - stopped ?
    float  windowedSignals   [512][4];
    float  correlatedSignals [512]   ;

    QByteArray   inputData           ;
    QString      tcpServerAddress    ;   // initially 192.168.1.5 set inside constructor
    int          tcpPort             ;   // initially 40000 set inside constructor
    //unsigned short input_short[512*4];
    QTcpSocket   *q_pSocket          ;
    QList<QByteArray> m_data         ;
    QVector<short> m_parsedData      ;
    QVector<short> m_triggeredData   ;

signals:
    void sigDrawLine(int selectedWindow, int x1, int y1, int x2, int y2);
    void sigSetStatus(QString text, int sec);

};

#endif
