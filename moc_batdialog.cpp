/****************************************************************************
** Meta object code from reading C++ file 'batdialog.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "headers/batdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'batdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BatDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      24,   10,   10,   10, 0x0a,
      51,   10,   10,   10, 0x0a,
      77,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_BatDialog[] = {
    "BatDialog\0\0saveNewBat()\0"
    "saveEditedBat(QModelIndex)\0"
    "saveEditedBatOnBtnClick()\0"
    "onItemChanged(QModelIndex&)\0"
};

void BatDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BatDialog *_t = static_cast<BatDialog *>(_o);
        switch (_id) {
        case 0: _t->saveNewBat(); break;
        case 1: _t->saveEditedBat((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->saveEditedBatOnBtnClick(); break;
        case 3: _t->onItemChanged((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BatDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BatDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BatDialog,
      qt_meta_data_BatDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BatDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BatDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BatDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BatDialog))
        return static_cast<void*>(const_cast< BatDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int BatDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
