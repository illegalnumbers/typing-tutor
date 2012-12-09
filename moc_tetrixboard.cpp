/****************************************************************************
** Meta object code from reading C++ file 'tetrixboard.h'
**
** Created: Thu Apr 14 17:07:19 2011
**      by: The Qt Meta Object Compiler version 59 (Qt 4.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "tetrixboard.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tetrixboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_TetrixBoard[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      19,   13,   12,   12, 0x05,
      43,   37,   12,   12, 0x05,
      70,   61,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      95,   12,   12,   12, 0x0a,
     103,   12,   12,   12, 0x0a,
     111,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TetrixBoard[] = {
    "TetrixBoard\0\0score\0scoreChanged(int)\0level\0levelChanged(int)\0"
    "numLines\0linesRemovedChanged(int)\0start()\0pause()\0"
    "showInstructions()\0"
};

const QMetaObject TetrixBoard::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_TetrixBoard,
      qt_meta_data_TetrixBoard, 0 }
};

const QMetaObject *TetrixBoard::metaObject() const
{
    return &staticMetaObject;
}

void *TetrixBoard::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TetrixBoard))
	return static_cast<void*>(const_cast<TetrixBoard*>(this));
    return QFrame::qt_metacast(_clname);
}

int TetrixBoard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: scoreChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: levelChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: linesRemovedChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: start(); break;
        case 4: pause(); break;
        case 5: showInstructions(); break;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void TetrixBoard::scoreChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TetrixBoard::levelChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TetrixBoard::linesRemovedChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
