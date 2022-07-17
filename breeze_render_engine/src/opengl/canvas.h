#ifndef CANVAS_H
#define CANVAS_H

#include "../common.h"
#include "vertex.h"
#include "shader.h"

class Canvas : public Model {
public:
	QVector3D innerColor = QVector3D(0, 0, 0);
	QVector3D outerColor = QVector3D(0, 0, 0);

	Canvas() : Model() {
		
	}

	void init() {
		initializeOpenGLFunctions();
		std::vector<Vertex> vertices = {
		{QVector3D(-1.0f, -1.0f, 0.0f), QVector3D(0.0f, 0.0f, 1.0f), QVector2D(0.0f, 0.0f)},
		{QVector3D(-1.0f, 3.0f, 0.0f), QVector3D(0.0f, 0.0f, 1.0f), QVector2D(0.0f, 1.0f)},
		{QVector3D(3.0f, -1.0f, 0.0f), QVector3D(0.0f, 0.0f, 1.0f), QVector2D(1.0, 0.0f)},
		};

		Mesh canvasMesh = Mesh(vertices);

		mesh = canvasMesh;
	}

	void draw(Shader &shader) {
		shader.use();
		shader.setVec3("inner", innerColor);
		shader.setVec3("outer", outerColor);

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		glBindVertexBuffer(0, mesh.getVBO(), 0, sizeof(Vertex));
		glBindVertexBuffer(1, mesh.getVBO(), offsetof(Vertex, normal), sizeof(Vertex));
		glBindVertexBuffer(2, mesh.getVBO(), offsetof(Vertex, uv), sizeof(Vertex));
		glDrawArrays(GL_TRIANGLES, 0, mesh.data.size());
	}
};


#endif