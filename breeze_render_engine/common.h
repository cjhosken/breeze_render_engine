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
#include <QOpenGLFunctions_4_5_Core>

#include <QMouseEvent>
#include <QWheelEvent>

#define APP_WIDTH 1280
#define APP_HEIGHT 700

#define SELECTED_COLOR QVector3D(0.66f, 0.29f, 0.84f)

#include <cmath>

enum ObjectType {
    SOLID,
    WIREFRAME,
};

enum DrawType {
    DEFAULT,
    WIRE,
    ID
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