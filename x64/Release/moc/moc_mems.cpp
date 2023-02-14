/****************************************************************************
** Meta object code from reading C++ file 'mems.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../mems.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mems.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mems_t {
    QByteArrayData data[9];
    char stringdata0[181];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mems_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mems_t qt_meta_stringdata_mems = {
    {
QT_MOC_LITERAL(0, 0, 4), // "mems"
QT_MOC_LITERAL(1, 5, 30), // "on_btnSplinePointColor_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 28), // "on_chkDataPoint_stateChanged"
QT_MOC_LITERAL(4, 66, 4), // "arg1"
QT_MOC_LITERAL(5, 71, 40), // "on_chkDataPointLabelVisible_s..."
QT_MOC_LITERAL(6, 112, 23), // "on_mems_refresh_clicked"
QT_MOC_LITERAL(7, 136, 24), // "on_mems_showdata_clicked"
QT_MOC_LITERAL(8, 161, 19) // "on_mems_serial_test"

    },
    "mems\0on_btnSplinePointColor_clicked\0"
    "\0on_chkDataPoint_stateChanged\0arg1\0"
    "on_chkDataPointLabelVisible_stateChanged\0"
    "on_mems_refresh_clicked\0"
    "on_mems_showdata_clicked\0on_mems_serial_test"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mems[] = {

 // content:
       8,       // revision
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
       6,    0,   51,    2, 0x08 /* Private */,
       7,    0,   52,    2, 0x08 /* Private */,
       8,    0,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void mems::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<mems *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnSplinePointColor_clicked(); break;
        case 1: _t->on_chkDataPoint_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_chkDataPointLabelVisible_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_mems_refresh_clicked(); break;
        case 4: _t->on_mems_showdata_clicked(); break;
        case 5: _t->on_mems_serial_test(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject mems::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_mems.data,
    qt_meta_data_mems,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *mems::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mems::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mems.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int mems::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
