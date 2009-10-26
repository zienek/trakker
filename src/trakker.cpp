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

#include "trakker.h"
#include "../forms/centralwidget.h"

#include <QtGui>
#include <QTextEdit>
#include <QTextStream>
#include <QCloseEvent>
#include <QFileDialog>
#include <QColor>
#include <QGraphicsWidget>

#include <iostream>

trakker::trakker() : fileMenu(NULL)
 {
      resize(1000,700);
      createActions();
      createMenus();
      createToolBars();
      createStatusBar();
      createGraphics();
}

void trakker::closeEvent(QCloseEvent *event)
{
      event->accept();
}

void trakker::about()
{
      QMessageBox::about(this, tr("About Trakker"),
            tr("The <b>Trakker</b> Is a program which demonstrates how "
                  "some sound localization algorithms are working."));
}

void trakker::connection(){
    emit sigConnection();
}

void trakker::createActions() // contains actions: About; About QT; Correlation; Exit
{
    aboutAct = new QAction(tr("&About"), this);                         // shows window containing info about program
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAct = new QAction(tr("About &Qt"), this);                    // shows window containing info about QT
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    connectionAct = new QAction(tr("Con&nect"), this);       // runs function responsible for ethernet connection initialization
    connectionAct->setStatusTip(tr("Initializing network connection"));
    //connectionAct->setShortcut(tr("n"));
    connectionAct->setShortcut(tr("N"));
    connect(connectionAct, SIGNAL(triggered()), this, SLOT(connection()));

    correlationAct = new QAction(tr("&Correlation"),this);              // runs correlation algorithm in MVC controller
    correlationAct->setStatusTip(tr("Calculating correlation"));
    correlationAct->setShortcut(tr("c"));
    correlationAct->setShortcut(tr("C"));
    connect(correlationAct, SIGNAL(triggered()),this, SLOT(correlation()));

    disconnectionAct = new QAction(tr("&Disconnect"), this);
    disconnectionAct->setStatusTip(tr("Disconnect current network link"));
    disconnectionAct->setShortcut(tr("d"));
    disconnectionAct->setShortcut(tr("D"));
    connect(disconnectionAct, SIGNAL(triggered()), this, SLOT(disconnection()));

    exitAct = new QAction(tr("E&xit"), this);                           // exits programm
    exitAct->setShortcut(tr("Q"));
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    startAct = new QAction(tr("Start&"),this);                          // start receiving data from ethernet connection
    startAct->setStatusTip(tr("Start Gathering Input Data"));
    //startAct->setShortcut(tr("s"));
    startAct->setShortcut(tr("S"));
    connect(startAct,SIGNAL(triggered()),this,SLOT(start()));

    stopAct = new QAction(tr("Stop&"),this);                            // stops receiving data from ethernet
    stopAct->setStatusTip(tr("Start Gathering Input Data"));
    stopAct->setShortcut(tr("Shift+s"));
    stopAct->setShortcut(tr("Shift+S"));
    connect(stopAct,SIGNAL(triggered()),this,SLOT(stop()));

    windowAct = new QAction(tr("&Windowing"),this);                     // runs windowing algorithm
    windowAct->setShortcut(tr("w"));
    windowAct->setShortcut(tr("W"));
    connect(windowAct,SIGNAL(triggered()),this,SLOT(windowSlot()));
}

void trakker::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(exitAct);
    //fileMenu->addAction(incrementAct);
    fileMenu->addAction(windowAct);
    fileMenu->addAction(correlationAct);

    ethMenu = menuBar()->addMenu(tr("&Ethernet"));
    ethMenu->addAction(connectionAct);
    ethMenu->addAction(disconnectionAct);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
}

void trakker::createToolBars()
{
    firstToolBar = addToolBar(tr("General"));
    firstToolBar->addAction(startAct);
    firstToolBar->addAction(stopAct);
    firstToolBar->addAction(exitAct);
}

void trakker::createStatusBar()
{
      statusBar()->showMessage(tr("Ready"));
}

void trakker::createGraphics()
{
      pWidget = new QWidget(this) ;
      pCentralWidget = new Ui::centralWidget() ;
      pCentralWidget->setupUi( pWidget ) ;
      setCentralWidget(pWidget);

      for (int i = 0 ; i < 10 ; ++i)  // 4 input signal + 1 window shape + 4 signals after windowing + correlation
      {
          vector.push_back( new QGraphicsScene() );
      }

      pCentralWidget->graphicsView_1->setScene(vector[0]); // input signal 1
      pCentralWidget->graphicsView_2->setScene(vector[1]); // input signal 2
      pCentralWidget->graphicsView_3->setScene(vector[2]); // input signal 3
      pCentralWidget->graphicsView_4->setScene(vector[3]); // input signal 4

      pCentralWidget->graphicsViewWindow->setScene(vector[4]);  // window shape (rectangular, triangular, blackmann, hanning);

      pCentralWidget->graphicsView_5->setScene(vector[5]); // signal 1 after windowing
      pCentralWidget->graphicsView_6->setScene(vector[6]); // signal 2 after windowing
      pCentralWidget->graphicsView_7->setScene(vector[7]); // signal 3 after windowing
      pCentralWidget->graphicsView_8->setScene(vector[8]); // signal 4 after windowing


      pCentralWidget->graphicsView_9->setScene(vector[9]); // signals after correlation

}

void trakker::correlation(){ // runs correlation algorithm in controller
    emit sigCorrelation();
    statusBar()->showMessage(tr("Correlation calculation started."));
}

void trakker::disconnection(){
    emit sigDisconnect();
    statusBar()->showMessage(tr("Disconnecting"));
}

void trakker::drawLine(int which, int x1, int y1, int x2, int y2)
{
    if ( (x1==0) and (x2==0) and (y1==0) and(y2==0) ) {  // command to add line [0,0][0,0] clears display
        emit vector[which]->clear();
    }else{

        vector[which]->addLine(x1,y1,x2,y2,QPen(Qt::blue)); // any normal line will be displayed
    }
}

void trakker::setStatus(QString text, int sec){
    statusBar()->showMessage(text, sec);
}

void trakker::start(){
    emit sigStart();
    statusBar()->showMessage(tr("Gathering input samples started."));
}

void trakker::stop(){
    emit sigStop();
    statusBar()->showMessage(tr("Gathering input samples stopped."));
}

void trakker::windowSlot(){
    emit sigWindow();
    statusBar()->showMessage(tr("Windowing signals."));
}

trakker::~trakker()
{

}
