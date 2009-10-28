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
#ifndef TRAKKERCONTROLLER_H
#define TRAKKERCONTROLLER_H

class QWidget ;
class trakkermodel ;


class trakkercontroller{
public:
    static trakkercontroller* instance() ;
    void setMainWindow( QWidget * pWidget ) { m_pWindow = pWidget ; }
    QWidget * getWindow() const { return m_pWindow ; }
    void setModel ( trakkermodel * pModel ) { m_pModel = pModel ; }
    trakkermodel * getModel() const { return m_pModel ; }
    void connectMua() ;

    ~trakkercontroller();

private:

    QWidget * m_pWindow ;
    trakkermodel *m_pModel;
    trakkercontroller();

    // do not implement !!
    trakkercontroller(const trakkercontroller & rhs );
    trakkercontroller* operator=(const trakkercontroller & rhs );

};

#endif
