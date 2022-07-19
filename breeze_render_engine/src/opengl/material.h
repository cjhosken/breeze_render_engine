#ifndef MATERIAL_H
#define MATERIAL_H

#include "../common.h"

struct Material {
	QColor color;
	float roughness;
	float specular;
};

#endif // !MATERIAL_H