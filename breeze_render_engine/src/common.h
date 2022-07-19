#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <memory>

#include <QVector>
#include <QVector2D>
#include <QVector3D>
#include <QVector4D>
#include <QMatrix4x4>

#include <QOpenGLWidget>
#include <QOpenGLExtraFunctions>
#include <QApplication>
#include <QSurfaceFormat>
#include <QIcon>
#include <QWidget>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QHBoxLayout>
#include <QVariant>
#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include <QCheckBox>
#include <QMessageBox>
#include <QFileDialog>
#include <QMenu>
#include <QAction>
#include <QSlider>
#include <QTemporaryDir>
#include <QColorDialog>
#include <QRegularExpression>
#include <QIntValidator>
#include <QDoubleValidator>
#include <QDesktopServices>
#include <QSettings>
#include <QPainterPath>

#include <QKeyEvent>
#include <QMouseEvent>

#include <QPushButton>
#include <QTimer>
#include <QSplashScreen>

#include <QMouseEvent>
#include <QWheelEvent>

#include <cmath>

enum ObjectType {
    SOLID,
    WIREFRAME,
};

enum DrawType {
    DEFAULT,
    WIRE,
    ID,
    LIGHT
};

inline float random_float() {
    return float(rand()) / (RAND_MAX + 1.0);
};

inline float random_float(float min, float max) {
    return min + (max - min) * random_float();
}

inline QVector3D randomVec() {
    return QVector3D(
        random_float(),
        random_float(),
        random_float()
    );
}

inline QVector3D randomVec(float min, float max) {
    return QVector3D(
        random_float(min, max),
        random_float(min, max),
        random_float(min, max)
    );
}

inline QVector3D randomInUnitSphere() {
    while (true) {
        QVector3D v = randomVec(-1, 1);
        if (v.lengthSquared() >= 1) continue;
        return v;
    }
}


#endif // !COMMON_H
