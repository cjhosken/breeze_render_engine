#ifndef MODEL_H
#define MODEL_H

#include "../common.h"
#include "mesh.h"
#include "shader.h"
#include "material.h"
#include "../interface/applicationsettings.h"

class Model : protected QOpenGLExtraFunctions {
public:
	std::string name;
	QVector3D location = QVector3D(0.0f, 0.0f, 0.0f);
	QVector3D rotation = QVector3D(0.0f, 0.0f, 0.0f);
	QVector3D scale = QVector3D(1.0f, 1.0f, 1.0f);

	Model() {
		genID();
	}

	Model(std::string n) {
		initializeOpenGLFunctions();
		name = n;
		genID();
	}

	void genID() {
		id = rand();
	}
	
	void draw(Shader &shader, DrawType draw, ApplicationSettings &settings) {
		shader.use();
		shader.setMat4("model", getModelMatrix());
		if (draw == DEFAULT) {
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			shader.setMaterial(material);

			if (selected) {
				QVector3D newColor = (material.color + settings.COLOR_SELECTED) / 2.0f;
				shader.setVec3("material.color", newColor);
			}
		}
		else if (draw == WIRE) {
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			if (selected) {
				shader.setVec3("color", settings.COLOR_SELECTED);
				glLineWidth(5.0f);
			}
			else {
				shader.setVec3("color", QVector3D(0.6f, 0.6f, 0.6f));
			}
			glLineWidth(1.0f);
		}
		else if (draw == ID) {
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

			float rID = (id & 0x000000FF) >> 0;
			float gID = (id & 0x0000FF00) >> 8;
			float bID = (id & 0x00FF0000) >> 16;

			shader.setVec3("color", QVector3D(rID / 255.0f, gID / 255.0f, bID / 255.0f));
		}


		glBindVertexBuffer(0, mesh.getVBO(), 0, sizeof(Vertex));
		glBindVertexBuffer(1, mesh.getVBO(), offsetof(Vertex, normal), sizeof(Vertex));
		glBindVertexBuffer(2, mesh.getVBO(), offsetof(Vertex, uv), sizeof(Vertex));
		glDrawArrays(GL_TRIANGLES, 0, mesh.data.size());
	}

	QMatrix4x4 getModelMatrix() {
		QMatrix4x4 scaleMatrix = QMatrix4x4();
		scaleMatrix.setToIdentity();
		scaleMatrix.scale(scale);

		QMatrix4x4 rotMatrix = QMatrix4x4();
		rotMatrix.setToIdentity();
		
		QMatrix4x4 locMatrix = QMatrix4x4();
		locMatrix.setToIdentity();
		locMatrix.translate(location);

		return scaleMatrix * rotMatrix + locMatrix;
	}

	void dispose() {
		mesh.dispose();
	}

	unsigned int id = 1;
	bool selected = false;

	ObjectType type = SOLID;
	Mesh mesh;
	Material material = {
		QVector3D(1.0f, 1.0f, 1.0f),
		1.0f,
		0.5f
	};
};

#endif // !MODEL_H