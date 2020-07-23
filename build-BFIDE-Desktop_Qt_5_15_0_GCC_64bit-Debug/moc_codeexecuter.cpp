/****************************************************************************
** Meta object code from reading C++ file 'codeexecuter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../BFIDE/codeexecuter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'codeexecuter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CodeExecuter_t {
    QByteArrayData data[8];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CodeExecuter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CodeExecuter_t qt_meta_stringdata_CodeExecuter = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CodeExecuter"
QT_MOC_LITERAL(1, 13, 13), // "codeConverted"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 12), // "codeExecuted"
QT_MOC_LITERAL(4, 41, 13), // "errorsChecked"
QT_MOC_LITERAL(5, 55, 10), // "convertToC"
QT_MOC_LITERAL(6, 66, 7), // "runCode"
QT_MOC_LITERAL(7, 74, 11) // "checkErrors"

    },
    "CodeExecuter\0codeConverted\0\0codeExecuted\0"
    "errorsChecked\0convertToC\0runCode\0"
    "checkErrors"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CodeExecuter[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CodeExecuter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CodeExecuter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->codeConverted(); break;
        case 1: _t->codeExecuted(); break;
        case 2: _t->errorsChecked(); break;
        case 3: _t->convertToC(); break;
        case 4: _t->runCode(); break;
        case 5: _t->checkErrors(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CodeExecuter::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CodeExecuter::codeConverted)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CodeExecuter::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CodeExecuter::codeExecuted)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CodeExecuter::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CodeExecuter::errorsChecked)) {
                *result = 2;
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

// SIGNAL 0
void CodeExecuter::codeConverted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CodeExecuter::codeExecuted()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void CodeExecuter::errorsChecked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
