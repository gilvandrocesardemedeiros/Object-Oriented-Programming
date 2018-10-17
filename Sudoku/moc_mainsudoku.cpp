/****************************************************************************
** Meta object code from reading C++ file 'mainsudoku.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainsudoku.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainsudoku.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainSudoku_t {
    QByteArrayData data[14];
    char stringdata0[279];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainSudoku_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainSudoku_t qt_meta_stringdata_MainSudoku = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainSudoku"
QT_MOC_LITERAL(1, 11, 24), // "on_tab_atual_cellClicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 3), // "row"
QT_MOC_LITERAL(4, 41, 6), // "column"
QT_MOC_LITERAL(5, 48, 29), // "on_spinbox_valor_valueChanged"
QT_MOC_LITERAL(6, 78, 4), // "arg1"
QT_MOC_LITERAL(7, 83, 23), // "on_button_jogar_clicked"
QT_MOC_LITERAL(8, 107, 28), // "on_actionReiniciar_triggered"
QT_MOC_LITERAL(9, 136, 23), // "on_actionNovo_triggered"
QT_MOC_LITERAL(10, 160, 38), // "on_actionPreencher_Imediatas_..."
QT_MOC_LITERAL(11, 199, 27), // "on_actionResolver_triggered"
QT_MOC_LITERAL(12, 227, 23), // "on_actionSair_triggered"
QT_MOC_LITERAL(13, 251, 27) // "on_button_continuar_clicked"

    },
    "MainSudoku\0on_tab_atual_cellClicked\0"
    "\0row\0column\0on_spinbox_valor_valueChanged\0"
    "arg1\0on_button_jogar_clicked\0"
    "on_actionReiniciar_triggered\0"
    "on_actionNovo_triggered\0"
    "on_actionPreencher_Imediatas_triggered\0"
    "on_actionResolver_triggered\0"
    "on_actionSair_triggered\0"
    "on_button_continuar_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainSudoku[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x08 /* Private */,
       5,    1,   64,    2, 0x08 /* Private */,
       7,    0,   67,    2, 0x08 /* Private */,
       8,    0,   68,    2, 0x08 /* Private */,
       9,    0,   69,    2, 0x08 /* Private */,
      10,    0,   70,    2, 0x08 /* Private */,
      11,    0,   71,    2, 0x08 /* Private */,
      12,    0,   72,    2, 0x08 /* Private */,
      13,    0,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainSudoku::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainSudoku *_t = static_cast<MainSudoku *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_tab_atual_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->on_spinbox_valor_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_button_jogar_clicked(); break;
        case 3: _t->on_actionReiniciar_triggered(); break;
        case 4: _t->on_actionNovo_triggered(); break;
        case 5: _t->on_actionPreencher_Imediatas_triggered(); break;
        case 6: _t->on_actionResolver_triggered(); break;
        case 7: _t->on_actionSair_triggered(); break;
        case 8: _t->on_button_continuar_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainSudoku::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainSudoku.data,
      qt_meta_data_MainSudoku,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainSudoku::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainSudoku::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainSudoku.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainSudoku::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
