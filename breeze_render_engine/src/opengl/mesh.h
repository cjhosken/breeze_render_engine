#ifndef MESH_H
#define MESH_H

#include "../common.h"
#include "vertex.h"

class Mesh : protected QOpenGLExtraFunctions {
public:
	std::vector<Vertex> data;

	Mesh() {}

	Mesh(std::vector<Vertex>& inData) {
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

	unsigned int getVBO() {
		return VBO;
	}

	void dispose() {
		glDeleteBuffers(1, &VBO);
	}

private:
	unsigned int VBO{};

	void bind() {
		initializeOpenGLFunctions();

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(Vertex), data.data(), GL_STATIC_DRAW);

	}
};


#endif // !MESH_H
