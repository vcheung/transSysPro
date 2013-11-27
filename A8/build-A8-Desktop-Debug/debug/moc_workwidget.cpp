/****************************************************************************
** Meta object code from reading C++ file 'workwidget.h'
**
** Created: Wed Nov 27 09:45:50 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../A8/workwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'workwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_workwidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      32,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      51,   11,   11,   11, 0x0a,
      64,   11,   11,   11, 0x0a,
      81,   11,   11,   11, 0x08,
     105,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_workwidget[] = {
    "workwidget\0\0switchToManSignal()\0"
    "updateShowSignal()\0updatetime()\0"
    "updateShowSlot()\0on_returnWork_clicked()\0"
    "on_quit_clicked()\0"
};

const QMetaObject workwidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_workwidget,
      qt_meta_data_workwidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &workwidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *workwidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *workwidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_workwidget))
        return static_cast<void*>(const_cast< workwidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int workwidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: switchToManSignal(); break;
        case 1: updateShowSignal(); break;
        case 2: updatetime(); break;
        case 3: updateShowSlot(); break;
        case 4: on_returnWork_clicked(); break;
        case 5: on_quit_clicked(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void workwidget::switchToManSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void workwidget::updateShowSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
