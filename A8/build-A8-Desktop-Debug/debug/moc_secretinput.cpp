/****************************************************************************
** Meta object code from reading C++ file 'secretinput.h'
**
** Created: Tue Nov 26 16:04:51 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../A8/secretinput.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'secretinput.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_secretInput[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      40,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      70,   12,   12,   12, 0x0a,
      91,   12,   12,   12, 0x0a,
     115,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_secretInput[] = {
    "secretInput\0\0switchToWorkwidgetSignal()\0"
    "switchToMagWorkwidgetSignal()\0"
    "switchToWorkwidget()\0switchToMagWorkwidget()\0"
    "invisiblePrompterSlot()\0"
};

const QMetaObject secretInput::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_secretInput,
      qt_meta_data_secretInput, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &secretInput::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *secretInput::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *secretInput::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_secretInput))
        return static_cast<void*>(const_cast< secretInput*>(this));
    return QWidget::qt_metacast(_clname);
}

int secretInput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: switchToWorkwidgetSignal(); break;
        case 1: switchToMagWorkwidgetSignal(); break;
        case 2: switchToWorkwidget(); break;
        case 3: switchToMagWorkwidget(); break;
        case 4: invisiblePrompterSlot(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void secretInput::switchToWorkwidgetSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void secretInput::switchToMagWorkwidgetSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
