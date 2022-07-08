#ifndef LIGHT_H
#define LIGHT_H

#include "../common.h"

class Light {
public:
	QVector3D positon;
	QVector3D color;

	float strength;
	float falloff;
	
	Light() {}
};

#endif
