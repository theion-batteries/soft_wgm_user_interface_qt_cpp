/****************************************************************************
** Meta object code from reading C++ file 'sinkingController.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../../src/businesslogic/sinkingController.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sinkingController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_sinkingController_t {
    uint offsetsAndSizes[18];
    char stringdata0[18];
    char stringdata1[8];
    char stringdata2[1];
    char stringdata3[10];
    char stringdata4[34];
    char stringdata5[31];
    char stringdata6[32];
    char stringdata7[30];
    char stringdata8[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_sinkingController_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_sinkingController_t qt_meta_stringdata_sinkingController = {
    {
        QT_MOC_LITERAL(0, 17),  // "sinkingController"
        QT_MOC_LITERAL(18, 7),  // "pressed"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 9),  // "triggered"
        QT_MOC_LITERAL(37, 33),  // "on_connect_keyence_sensor_cli..."
        QT_MOC_LITERAL(71, 30),  // "on_run_sinking_process_clicked"
        QT_MOC_LITERAL(102, 31),  // "on_stop_sinking_process_clicked"
        QT_MOC_LITERAL(134, 29),  // "on_actionwhs_config_triggered"
        QT_MOC_LITERAL(164, 16)   // "get_delta_status"
    },
    "sinkingController",
    "pressed",
    "",
    "triggered",
    "on_connect_keyence_sensor_clicked",
    "on_run_sinking_process_clicked",
    "on_stop_sinking_process_clicked",
    "on_actionwhs_config_triggered",
    "get_delta_status"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_sinkingController[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x06,    1 /* Public */,
       3,    0,   57,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   58,    2, 0x0a,    3 /* Public */,
       5,    0,   59,    2, 0x0a,    4 /* Public */,
       6,    0,   60,    2, 0x0a,    5 /* Public */,
       7,    0,   61,    2, 0x0a,    6 /* Public */,
       8,    0,   62,    2, 0x0a,    7 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString,

       0        // eod
};

Q_CONSTINIT const QMetaObject sinkingController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_sinkingController.offsetsAndSizes,
    qt_meta_data_sinkingController,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_sinkingController_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<sinkingController, std::true_type>,
        // method 'pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_connect_keyence_sensor_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_run_sinking_process_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_stop_sinking_process_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionwhs_config_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'get_delta_status'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void sinkingController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<sinkingController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->pressed(); break;
        case 1: _t->triggered(); break;
        case 2: _t->on_connect_keyence_sensor_clicked(); break;
        case 3: _t->on_run_sinking_process_clicked(); break;
        case 4: _t->on_stop_sinking_process_clicked(); break;
        case 5: _t->on_actionwhs_config_triggered(); break;
        case 6: { QString _r = _t->get_delta_status();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (sinkingController::*)();
            if (_t _q_method = &sinkingController::pressed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (sinkingController::*)();
            if (_t _q_method = &sinkingController::triggered; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *sinkingController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *sinkingController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_sinkingController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int sinkingController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void sinkingController::pressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void sinkingController::triggered()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
