#ifndef CANVAS_H
#define CANVAS_H

#include "../common.h"
#include "vertex.h"
#include "shader.h"

class Canvas : public Model {
public:
	QColor innerColor = QColor(0, 0, 0);
	QColor outerColor = QColor(0, 0, 0);

	Canvas() : Model() {
		QSettings settings;
		innerColor = settings.value("color/viewportGradientInner").value<QColor>();
		outerColor = settings.value("color/viewportGradientOuter").value<QColor>();
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

	void setInnerColor(QColor &col) {
		innerColor = col;
	}

	void setOuterColor(QColor &col) {
		outerColor = col;
	}

	void draw(Shader &shader) {
		shader.use();
		qDebug() << innerColor;
		shader.setColor("inner", innerColor);
		shader.setColor("outer", outerColor);

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		glBindVertexBuffer(0, mesh.getVBO(), 0, sizeof(Vertex));
		glBindVertexBuffer(1, mesh.getVBO(), offsetof(Vertex, normal), sizeof(Vertex));
		glBindVertexBuffer(2, mesh.getVBO(), offsetof(Vertex, uv), sizeof(Vertex));
		glDrawArrays(GL_TRIANGLES, 0, mesh.data.size());
	}
};


#endif