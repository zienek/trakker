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
#include "trakkercontroller.h"
#include <memory>
#include <cassert>
#include <QObject>
#include <QWidget>
#include "src/trakkermodel.h"
#include "src/trakker.h"

trakkercontroller::trakkercontroller()
{

}

trakkercontroller::~trakkercontroller()
{
}

trakkercontroller * trakkercontroller::instance() {
    static std::auto_ptr<trakkercontroller> apTrContr ( new trakkercontroller() ) ;
    return apTrContr.get() ;
}

void trakkercontroller::connectMua() {  // here connect all neccesary items
    assert ( m_pWindow && m_pModel ) ;
    QObject::connect( m_pModel ,  SIGNAL(sigDrawLine(int, int, int, int, int)), m_pWindow, SLOT(drawLine(int, int, int, int, int))) ;
    QObject::connect( (qobject_cast<trakker*>( m_pWindow))->pCentralWidget->comboBox, SIGNAL(highlighted(int)), m_pModel, SLOT(setWindowing(int))) ;
    QObject::connect( (qobject_cast<trakker*>( m_pWindow))->pCentralWidget->comboBox, SIGNAL(currentIndexChanged(int)), m_pModel, SLOT(setWindowing(int))) ;
    QObject::connect( m_pWindow, SIGNAL(sigStartTransfer()), m_pModel, SLOT(startTransfer()));
    QObject::connect( m_pWindow, SIGNAL(sigStopTransfer()), m_pModel, SLOT(stopTransfer()));
    QObject::connect( m_pWindow, SIGNAL(sigWindow()) , m_pModel, SLOT(runWindowing()));
    QObject::connect( m_pWindow, SIGNAL(sigCorrelation()) , m_pModel, SLOT(runCorrelation()));
    QObject::connect( (qobject_cast<trakker*>( m_pWindow))->pCentralWidget->comboBox_3, SIGNAL(highlighted(int)), m_pModel, SLOT(setCorrelation(int)));
    QObject::connect( (qobject_cast<trakker*>( m_pWindow))->pCentralWidget->comboBox_3, SIGNAL(currentIndexChanged(int)), m_pModel, SLOT(setCorrelation(int)));
    QObject::connect( m_pModel , SIGNAL(sigSetStatus(QString, int)) , m_pWindow , SLOT(setStatus(QString, int)));
    QObject::connect( m_pWindow, SIGNAL(sigConnection()), m_pModel , SLOT(setConnection()));
    QObject::connect( m_pWindow, SIGNAL(sigDisconnect()), m_pModel , SLOT(setDisconnection()));
    QObject::connect( (qobject_cast<trakker*>( m_pWindow))->pCentralWidget->radioButton_1, SIGNAL(toggled(bool)),m_pModel, SLOT(setContinousCapturing(bool)));
    QObject::connect( (qobject_cast<trakker*>( m_pWindow))->pCentralWidget->pushButton, SIGNAL(pressed()) ,m_pModel, SLOT(runWindowing()));

}
