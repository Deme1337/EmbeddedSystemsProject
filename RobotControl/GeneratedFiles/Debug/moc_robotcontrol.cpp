/****************************************************************************
** Meta object code from reading C++ file 'robotcontrol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../robotcontrol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'robotcontrol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RobotControl_t {
    QByteArrayData data[10];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RobotControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RobotControl_t qt_meta_stringdata_RobotControl = {
    {
QT_MOC_LITERAL(0, 0, 12), // "RobotControl"
QT_MOC_LITERAL(1, 13, 24), // "on_actionStart_triggered"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 32), // "on_actionVertical_Flip_triggered"
QT_MOC_LITERAL(4, 72, 9), // "triggered"
QT_MOC_LITERAL(5, 82, 37), // "on_action_Horizontal_Mirror_t..."
QT_MOC_LITERAL(6, 120, 7), // "checked"
QT_MOC_LITERAL(7, 128, 9), // "SetClient"
QT_MOC_LITERAL(8, 138, 14), // "StartListening"
QT_MOC_LITERAL(9, 153, 13) // "StopListening"

    },
    "RobotControl\0on_actionStart_triggered\0"
    "\0on_actionVertical_Flip_triggered\0"
    "triggered\0on_action_Horizontal_Mirror_triggered\0"
    "checked\0SetClient\0StartListening\0"
    "StopListening"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RobotControl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    1,   45,    2, 0x08 /* Private */,
       5,    1,   48,    2, 0x08 /* Private */,
       7,    0,   51,    2, 0x08 /* Private */,
       8,    0,   52,    2, 0x08 /* Private */,
       9,    0,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RobotControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RobotControl *_t = static_cast<RobotControl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionStart_triggered(); break;
        case 1: _t->on_actionVertical_Flip_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_action_Horizontal_Mirror_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->SetClient(); break;
        case 4: _t->StartListening(); break;
        case 5: _t->StopListening(); break;
        default: ;
        }
    }
}

const QMetaObject RobotControl::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_RobotControl.data,
      qt_meta_data_RobotControl,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RobotControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RobotControl::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RobotControl.stringdata0))
        return static_cast<void*>(const_cast< RobotControl*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int RobotControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
