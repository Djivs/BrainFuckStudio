/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../BFIDE/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CodeExecuter_t {
    QByteArrayData data[4];
    char stringdata0[35];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CodeExecuter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CodeExecuter_t qt_meta_stringdata_CodeExecuter = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CodeExecuter"
QT_MOC_LITERAL(1, 13, 12), // "codeExecuted"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 7) // "runCode"

    },
    "CodeExecuter\0codeExecuted\0\0runCode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CodeExecuter[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   25,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void CodeExecuter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CodeExecuter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->codeExecuted(); break;
        case 1: _t->runCode(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CodeExecuter::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CodeExecuter::codeExecuted)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CodeExecuter::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CodeExecuter.data,
    qt_meta_data_CodeExecuter,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CodeExecuter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CodeExecuter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CodeExecuter.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CodeExecuter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void CodeExecuter::codeExecuted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[391];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 14), // "startOperation"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 9), // "updateOut"
QT_MOC_LITERAL(4, 37, 18), // "end_code_execution"
QT_MOC_LITERAL(5, 56, 18), // "on_bytes16_clicked"
QT_MOC_LITERAL(6, 75, 18), // "on_bytes32_clicked"
QT_MOC_LITERAL(7, 94, 17), // "on_bytes8_clicked"
QT_MOC_LITERAL(8, 112, 25), // "on_viewMemoryLine_clicked"
QT_MOC_LITERAL(9, 138, 19), // "on_prog_textChanged"
QT_MOC_LITERAL(10, 158, 20), // "on_sep_space_clicked"
QT_MOC_LITERAL(11, 179, 17), // "on_sep_nl_clicked"
QT_MOC_LITERAL(12, 197, 21), // "on_darkScheme_clicked"
QT_MOC_LITERAL(13, 219, 22), // "on_lightScheme_clicked"
QT_MOC_LITERAL(14, 242, 17), // "on_sep_no_clicked"
QT_MOC_LITERAL(15, 260, 29), // "on_actionStart_Code_triggered"
QT_MOC_LITERAL(16, 290, 27), // "on_actionEnd_Code_triggered"
QT_MOC_LITERAL(17, 318, 24), // "on_actionClear_triggered"
QT_MOC_LITERAL(18, 343, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(19, 367, 23) // "on_actionLoad_triggered"

    },
    "MainWindow\0startOperation\0\0updateOut\0"
    "end_code_execution\0on_bytes16_clicked\0"
    "on_bytes32_clicked\0on_bytes8_clicked\0"
    "on_viewMemoryLine_clicked\0on_prog_textChanged\0"
    "on_sep_space_clicked\0on_sep_nl_clicked\0"
    "on_darkScheme_clicked\0on_lightScheme_clicked\0"
    "on_sep_no_clicked\0on_actionStart_Code_triggered\0"
    "on_actionEnd_Code_triggered\0"
    "on_actionClear_triggered\0"
    "on_actionSave_triggered\0on_actionLoad_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,  105,    2, 0x08 /* Private */,
       4,    0,  106,    2, 0x08 /* Private */,
       5,    0,  107,    2, 0x08 /* Private */,
       6,    0,  108,    2, 0x08 /* Private */,
       7,    0,  109,    2, 0x08 /* Private */,
       8,    0,  110,    2, 0x08 /* Private */,
       9,    0,  111,    2, 0x08 /* Private */,
      10,    0,  112,    2, 0x08 /* Private */,
      11,    0,  113,    2, 0x08 /* Private */,
      12,    0,  114,    2, 0x08 /* Private */,
      13,    0,  115,    2, 0x08 /* Private */,
      14,    0,  116,    2, 0x08 /* Private */,
      15,    0,  117,    2, 0x08 /* Private */,
      16,    0,  118,    2, 0x08 /* Private */,
      17,    0,  119,    2, 0x08 /* Private */,
      18,    0,  120,    2, 0x08 /* Private */,
      19,    0,  121,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

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
        case 0: _t->startOperation(); break;
        case 1: _t->updateOut(); break;
        case 2: _t->end_code_execution(); break;
        case 3: _t->on_bytes16_clicked(); break;
        case 4: _t->on_bytes32_clicked(); break;
        case 5: _t->on_bytes8_clicked(); break;
        case 6: _t->on_viewMemoryLine_clicked(); break;
        case 7: _t->on_prog_textChanged(); break;
        case 8: _t->on_sep_space_clicked(); break;
        case 9: _t->on_sep_nl_clicked(); break;
        case 10: _t->on_darkScheme_clicked(); break;
        case 11: _t->on_lightScheme_clicked(); break;
        case 12: _t->on_sep_no_clicked(); break;
        case 13: _t->on_actionStart_Code_triggered(); break;
        case 14: _t->on_actionEnd_Code_triggered(); break;
        case 15: _t->on_actionClear_triggered(); break;
        case 16: _t->on_actionSave_triggered(); break;
        case 17: _t->on_actionLoad_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::startOperation)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
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
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::startOperation()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
