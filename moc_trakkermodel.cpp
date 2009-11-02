/****************************************************************************
** Meta object code from reading C++ file 'trakkermodel.h'
**
** Created: Mon Nov 2 17:07:39 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/trakkermodel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trakkermodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_trakkermodel[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      41,   14,   13,   13, 0x05,
      83,   74,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
     109,   13,   13,   13, 0x0a,
     127,   13,   13,   13, 0x0a,
     147,   13,   13,   13, 0x0a,
     175,   13,   13,   13, 0x0a,
     191,   13,   13,   13, 0x0a,
     206,   13,   13,   13, 0x0a,
     221,   13,   13,   13, 0x0a,
     238,   13,   13,   13, 0x0a,
     254,   13,   13,   13, 0x0a,
     275,  273,   13,   13, 0x0a,
     310,  298,   13,   13, 0x0a,
     349,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_trakkermodel[] = {
    "trakkermodel\0\0selectedWindow,x1,y1,x2,y2\0"
    "sigDrawLine(int,int,int,int,int)\0"
    "text,sec\0sigSetStatus(QString,int)\0"
    "setWindowing(int)\0setCorrelation(int)\0"
    "setContinousCapturing(bool)\0startTransfer()\0"
    "stopTransfer()\0runWindowing()\0"
    "runCorrelation()\0setConnection()\0"
    "setDisconnection()\0,\0setStatus(QString,int)\0"
    "socketError\0tcpError(QAbstractSocket::SocketError)\0"
    "readTcp()\0"
};

const QMetaObject trakkermodel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_trakkermodel,
      qt_meta_data_trakkermodel, 0 }
};

const QMetaObject *trakkermodel::metaObject() const
{
    return &staticMetaObject;
}

void *trakkermodel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_trakkermodel))
        return static_cast<void*>(const_cast< trakkermodel*>(this));
    return QObject::qt_metacast(_clname);
}

int trakkermodel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sigDrawLine((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 1: sigSetStatus((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: setWindowing((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: setCorrelation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: setContinousCapturing((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: startTransfer(); break;
        case 6: stopTransfer(); break;
        case 7: runWindowing(); break;
        case 8: runCorrelation(); break;
        case 9: setConnection(); break;
        case 10: setDisconnection(); break;
        case 11: setStatus((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: tcpError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 13: readTcp(); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void trakkermodel::sigDrawLine(int _t1, int _t2, int _t3, int _t4, int _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void trakkermodel::sigSetStatus(QString _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
