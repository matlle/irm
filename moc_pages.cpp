/****************************************************************************
** Meta object code from reading C++ file 'pages.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "headers/pages.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pages.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ResidentPage[] = {

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
      14,   13,   13,   13, 0x0a,
      42,   36,   13,   13, 0x0a,
      79,   13,   13,   13, 0x0a,
     110,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ResidentPage[] = {
    "ResidentPage\0\0showEdit(QModelIndex)\0"
    "event\0contextMenuEvent(QContextMenuEvent*)\0"
    "showResidentInfos(QModelIndex)\0"
    "removeResident()\0"
};

void ResidentPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ResidentPage *_t = static_cast<ResidentPage *>(_o);
        switch (_id) {
        case 0: _t->showEdit((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->contextMenuEvent((*reinterpret_cast< QContextMenuEvent*(*)>(_a[1]))); break;
        case 2: _t->showResidentInfos((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->removeResident(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ResidentPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ResidentPage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ResidentPage,
      qt_meta_data_ResidentPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ResidentPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ResidentPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ResidentPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ResidentPage))
        return static_cast<void*>(const_cast< ResidentPage*>(this));
    return QWidget::qt_metacast(_clname);
}

int ResidentPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
