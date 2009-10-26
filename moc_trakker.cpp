/****************************************************************************
** Meta object code from reading C++ file 'trakker.h'
**
** Created: Sat Oct 24 13:45:59 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/trakker.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trakker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_trakker[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,
      20,    8,    8,    8, 0x05,
      30,    8,    8,    8, 0x05,
      42,    8,    8,    8, 0x05,
      59,    8,    8,    8, 0x05,
      75,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
     101,   91,    8,    8, 0x0a,
     140,  131,    8,    8, 0x0a,
     163,    8,    8,    8, 0x08,
     171,    8,    8,    8, 0x08,
     179,    8,    8,    8, 0x08,
     186,    8,    8,    8, 0x08,
     199,    8,    8,    8, 0x08,
     213,    8,    8,    8, 0x08,
     226,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_trakker[] = {
    "trakker\0\0sigStart()\0sigStop()\0sigWindow()\0"
    "sigCorrelation()\0sigConnection()\0"
    "sigDisconnect()\0which,,,,\0"
    "drawLine(int,int,int,int,int)\0text,sec\0"
    "setStatus(QString,int)\0about()\0start()\0"
    "stop()\0windowSlot()\0correlation()\0"
    "connection()\0disconnection()\0"
};

const QMetaObject trakker::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_trakker,
      qt_meta_data_trakker, 0 }
};

const QMetaObject *trakker::metaObject() const
{
    return &staticMetaObject;
}

void *trakker::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_trakker))
        return static_cast<void*>(const_cast< trakker*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int trakker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sigStart(); break;
        case 1: sigStop(); break;
        case 2: sigWindow(); break;
        case 3: sigCorrelation(); break;
        case 4: sigConnection(); break;
        case 5: sigDisconnect(); break;
        case 6: drawLine((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 7: setStatus((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: about(); break;
        case 9: start(); break;
        case 10: stop(); break;
        case 11: windowSlot(); break;
        case 12: correlation(); break;
        case 13: connection(); break;
        case 14: disconnection(); break;
        default: ;
        }
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void trakker::sigStart()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void trakker::sigStop()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void trakker::sigWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void trakker::sigCorrelation()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void trakker::sigConnection()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void trakker::sigDisconnect()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}
QT_END_MOC_NAMESPACE
