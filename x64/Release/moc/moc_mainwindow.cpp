/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[30];
    char stringdata0[437];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "on_mcu_accepted"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 15), // "on_adc_accepted"
QT_MOC_LITERAL(4, 44, 21), // "on_ip_config_accepted"
QT_MOC_LITERAL(5, 66, 23), // "on_serial_port_accepted"
QT_MOC_LITERAL(6, 90, 17), // "on_laser_accepted"
QT_MOC_LITERAL(7, 108, 20), // "on_receiver_accepted"
QT_MOC_LITERAL(8, 129, 16), // "on_mems_accepted"
QT_MOC_LITERAL(9, 146, 20), // "on_document_accepted"
QT_MOC_LITERAL(10, 167, 16), // "on_FPGA_accepted"
QT_MOC_LITERAL(11, 184, 18), // "onaction_Open_File"
QT_MOC_LITERAL(12, 203, 17), // "onaction_new_file"
QT_MOC_LITERAL(13, 221, 17), // "on_Index_accepted"
QT_MOC_LITERAL(14, 239, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(15, 263, 8), // "loadFile"
QT_MOC_LITERAL(16, 272, 12), // "filePathList"
QT_MOC_LITERAL(17, 285, 3), // "add"
QT_MOC_LITERAL(18, 289, 5), // "clear"
QT_MOC_LITERAL(19, 295, 11), // "pRecentOpen"
QT_MOC_LITERAL(20, 307, 21), // "slot_uploadBtnClicked"
QT_MOC_LITERAL(21, 329, 7), // "popMenu"
QT_MOC_LITERAL(22, 337, 8), // "hideItem"
QT_MOC_LITERAL(23, 346, 8), // "showItem"
QT_MOC_LITERAL(24, 355, 10), // "deleteItem"
QT_MOC_LITERAL(25, 366, 16), // "popMenuInConsole"
QT_MOC_LITERAL(26, 383, 12), // "clearConsole"
QT_MOC_LITERAL(27, 396, 13), // "enableConsole"
QT_MOC_LITERAL(28, 410, 14), // "disableConsole"
QT_MOC_LITERAL(29, 425, 11) // "timerUpdate"

    },
    "MainWindow\0on_mcu_accepted\0\0on_adc_accepted\0"
    "on_ip_config_accepted\0on_serial_port_accepted\0"
    "on_laser_accepted\0on_receiver_accepted\0"
    "on_mems_accepted\0on_document_accepted\0"
    "on_FPGA_accepted\0onaction_Open_File\0"
    "onaction_new_file\0on_Index_accepted\0"
    "on_pushButton_2_clicked\0loadFile\0"
    "filePathList\0add\0clear\0pRecentOpen\0"
    "slot_uploadBtnClicked\0popMenu\0hideItem\0"
    "showItem\0deleteItem\0popMenuInConsole\0"
    "clearConsole\0enableConsole\0disableConsole\0"
    "timerUpdate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  149,    2, 0x08 /* Private */,
       3,    0,  150,    2, 0x08 /* Private */,
       4,    0,  151,    2, 0x08 /* Private */,
       5,    0,  152,    2, 0x08 /* Private */,
       6,    0,  153,    2, 0x08 /* Private */,
       7,    0,  154,    2, 0x08 /* Private */,
       8,    0,  155,    2, 0x08 /* Private */,
       9,    0,  156,    2, 0x08 /* Private */,
      10,    0,  157,    2, 0x08 /* Private */,
      11,    0,  158,    2, 0x08 /* Private */,
      12,    0,  159,    2, 0x08 /* Private */,
      13,    0,  160,    2, 0x08 /* Private */,
      14,    0,  161,    2, 0x08 /* Private */,
      15,    1,  162,    2, 0x08 /* Private */,
      17,    0,  165,    2, 0x08 /* Private */,
      18,    0,  166,    2, 0x08 /* Private */,
      19,    0,  167,    2, 0x08 /* Private */,
      20,    0,  168,    2, 0x08 /* Private */,
      21,    1,  169,    2, 0x08 /* Private */,
      22,    0,  172,    2, 0x08 /* Private */,
      23,    0,  173,    2, 0x08 /* Private */,
      24,    0,  174,    2, 0x08 /* Private */,
      25,    1,  175,    2, 0x08 /* Private */,
      26,    0,  178,    2, 0x08 /* Private */,
      27,    0,  179,    2, 0x08 /* Private */,
      28,    0,  180,    2, 0x08 /* Private */,
      29,    0,  181,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_mcu_accepted(); break;
        case 1: _t->on_adc_accepted(); break;
        case 2: _t->on_ip_config_accepted(); break;
        case 3: _t->on_serial_port_accepted(); break;
        case 4: _t->on_laser_accepted(); break;
        case 5: _t->on_receiver_accepted(); break;
        case 6: _t->on_mems_accepted(); break;
        case 7: _t->on_document_accepted(); break;
        case 8: _t->on_FPGA_accepted(); break;
        case 9: _t->onaction_Open_File(); break;
        case 10: _t->onaction_new_file(); break;
        case 11: _t->on_Index_accepted(); break;
        case 12: _t->on_pushButton_2_clicked(); break;
        case 13: _t->loadFile((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 14: _t->add(); break;
        case 15: _t->clear(); break;
        case 16: _t->pRecentOpen(); break;
        case 17: _t->slot_uploadBtnClicked(); break;
        case 18: _t->popMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 19: _t->hideItem(); break;
        case 20: _t->showItem(); break;
        case 21: _t->deleteItem(); break;
        case 22: _t->popMenuInConsole((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 23: _t->clearConsole(); break;
        case 24: _t->enableConsole(); break;
        case 25: _t->disableConsole(); break;
        case 26: _t->timerUpdate(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 27)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 27;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
