/****************************************************************************
** Meta object code from reading C++ file 'bacondemo.h'
**
** Created: Thu Apr 14 17:07:06 2011
**      by: The Qt Meta Object Compiler version 59 (Qt 4.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "bacondemo.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bacondemo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_BaconDemo[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      17,   11,   10,   10, 0x05,
      41,   35,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      59,   10,   10,   10, 0x0a,
      67,   10,   10,   10, 0x0a,
      75,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_BaconDemo[] = {
    "BaconDemo\0\0score\0scoreChanged(int)\0level\0levelChanged(int)\0"
    "start()\0pause()\0showInstructions()\0"
};

const QMetaObject BaconDemo::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_BaconDemo,
      qt_meta_data_BaconDemo, 0 }
};

const QMetaObject *BaconDemo::metaObject() const
{
    return &staticMetaObject;
}

void *BaconDemo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BaconDemo))
	return static_cast<void*>(const_cast<BaconDemo*>(this));
    return QFrame::qt_metacast(_clname);
}

int BaconDemo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: scoreChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: levelChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: start(); break;
        case 3: pause(); break;
        case 4: showInstructions(); break;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void BaconDemo::scoreChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BaconDemo::levelChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
