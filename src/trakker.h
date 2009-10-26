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


#ifndef TRAKKER_H
#define TRAKKER_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QGraphicsWidget>
#include <QPointer>
#include <QtGui>
#include <QVector>
#include "../forms/centralwidget.h"

class QAction;
class QMenu;
class QGraphicsView;
class QGraphicsScene;
class QWidget;
class Ui_centralWidget;




class trakker: public QMainWindow
{
    Q_OBJECT

public:
    friend class trakkercontroller ;
    trakker();
    ~trakker();
    void addText(QString);

public slots:
    void drawLine(int which, int, int, int, int);
    void setStatus(QString text, int sec);

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void about()        ;
    //void increment()  ;
    void start()        ;
    void stop()         ;
    void windowSlot()   ;
    void correlation()  ;
    void connection()   ;
    void disconnection();

private:
    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();
    void createGraphics();

    QMenu *fileMenu; // main
    QMenu *ethMenu ; // ethernet menu
    QMenu *helpMenu; // additional menu

    QToolBar *firstToolBar; // buttons : start gathering, stop gathering, save samples set, load samples set, [...] , exit

    QAction *exitAct        ;
    QAction *aboutAct       ;
    QAction *aboutQtAct     ;
    QAction *startAct       ;
    QAction *stopAct        ;
    QAction *windowAct      ;
    QAction *correlationAct ;
    QAction *connectionAct  ;
    QAction *disconnectionAct;

    QGraphicsScene *scena;
    QGraphicsView *grafika;

    QWidget *pWidget;
    Ui::centralWidget * pCentralWidget;

    QVector<QGraphicsScene *> vector ;

    int counter1; // to text signal/slot behaviour

signals:
    //void sigTrigger(int counter1);
    void sigStart();
    void sigStop();
    void sigWindow();
    void sigCorrelation();
    void sigConnection();
    void sigDisconnect();

};

#endif


/*
#ifndef TRAKKER_H
#define TRAKKER_H

class trakker
{
public:
    trakker();
};

#endif // TRAKKER_H
*/

