#ifndef CANVAS_H
#define CANVAS_H

#include "../common.h"
#include "vertex.h"
#include "shader.h"

class Canvas : protected QOpenGLFunctions_4_5_Core {
public:
	Canvas() {	
	}

	void init() {
		initializeOpenGLFunctions();

		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);

		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));

		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));

		glBindVertexArray(0);
	}

	void draw(Shader &shader) {
		shader.use();

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, vertices.size());
		glBindVertexArray(0);
	}

	void dispose() {
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
	}

private:
	unsigned int VAO, VBO;

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