#ifndef RAY_H
#define RAY_H

#include "../common.h"

class Ray {
public:
	Ray() {};

	Ray(QVector3D o, QVector3D d) : orig(o), dir(d) {}

	QVector3D origin() {
		return orig;
	}

	QVector3D direction() {
		return dir;
	}

	QVector3D at(float t) {
		return orig + dir * t;
	}
private:
	QVector3D orig;
	QVector3D dir;
};

#endif // !RAY_H