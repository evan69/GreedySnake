/****************************************************************************
** Meta object code from reading C++ file 'snake.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../snake/snake.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'snake.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_snake_t {
    QByteArrayData data[7];
    char stringdata0[48];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_snake_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_snake_t qt_meta_stringdata_snake = {
    {
QT_MOC_LITERAL(0, 0, 5), // "snake"
QT_MOC_LITERAL(1, 6, 11), // "deathSignal"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 11), // "updateSnake"
QT_MOC_LITERAL(4, 31, 5), // "start"
QT_MOC_LITERAL(5, 37, 4), // "move"
QT_MOC_LITERAL(6, 42, 5) // "pause"

    },
    "snake\0deathSignal\0\0updateSnake\0start\0"
    "move\0pause"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_snake[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   41,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void snake::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        snake *_t = static_cast<snake *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->deathSignal(); break;
        case 1: _t->updateSnake(); break;
        case 2: _t->start(); break;
        case 3: _t->move(); break;
        case 4: _t->pause(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (snake::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&snake::deathSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (snake::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&snake::updateSnake)) {
                *result = 1;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject snake::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_snake.data,
      qt_meta_data_snake,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *snake::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *snake::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_snake.stringdata0))
        return static_cast<void*>(const_cast< snake*>(this));
    return QObject::qt_metacast(_clname);
}

int snake::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void snake::deathSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void snake::updateSnake()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
