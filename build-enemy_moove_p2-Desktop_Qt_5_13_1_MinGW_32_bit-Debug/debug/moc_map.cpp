/****************************************************************************
** Meta object code from reading C++ file 'map.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../enemy_moove_p2/map.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'map.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Map_t {
    QByteArrayData data[15];
    char stringdata0[159];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Map_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Map_t qt_meta_stringdata_Map = {
    {
QT_MOC_LITERAL(0, 0, 3), // "Map"
QT_MOC_LITERAL(1, 4, 13), // "pauseFunction"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 7), // "gameEnd"
QT_MOC_LITERAL(4, 27, 15), // "mousePressEvent"
QT_MOC_LITERAL(5, 43, 12), // "QMouseEvent*"
QT_MOC_LITERAL(6, 56, 5), // "event"
QT_MOC_LITERAL(7, 62, 14), // "mouseMoveEvent"
QT_MOC_LITERAL(8, 77, 13), // "keyPressEvent"
QT_MOC_LITERAL(9, 91, 10), // "QKeyEvent*"
QT_MOC_LITERAL(10, 102, 11), // "moveMonster"
QT_MOC_LITERAL(11, 114, 12), // "spawnMonster"
QT_MOC_LITERAL(12, 127, 9), // "pauseMenu"
QT_MOC_LITERAL(13, 137, 9), // "shotTower"
QT_MOC_LITERAL(14, 147, 11) // "waveMonster"

    },
    "Map\0pauseFunction\0\0gameEnd\0mousePressEvent\0"
    "QMouseEvent*\0event\0mouseMoveEvent\0"
    "keyPressEvent\0QKeyEvent*\0moveMonster\0"
    "spawnMonster\0pauseMenu\0shotTower\0"
    "waveMonster"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Map[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   66,    2, 0x08 /* Private */,
       7,    1,   69,    2, 0x08 /* Private */,
       8,    1,   72,    2, 0x08 /* Private */,
      10,    0,   75,    2, 0x08 /* Private */,
      11,    0,   76,    2, 0x08 /* Private */,
      12,    0,   77,    2, 0x08 /* Private */,
      13,    0,   78,    2, 0x08 /* Private */,
      14,    0,   79,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 9,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Map::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Map *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pauseFunction(); break;
        case 1: _t->gameEnd(); break;
        case 2: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 4: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 5: _t->moveMonster(); break;
        case 6: _t->spawnMonster(); break;
        case 7: _t->pauseMenu(); break;
        case 8: _t->shotTower(); break;
        case 9: _t->waveMonster(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Map::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Map::pauseFunction)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Map::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Map::gameEnd)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Map::staticMetaObject = { {
    &QGraphicsView::staticMetaObject,
    qt_meta_stringdata_Map.data,
    qt_meta_data_Map,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Map::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Map::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Map.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int Map::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Map::pauseFunction()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Map::gameEnd()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
