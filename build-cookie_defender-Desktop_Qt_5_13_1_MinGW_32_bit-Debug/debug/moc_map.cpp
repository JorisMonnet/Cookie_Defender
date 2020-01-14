/****************************************************************************
** Meta object code from reading C++ file 'map.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../cookie_defender/map.h"
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
    QByteArrayData data[21];
    char stringdata0[228];
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
QT_MOC_LITERAL(4, 27, 10), // "moneySound"
QT_MOC_LITERAL(5, 38, 12), // "gameWinSound"
QT_MOC_LITERAL(6, 51, 12), // "enemyTPSound"
QT_MOC_LITERAL(7, 64, 8), // "gameOver"
QT_MOC_LITERAL(8, 73, 11), // "waveMonster"
QT_MOC_LITERAL(9, 85, 7), // "gameWin"
QT_MOC_LITERAL(10, 93, 15), // "mousePressEvent"
QT_MOC_LITERAL(11, 109, 12), // "QMouseEvent*"
QT_MOC_LITERAL(12, 122, 5), // "event"
QT_MOC_LITERAL(13, 128, 14), // "mouseMoveEvent"
QT_MOC_LITERAL(14, 143, 13), // "keyPressEvent"
QT_MOC_LITERAL(15, 157, 10), // "QKeyEvent*"
QT_MOC_LITERAL(16, 168, 11), // "moveMonster"
QT_MOC_LITERAL(17, 180, 9), // "pauseMenu"
QT_MOC_LITERAL(18, 190, 11), // "towerDetect"
QT_MOC_LITERAL(19, 202, 12), // "aliveMonster"
QT_MOC_LITERAL(20, 215, 12) // "spawnMonster"

    },
    "Map\0pauseFunction\0\0gameEnd\0moneySound\0"
    "gameWinSound\0enemyTPSound\0gameOver\0"
    "waveMonster\0gameWin\0mousePressEvent\0"
    "QMouseEvent*\0event\0mouseMoveEvent\0"
    "keyPressEvent\0QKeyEvent*\0moveMonster\0"
    "pauseMenu\0towerDetect\0aliveMonster\0"
    "spawnMonster"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Map[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    0,   95,    2, 0x06 /* Public */,
       4,    0,   96,    2, 0x06 /* Public */,
       5,    0,   97,    2, 0x06 /* Public */,
       6,    0,   98,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   99,    2, 0x0a /* Public */,
       8,    0,  100,    2, 0x0a /* Public */,
       9,    0,  101,    2, 0x0a /* Public */,
      10,    1,  102,    2, 0x08 /* Private */,
      13,    1,  105,    2, 0x08 /* Private */,
      14,    1,  108,    2, 0x08 /* Private */,
      16,    0,  111,    2, 0x08 /* Private */,
      17,    0,  112,    2, 0x08 /* Private */,
      18,    0,  113,    2, 0x08 /* Private */,
      19,    0,  114,    2, 0x08 /* Private */,
      20,    0,  115,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 15,   12,
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
        case 2: _t->moneySound(); break;
        case 3: _t->gameWinSound(); break;
        case 4: _t->enemyTPSound(); break;
        case 5: _t->gameOver(); break;
        case 6: _t->waveMonster(); break;
        case 7: _t->gameWin(); break;
        case 8: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 9: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 10: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 11: _t->moveMonster(); break;
        case 12: _t->pauseMenu(); break;
        case 13: _t->towerDetect(); break;
        case 14: _t->aliveMonster(); break;
        case 15: _t->spawnMonster(); break;
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
        {
            using _t = void (Map::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Map::moneySound)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Map::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Map::gameWinSound)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Map::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Map::enemyTPSound)) {
                *result = 4;
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
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
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

// SIGNAL 2
void Map::moneySound()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Map::gameWinSound()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Map::enemyTPSound()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
