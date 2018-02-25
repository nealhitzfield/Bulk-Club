/****************************************************************************
** Meta object code from reading C++ file 'confirmremoval.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../BulkClub/confirmremoval.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'confirmremoval.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ConfirmRemoval_t {
    QByteArrayData data[8];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConfirmRemoval_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConfirmRemoval_t qt_meta_stringdata_ConfirmRemoval = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ConfirmRemoval"
QT_MOC_LITERAL(1, 15, 16), // "removalConfirmed"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 13), // "setMemberView"
QT_MOC_LITERAL(4, 47, 12), // "MemberModel*"
QT_MOC_LITERAL(5, 60, 5), // "model"
QT_MOC_LITERAL(6, 66, 24), // "on_confirmButton_clicked"
QT_MOC_LITERAL(7, 91, 23) // "on_cancelButton_clicked"

    },
    "ConfirmRemoval\0removalConfirmed\0\0"
    "setMemberView\0MemberModel*\0model\0"
    "on_confirmButton_clicked\0"
    "on_cancelButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConfirmRemoval[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   35,    2, 0x08 /* Private */,
       6,    0,   38,    2, 0x08 /* Private */,
       7,    0,   39,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ConfirmRemoval::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConfirmRemoval *_t = static_cast<ConfirmRemoval *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->removalConfirmed(); break;
        case 1: _t->setMemberView((*reinterpret_cast< MemberModel*(*)>(_a[1]))); break;
        case 2: _t->on_confirmButton_clicked(); break;
        case 3: _t->on_cancelButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ConfirmRemoval::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConfirmRemoval::removalConfirmed)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ConfirmRemoval::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ConfirmRemoval.data,
      qt_meta_data_ConfirmRemoval,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ConfirmRemoval::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConfirmRemoval::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ConfirmRemoval.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ConfirmRemoval::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ConfirmRemoval::removalConfirmed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
