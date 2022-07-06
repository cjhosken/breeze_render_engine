#ifndef MATERIAL_H
#define MATERIAL_H

#include "../common.h"

struct Material {
	QVector3D color;
	float roughness;
	float specular;
};

#endif // !MATERIAL_H