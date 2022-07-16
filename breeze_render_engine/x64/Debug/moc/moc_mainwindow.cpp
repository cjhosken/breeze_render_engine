/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/interface/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[44];
    char stringdata0[430];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 20), // "onViewportFOVChanged"
QT_MOC_LITERAL(32, 0), // ""
QT_MOC_LITERAL(33, 5), // "value"
QT_MOC_LITERAL(39, 25), // "onToggleSelectButtonClick"
QT_MOC_LITERAL(65, 20), // "onAddCubeButtonClick"
QT_MOC_LITERAL(86, 21), // "onAddPlaneButtonClick"
QT_MOC_LITERAL(108, 22), // "onAddSphereButtonClick"
QT_MOC_LITERAL(131, 22), // "onAddCircleButtonClick"
QT_MOC_LITERAL(154, 24), // "onAddTriangleButtonClick"
QT_MOC_LITERAL(179, 22), // "onAddMonkeyButtonClick"
QT_MOC_LITERAL(202, 22), // "onAddTeapotButtonClick"
QT_MOC_LITERAL(225, 19), // "onAddOBJButtonClick"
QT_MOC_LITERAL(245, 21), // "onAddLightButtonClick"
QT_MOC_LITERAL(267, 22), // "onSolidViewButtonClick"
QT_MOC_LITERAL(290, 21), // "onWireViewButtonClick"
QT_MOC_LITERAL(312, 22), // "onLightViewButtonClick"
QT_MOC_LITERAL(335, 17), // "onExitButtonClick"
QT_MOC_LITERAL(353, 16), // "onBugButtonClick"
QT_MOC_LITERAL(370, 17), // "onCodeButtonClick"
QT_MOC_LITERAL(388, 26), // "onDocumentationButtonClick"
QT_MOC_LITERAL(415, 14) // "onRenderButton"

    },
    "MainWindow\0onViewportFOVChanged\0\0value\0"
    "onToggleSelectButtonClick\0"
    "onAddCubeButtonClick\0onAddPlaneButtonClick\0"
    "onAddSphereButtonClick\0onAddCircleButtonClick\0"
    "onAddTriangleButtonClick\0"
    "onAddMonkeyButtonClick\0onAddTeapotButtonClick\0"
    "onAddOBJButtonClick\0onAddLightButtonClick\0"
    "onSolidViewButtonClick\0onWireViewButtonClick\0"
    "onLightViewButtonClick\0onExitButtonClick\0"
    "onBugButtonClick\0onCodeButtonClick\0"
    "onDocumentationButtonClick\0onRenderButton"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  128,    2, 0x08,    1 /* Private */,
       4,    0,  131,    2, 0x08,    3 /* Private */,
       5,    0,  132,    2, 0x08,    4 /* Private */,
       6,    0,  133,    2, 0x08,    5 /* Private */,
       7,    0,  134,    2, 0x08,    6 /* Private */,
       8,    0,  135,    2, 0x08,    7 /* Private */,
       9,    0,  136,    2, 0x08,    8 /* Private */,
      10,    0,  137,    2, 0x08,    9 /* Private */,
      11,    0,  138,    2, 0x08,   10 /* Private */,
      12,    0,  139,    2, 0x08,   11 /* Private */,
      13,    0,  140,    2, 0x08,   12 /* Private */,
      14,    0,  141,    2, 0x08,   13 /* Private */,
      15,    0,  142,    2, 0x08,   14 /* Private */,
      16,    0,  143,    2, 0x08,   15 /* Private */,
      17,    0,  144,    2, 0x08,   16 /* Private */,
      18,    0,  145,    2, 0x08,   17 /* Private */,
      19,    0,  146,    2, 0x08,   18 /* Private */,
      20,    0,  147,    2, 0x08,   19 /* Private */,
      21,    0,  148,    2, 0x08,   20 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onViewportFOVChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->onToggleSelectButtonClick(); break;
        case 2: _t->onAddCubeButtonClick(); break;
        case 3: _t->onAddPlaneButtonClick(); break;
        case 4: _t->onAddSphereButtonClick(); break;
        case 5: _t->onAddCircleButtonClick(); break;
        case 6: _t->onAddTriangleButtonClick(); break;
        case 7: _t->onAddMonkeyButtonClick(); break;
        case 8: _t->onAddTeapotButtonClick(); break;
        case 9: _t->onAddOBJButtonClick(); break;
        case 10: _t->onAddLightButtonClick(); break;
        case 11: _t->onSolidViewButtonClick(); break;
        case 12: _t->onWireViewButtonClick(); break;
        case 13: _t->onLightViewButtonClick(); break;
        case 14: _t->onExitButtonClick(); break;
        case 15: _t->onBugButtonClick(); break;
        case 16: _t->onCodeButtonClick(); break;
        case 17: _t->onDocumentationButtonClick(); break;
        case 18: _t->onRenderButton(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 19;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
