/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created: Wed Nov 27 20:54:41 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../A8/widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Widget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,
      30,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      53,    7,    7,    7, 0x0a,
      66,    7,    7,    7, 0x0a,
      81,    7,    7,    7, 0x0a,
      93,    7,    7,    7, 0x0a,
     104,    7,    7,    7, 0x0a,
     114,    7,    7,    7, 0x0a,
     132,    7,    7,    7, 0x08,
     153,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Widget[] = {
    "Widget\0\0switchToWorkWSignal()\0"
    "switchToSecretSignal()\0updatetime()\0"
    "magWorkWShow()\0workWShow()\0toSecret()\0"
    "manShow()\0SendModDataSlot()\0"
    "on_visiBtn_clicked()\0on_manaBtn_clicked()\0"
};

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget,
      qt_meta_data_Widget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Widget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Widget))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: switchToWorkWSignal(); break;
        case 1: switchToSecretSignal(); break;
        case 2: updatetime(); break;
        case 3: magWorkWShow(); break;
        case 4: workWShow(); break;
        case 5: toSecret(); break;
        case 6: manShow(); break;
        case 7: SendModDataSlot(); break;
        case 8: on_visiBtn_clicked(); break;
        case 9: on_manaBtn_clicked(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Widget::switchToWorkWSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Widget::switchToSecretSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
