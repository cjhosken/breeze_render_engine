#ifndef CANVAS_H
#define CANVAS_H

#include "../common.h"
#include "vertex.h"
#include "shader.h"

class Canvas : protected QOpenGLExtraFunctions{
public:
	QVector3D innerColor = QVector3D(0, 0, 0);
	QVector3D outerColor = QVector3D(0, 0, 0);

	Canvas() {	
	}

	void init() {
		initializeOpenGLFunctions();

		glGenBuffers(1, &VBO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
	}

	void draw(Shader &shader) {
		shader.use();
		shader.setVec3("inner", innerColor);
		shader.setVec3("outer", outerColor);

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glDrawArrays(GL_TRIANGLES, 0, vertices.size());
	}

	void dispose() {
		glDeleteBuffers(1, &VBO);
	}

private:
	unsigned int VBO;

	std::vector<Vertex> vertices = {
			{QVector3D(1.0f, 1.0f, 0.0f), QVector3D(0.0f, 0.0f, 1.0f), QVector2D(1.0f, 1.0f)},
			{QVector3D(1.0f, -1.0f, 0.0f), QVector3D(0.0f, 0.0f, 1.0f), QVector2D(1.0f, 0.0f)},
			{QVector3D(-1.0f, 1.0f, 0.0f), QVector3D(0.0f, 0.0f, 1.0f), QVector2D(0.0, 1.0f)},

			{QVector3D(1.0f, -1.0f, 0.0f), QVector3D(0.0f, 0.0f, 1.0f), QVector2D(1.0f, 0.0f)},
			{QVector3D(-1.0f, -1.0f, 0.0f), QVector3D(0.0f, 0.0f, 1.0f), QVector2D(0.0f, 0.0f)},
			{QVector3D(-1.0f, 1.0f, 0.0f), QVector3D(0.0f, 0.0f, 1.0f), QVector2D(0.0f, 1.0f)}
	};
};


#endif