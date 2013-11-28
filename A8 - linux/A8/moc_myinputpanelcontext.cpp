/****************************************************************************
** Meta object code from reading C++ file 'myinputpanelcontext.h'
**
** Created: Thu Nov 28 09:59:17 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "myinputpanelcontext.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myinputpanelcontext.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyInputPanelContext[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      31,   21,   20,   20, 0x08,
      52,   20,   20,   20, 0x08,
      68,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MyInputPanelContext[] = {
    "MyInputPanelContext\0\0character\0"
    "sendCharacter(QChar)\0BackSpaceSlot()\0"
    "EnterSlot()\0"
};

const QMetaObject MyInputPanelContext::staticMetaObject = {
    { &QInputContext::staticMetaObject, qt_meta_stringdata_MyInputPanelContext,
      qt_meta_data_MyInputPanelContext, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyInputPanelContext::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyInputPanelContext::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyInputPanelContext::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyInputPanelContext))
        return static_cast<void*>(const_cast< MyInputPanelContext*>(this));
    return QInputContext::qt_metacast(_clname);
}

int MyInputPanelContext::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QInputContext::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sendCharacter((*reinterpret_cast< QChar(*)>(_a[1]))); break;
        case 1: BackSpaceSlot(); break;
        case 2: EnterSlot(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
