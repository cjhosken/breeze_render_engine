#ifndef LIGHT_H
#define LIGHT_H

#include "../common.h"
#include "model.h"

#include "lightmaterial.h"

class Light : public Model {
public:

	LightMaterial light = {
		QColor(1.0f, 1.0f, 1.0f),
		1.0f
	};

	Light() : Model() {}
	
	Light(QString n) : Model(n) {
		initializeOpenGLFunctions();
		std::vector<Vertex> vertices = {
			{QVector3D(0.5f, 0.5f, 0.0f), QVector3D(0.0f, 0.0f, 1.0f), QVector2D(1.0f, 1.0f)},
			{QVector3D(0.5f, -0.5f, 0.0f), QVector3D(0.0f, 0.0f, 1.0f), QVector2D(1.0f, 0.0f)},
			{QVector3D(-0.5f, 0.5f, 0.0f), QVector3D(0.0f, 0.0f, 1.0f), QVector2D(0.0, 1.0f)},

			{QVector3D(0.5f, -0.5f, 0.0f), QVector3D(0.0f, 0.0f, 1.0f), QVector2D(1.0f, 0.0f)},
			{QVector3D(-0.5f, -0.5f, 0.0f), QVector3D(0.0f, 0.0f, 1.0f), QVector2D(0.0f, 0.0f)},
			{QVector3D(-0.5f, 0.5f, 0.0f), QVector3D(0.0f, 0.0f, 1.0f), QVector2D(0.0f, 1.0f)},
		};

		Mesh lightMesh = Mesh(vertices);

		mesh = lightMesh;
	}
};

#endif
