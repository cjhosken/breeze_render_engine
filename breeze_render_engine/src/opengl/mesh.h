#ifndef MESH_H
#define MESH_H

#include "../common.h"
#include "vertex.h"

class Mesh : protected QOpenGLFunctions_4_5_Core {
public:
	std::vector<Vertex> data;

	Mesh() {}

	Mesh(std::vector<Vertex> inData) {
		data = inData;
		bind();
	}

	Mesh(const Mesh& m) {
		data = m.data;
		bind();
	}

	Mesh& operator=(Mesh const & m) {
		data = m.data;
		bind();

		return *this;
	};

	unsigned int getVAO() {
		return VAO;
	}

	void dispose() {
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
	}

private:
	unsigned int VAO{};
	unsigned int VBO{};

	void bind() {
		initializeOpenGLFunctions();

		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);

		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(Vertex), &data[0], GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));

		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));

		glBindVertexArray(0);
	}
};

#endif // !MESH_H
