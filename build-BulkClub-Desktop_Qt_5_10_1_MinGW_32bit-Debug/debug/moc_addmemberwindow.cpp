/****************************************************************************
** Meta object code from reading C++ file 'addmemberwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../BulkClub/addmemberwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addmemberwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AddMemberWindow_t {
    QByteArrayData data[10];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddMemberWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddMemberWindow_t qt_meta_stringdata_AddMemberWindow = {
    {
QT_MOC_LITERAL(0, 0, 15), // "AddMemberWindow"
QT_MOC_LITERAL(1, 16, 12), // "windowClosed"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 6), // "sendID"
QT_MOC_LITERAL(4, 37, 2), // "id"
QT_MOC_LITERAL(5, 40, 20), // "on_addButton_clicked"
QT_MOC_LITERAL(6, 61, 10), // "checkInput"
QT_MOC_LITERAL(7, 72, 4), // "text"
QT_MOC_LITERAL(8, 77, 19), // "on_noButton_clicked"
QT_MOC_LITERAL(9, 97, 20) // "on_yesButton_clicked"

    },
    "AddMemberWindow\0windowClosed\0\0sendID\0"
    "id\0on_addButton_clicked\0checkInput\0"
    "text\0on_noButton_clicked\0on_yesButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddMemberWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   48,    2, 0x08 /* Private */,
       6,    1,   49,    2, 0x08 /* Private */,
       8,    0,   52,    2, 0x08 /* Private */,
       9,    0,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AddMemberWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AddMemberWindow *_t = static_cast<AddMemberWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->windowClosed(); break;
        case 1: _t->sendID((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_addButton_clicked(); break;
        case 3: _t->checkInput((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_noButton_clicked(); break;
        case 5: _t->on_yesButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (AddMemberWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AddMemberWindow::windowClosed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AddMemberWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AddMemberWindow::sendID)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AddMemberWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AddMemberWindow.data,
      qt_meta_data_AddMemberWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AddMemberWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddMemberWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AddMemberWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int AddMemberWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void AddMemberWindow::windowClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AddMemberWindow::sendID(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
