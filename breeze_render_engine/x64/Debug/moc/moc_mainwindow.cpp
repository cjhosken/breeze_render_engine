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
    const uint offsetsAndSize[108];
    char stringdata0[946];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 25), // "setSelectedObjectLocation"
QT_MOC_LITERAL(37, 0), // ""
QT_MOC_LITERAL(38, 1), // "l"
QT_MOC_LITERAL(40, 25), // "setSelectedObjectRotation"
QT_MOC_LITERAL(66, 1), // "r"
QT_MOC_LITERAL(68, 22), // "setSelectedObjectScale"
QT_MOC_LITERAL(91, 1), // "s"
QT_MOC_LITERAL(93, 20), // "renameSelectedObject"
QT_MOC_LITERAL(114, 1), // "n"
QT_MOC_LITERAL(116, 22), // "setSelectedObjectColor"
QT_MOC_LITERAL(139, 3), // "col"
QT_MOC_LITERAL(143, 26), // "setSelectedObjectRoughness"
QT_MOC_LITERAL(170, 25), // "setSelectedObjectSpecular"
QT_MOC_LITERAL(196, 25), // "setSelectedObjectStrength"
QT_MOC_LITERAL(222, 5), // "num_f"
QT_MOC_LITERAL(228, 20), // "setSelectedObjectFOV"
QT_MOC_LITERAL(249, 1), // "f"
QT_MOC_LITERAL(251, 20), // "setSelectedObjectDOF"
QT_MOC_LITERAL(272, 1), // "b"
QT_MOC_LITERAL(274, 25), // "setSelectedObjectDistance"
QT_MOC_LITERAL(300, 25), // "setSelectedObjectAperture"
QT_MOC_LITERAL(326, 14), // "setRenderWidth"
QT_MOC_LITERAL(341, 5), // "num_s"
QT_MOC_LITERAL(347, 15), // "setRenderHeight"
QT_MOC_LITERAL(363, 16), // "setRenderSamples"
QT_MOC_LITERAL(380, 16), // "setRenderBounces"
QT_MOC_LITERAL(397, 17), // "updateObjectPanel"
QT_MOC_LITERAL(415, 29), // "updateInnerBackgroundGradient"
QT_MOC_LITERAL(445, 5), // "inner"
QT_MOC_LITERAL(451, 29), // "updateOuterBackgroundGradient"
QT_MOC_LITERAL(481, 5), // "outer"
QT_MOC_LITERAL(487, 20), // "onViewportFOVChanged"
QT_MOC_LITERAL(508, 5), // "value"
QT_MOC_LITERAL(514, 18), // "toggleSelectButton"
QT_MOC_LITERAL(533, 20), // "onAddCubeButtonClick"
QT_MOC_LITERAL(554, 21), // "onAddPlaneButtonClick"
QT_MOC_LITERAL(576, 22), // "onAddSphereButtonClick"
QT_MOC_LITERAL(599, 22), // "onAddCircleButtonClick"
QT_MOC_LITERAL(622, 24), // "onAddCylinderButtonClick"
QT_MOC_LITERAL(647, 24), // "onAddTriangleButtonClick"
QT_MOC_LITERAL(672, 22), // "onAddMonkeyButtonClick"
QT_MOC_LITERAL(695, 22), // "onAddTeapotButtonClick"
QT_MOC_LITERAL(718, 19), // "onAddOBJButtonClick"
QT_MOC_LITERAL(738, 21), // "onAddLightButtonClick"
QT_MOC_LITERAL(760, 22), // "onAddCameraButtonClick"
QT_MOC_LITERAL(783, 22), // "onSolidViewButtonClick"
QT_MOC_LITERAL(806, 21), // "onWireViewButtonClick"
QT_MOC_LITERAL(828, 22), // "onLightViewButtonClick"
QT_MOC_LITERAL(851, 17), // "onExitButtonClick"
QT_MOC_LITERAL(869, 16), // "onBugButtonClick"
QT_MOC_LITERAL(886, 17), // "onCodeButtonClick"
QT_MOC_LITERAL(904, 26), // "onDocumentationButtonClick"
QT_MOC_LITERAL(931, 14) // "onRenderButton"

    },
    "MainWindow\0setSelectedObjectLocation\0"
    "\0l\0setSelectedObjectRotation\0r\0"
    "setSelectedObjectScale\0s\0renameSelectedObject\0"
    "n\0setSelectedObjectColor\0col\0"
    "setSelectedObjectRoughness\0"
    "setSelectedObjectSpecular\0"
    "setSelectedObjectStrength\0num_f\0"
    "setSelectedObjectFOV\0f\0setSelectedObjectDOF\0"
    "b\0setSelectedObjectDistance\0"
    "setSelectedObjectAperture\0setRenderWidth\0"
    "num_s\0setRenderHeight\0setRenderSamples\0"
    "setRenderBounces\0updateObjectPanel\0"
    "updateInnerBackgroundGradient\0inner\0"
    "updateOuterBackgroundGradient\0outer\0"
    "onViewportFOVChanged\0value\0"
    "toggleSelectButton\0onAddCubeButtonClick\0"
    "onAddPlaneButtonClick\0onAddSphereButtonClick\0"
    "onAddCircleButtonClick\0onAddCylinderButtonClick\0"
    "onAddTriangleButtonClick\0"
    "onAddMonkeyButtonClick\0onAddTeapotButtonClick\0"
    "onAddOBJButtonClick\0onAddLightButtonClick\0"
    "onAddCameraButtonClick\0onSolidViewButtonClick\0"
    "onWireViewButtonClick\0onLightViewButtonClick\0"
    "onExitButtonClick\0onBugButtonClick\0"
    "onCodeButtonClick\0onDocumentationButtonClick\0"
    "onRenderButton"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      40,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  254,    2, 0x08,    1 /* Private */,
       4,    1,  257,    2, 0x08,    3 /* Private */,
       6,    1,  260,    2, 0x08,    5 /* Private */,
       8,    1,  263,    2, 0x08,    7 /* Private */,
      10,    1,  266,    2, 0x08,    9 /* Private */,
      12,    1,  269,    2, 0x08,   11 /* Private */,
      13,    1,  272,    2, 0x08,   13 /* Private */,
      14,    1,  275,    2, 0x08,   15 /* Private */,
      16,    1,  278,    2, 0x08,   17 /* Private */,
      18,    1,  281,    2, 0x08,   19 /* Private */,
      20,    1,  284,    2, 0x08,   21 /* Private */,
      21,    1,  287,    2, 0x08,   23 /* Private */,
      22,    1,  290,    2, 0x08,   25 /* Private */,
      24,    1,  293,    2, 0x08,   27 /* Private */,
      25,    1,  296,    2, 0x08,   29 /* Private */,
      26,    1,  299,    2, 0x08,   31 /* Private */,
      27,    0,  302,    2, 0x08,   33 /* Private */,
      28,    1,  303,    2, 0x08,   34 /* Private */,
      30,    1,  306,    2, 0x08,   36 /* Private */,
      32,    1,  309,    2, 0x08,   38 /* Private */,
      34,    0,  312,    2, 0x08,   40 /* Private */,
      35,    0,  313,    2, 0x08,   41 /* Private */,
      36,    0,  314,    2, 0x08,   42 /* Private */,
      37,    0,  315,    2, 0x08,   43 /* Private */,
      38,    0,  316,    2, 0x08,   44 /* Private */,
      39,    0,  317,    2, 0x08,   45 /* Private */,
      40,    0,  318,    2, 0x08,   46 /* Private */,
      41,    0,  319,    2, 0x08,   47 /* Private */,
      42,    0,  320,    2, 0x08,   48 /* Private */,
      43,    0,  321,    2, 0x08,   49 /* Private */,
      44,    0,  322,    2, 0x08,   50 /* Private */,
      45,    0,  323,    2, 0x08,   51 /* Private */,
      46,    0,  324,    2, 0x08,   52 /* Private */,
      47,    0,  325,    2, 0x08,   53 /* Private */,
      48,    0,  326,    2, 0x08,   54 /* Private */,
      49,    0,  327,    2, 0x08,   55 /* Private */,
      50,    0,  328,    2, 0x08,   56 /* Private */,
      51,    0,  329,    2, 0x08,   57 /* Private */,
      52,    0,  330,    2, 0x08,   58 /* Private */,
      53,    0,  331,    2, 0x08,   59 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QVector3D,    3,
    QMetaType::Void, QMetaType::QVector3D,    5,
    QMetaType::Void, QMetaType::QVector3D,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QColor,   11,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QColor,   29,
    QMetaType::Void, QMetaType::QColor,   31,
    QMetaType::Void, QMetaType::Int,   33,
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
        case 0: _t->setSelectedObjectLocation((*reinterpret_cast< std::add_pointer_t<QVector3D>>(_a[1]))); break;
        case 1: _t->setSelectedObjectRotation((*reinterpret_cast< std::add_pointer_t<QVector3D>>(_a[1]))); break;
        case 2: _t->setSelectedObjectScale((*reinterpret_cast< std::add_pointer_t<QVector3D>>(_a[1]))); break;
        case 3: _t->renameSelectedObject((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->setSelectedObjectColor((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 5: _t->setSelectedObjectRoughness((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->setSelectedObjectSpecular((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->setSelectedObjectStrength((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->setSelectedObjectFOV((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->setSelectedObjectDOF((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 10: _t->setSelectedObjectDistance((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 11: _t->setSelectedObjectAperture((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->setRenderWidth((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 13: _t->setRenderHeight((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 14: _t->setRenderSamples((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 15: _t->setRenderBounces((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 16: _t->updateObjectPanel(); break;
        case 17: _t->updateInnerBackgroundGradient((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 18: _t->updateOuterBackgroundGradient((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 19: _t->onViewportFOVChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 20: _t->toggleSelectButton(); break;
        case 21: _t->onAddCubeButtonClick(); break;
        case 22: _t->onAddPlaneButtonClick(); break;
        case 23: _t->onAddSphereButtonClick(); break;
        case 24: _t->onAddCircleButtonClick(); break;
        case 25: _t->onAddCylinderButtonClick(); break;
        case 26: _t->onAddTriangleButtonClick(); break;
        case 27: _t->onAddMonkeyButtonClick(); break;
        case 28: _t->onAddTeapotButtonClick(); break;
        case 29: _t->onAddOBJButtonClick(); break;
        case 30: _t->onAddLightButtonClick(); break;
        case 31: _t->onAddCameraButtonClick(); break;
        case 32: _t->onSolidViewButtonClick(); break;
        case 33: _t->onWireViewButtonClick(); break;
        case 34: _t->onLightViewButtonClick(); break;
        case 35: _t->onExitButtonClick(); break;
        case 36: _t->onBugButtonClick(); break;
        case 37: _t->onCodeButtonClick(); break;
        case 38: _t->onDocumentationButtonClick(); break;
        case 39: _t->onRenderButton(); break;
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
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector3D, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector3D, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector3D, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QColor, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QColor, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QColor, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


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
        if (_id < 40)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 40;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 40)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 40;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
