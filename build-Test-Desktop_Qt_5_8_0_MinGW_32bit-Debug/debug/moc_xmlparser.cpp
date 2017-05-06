/****************************************************************************
** Meta object code from reading C++ file 'xmlparser.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Test/xmlparser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'xmlparser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_XMLParser_t {
    QByteArrayData data[6];
    char stringdata0[54];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_XMLParser_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_XMLParser_t qt_meta_stringdata_XMLParser = {
    {
QT_MOC_LITERAL(0, 0, 9), // "XMLParser"
QT_MOC_LITERAL(1, 10, 16), // "NewObjectDataXml"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 6), // "Object"
QT_MOC_LITERAL(4, 35, 6), // "NewObj"
QT_MOC_LITERAL(5, 42, 11) // "InfoHandler"

    },
    "XMLParser\0NewObjectDataXml\0\0Object\0"
    "NewObj\0InfoHandler"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XMLParser[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   27,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void XMLParser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        XMLParser *_t = static_cast<XMLParser *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->NewObjectDataXml((*reinterpret_cast< const Object(*)>(_a[1]))); break;
        case 1: _t->InfoHandler(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (XMLParser::*_t)(const Object );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XMLParser::NewObjectDataXml)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject XMLParser::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_XMLParser.data,
      qt_meta_data_XMLParser,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *XMLParser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XMLParser::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_XMLParser.stringdata0))
        return static_cast<void*>(const_cast< XMLParser*>(this));
    return QObject::qt_metacast(_clname);
}

int XMLParser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void XMLParser::NewObjectDataXml(const Object _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
