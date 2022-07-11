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
    const uint offsetsAndSize[40];
    char stringdata0[403];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 25), // "onToggleSelectButtonClick"
QT_MOC_LITERAL(37, 0), // ""
QT_MOC_LITERAL(38, 20), // "onAddCubeButtonClick"
QT_MOC_LITERAL(59, 21), // "onAddPlaneButtonClick"
QT_MOC_LITERAL(81, 22), // "onAddSphereButtonClick"
QT_MOC_LITERAL(104, 22), // "onAddCircleButtonClick"
QT_MOC_LITERAL(127, 24), // "onAddTriangleButtonClick"
QT_MOC_LITERAL(152, 22), // "onAddMonkeyButtonClick"
QT_MOC_LITERAL(175, 22), // "onAddTeapotButtonClick"
QT_MOC_LITERAL(198, 19), // "onAddOBJButtonClick"
QT_MOC_LITERAL(218, 21), // "onAddLightButtonClick"
QT_MOC_LITERAL(240, 22), // "onSolidViewButtonClick"
QT_MOC_LITERAL(263, 21), // "onWireViewButtonClick"
QT_MOC_LITERAL(285, 22), // "onLightViewButtonClick"
QT_MOC_LITERAL(308, 17), // "onExitButtonClick"
QT_MOC_LITERAL(326, 16), // "onBugButtonClick"
QT_MOC_LITERAL(343, 17), // "onCodeButtonClick"
QT_MOC_LITERAL(361, 26), // "onDocumentationButtonClick"
QT_MOC_LITERAL(388, 14) // "onRenderButton"

    },
    "MainWindow\0onToggleSelectButtonClick\0"
    "\0onAddCubeButtonClick\0onAddPlaneButtonClick\0"
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
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  122,    2, 0x08,    1 /* Private */,
       3,    0,  123,    2, 0x08,    2 /* Private */,
       4,    0,  124,    2, 0x08,    3 /* Private */,
       5,    0,  125,    2, 0x08,    4 /* Private */,
       6,    0,  126,    2, 0x08,    5 /* Private */,
       7,    0,  127,    2, 0x08,    6 /* Private */,
       8,    0,  128,    2, 0x08,    7 /* Private */,
       9,    0,  129,    2, 0x08,    8 /* Private */,
      10,    0,  130,    2, 0x08,    9 /* Private */,
      11,    0,  131,    2, 0x08,   10 /* Private */,
      12,    0,  132,    2, 0x08,   11 /* Private */,
      13,    0,  133,    2, 0x08,   12 /* Private */,
      14,    0,  134,    2, 0x08,   13 /* Private */,
      15,    0,  135,    2, 0x08,   14 /* Private */,
      16,    0,  136,    2, 0x08,   15 /* Private */,
      17,    0,  137,    2, 0x08,   16 /* Private */,
      18,    0,  138,    2, 0x08,   17 /* Private */,
      19,    0,  139,    2, 0x08,   18 /* Private */,

 // slots: parameters
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
        case 0: _t->onToggleSelectButtonClick(); break;
        case 1: _t->onAddCubeButtonClick(); break;
        case 2: _t->onAddPlaneButtonClick(); break;
        case 3: _t->onAddSphereButtonClick(); break;
        case 4: _t->onAddCircleButtonClick(); break;
        case 5: _t->onAddTriangleButtonClick(); break;
        case 6: _t->onAddMonkeyButtonClick(); break;
        case 7: _t->onAddTeapotButtonClick(); break;
        case 8: _t->onAddOBJButtonClick(); break;
        case 9: _t->onAddLightButtonClick(); break;
        case 10: _t->onSolidViewButtonClick(); break;
        case 11: _t->onWireViewButtonClick(); break;
        case 12: _t->onLightViewButtonClick(); break;
        case 13: _t->onExitButtonClick(); break;
        case 14: _t->onBugButtonClick(); break;
        case 15: _t->onCodeButtonClick(); break;
        case 16: _t->onDocumentationButtonClick(); break;
        case 17: _t->onRenderButton(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


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
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 18;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
