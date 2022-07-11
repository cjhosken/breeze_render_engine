#ifndef LIGHT_H
#define LIGHT_H

#include "../common.h"
#include "model.h"


class Light : public Model {
public:
	QVector3D positon;
	QVector3D color;

	float strength;
	float falloff;

	Light() : Model() {}
	
	Light(std::string n) : Model(n) {
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
