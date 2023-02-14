/****************************************************************************
** Meta object code from reading C++ file 'serial_port.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../serial_port.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serial_port.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_serial_port_t {
    QByteArrayData data[11];
    char stringdata0[222];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_serial_port_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_serial_port_t qt_meta_stringdata_serial_port = {
    {
QT_MOC_LITERAL(0, 0, 11), // "serial_port"
QT_MOC_LITERAL(1, 12, 26), // "on_serialSwitchBtn_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 24), // "on_saveWidgetBtn_clicked"
QT_MOC_LITERAL(4, 65, 22), // "on_clearRecBtn_clicked"
QT_MOC_LITERAL(5, 88, 18), // "on_sendBtn_clicked"
QT_MOC_LITERAL(6, 107, 27), // "on_clearSendAreaBtn_clicked"
QT_MOC_LITERAL(7, 135, 27), // "on_saveFileCheckBox_clicked"
QT_MOC_LITERAL(8, 163, 7), // "checked"
QT_MOC_LITERAL(9, 171, 29), // "on_timingSendCheckBox_clicked"
QT_MOC_LITERAL(10, 201, 20) // "on_updataBtn_clicked"

    },
    "serial_port\0on_serialSwitchBtn_clicked\0"
    "\0on_saveWidgetBtn_clicked\0"
    "on_clearRecBtn_clicked\0on_sendBtn_clicked\0"
    "on_clearSendAreaBtn_clicked\0"
    "on_saveFileCheckBox_clicked\0checked\0"
    "on_timingSendCheckBox_clicked\0"
    "on_updataBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_serial_port[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    1,   59,    2, 0x08 /* Private */,
       9,    1,   62,    2, 0x08 /* Private */,
      10,    0,   65,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,

       0        // eod
};

void serial_port::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<serial_port *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_serialSwitchBtn_clicked(); break;
        case 1: _t->on_saveWidgetBtn_clicked(); break;
        case 2: _t->on_clearRecBtn_clicked(); break;
        case 3: _t->on_sendBtn_clicked(); break;
        case 4: _t->on_clearSendAreaBtn_clicked(); break;
        case 5: _t->on_saveFileCheckBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_timingSendCheckBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_updataBtn_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject serial_port::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_serial_port.data,
    qt_meta_data_serial_port,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *serial_port::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *serial_port::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_serial_port.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int serial_port::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
