#ifndef RENDERCAMERA_H
#define RENDERCAMERA_H

#include "../common.h"
#include "shader.h"
#include "model.h"
#include "ray.h"

class RenderCamera : public Model {
public:
	int width = 640;
	int height = 480;

	int channels = 3;
	int samples = 4;
	int bounces = 2;

	bool dof = false;
	float distance = 1.0f;
	float aperture = 2.0f;
	float fov = 35.0f;

	RenderCamera(QString n) : Model(n) {
		initializeOpenGLFunctions();
		std::vector<Vertex> vertices = {
			{QVector3D(0.0f,0.0f,0.0f), QVector3D(0.0f,0.0f,0.0f), QVector2D(0.0f,0.0f)},
			{QVector3D(-0.5f, 0.5f, -1.0f), QVector3D(0.0f, 0.0f, 0.0f), QVector2D(0.0f,0.0f)},
			{QVector3D(0.5f, 0.5f, -1.0f), QVector3D(0.0f, 0.0f, 0.0f), QVector2D(0.0f,0.0f)},

			{QVector3D(0.0f,0.0f,0.0f), QVector3D(0.0f,0.0f,0.0f), QVector2D(0.0f, 0.0f)},
			{QVector3D(-0.5f, 0.5f, -1.0f), QVector3D(0.0f, 0.0f, 0.0f), QVector2D(0.0f,0.0f)},
			{QVector3D(-0.5f, -0.5f, -1.0f), QVector3D(0.0f, 0.0f, 0.0f), QVector2D(0.0f,0.0f)},

			{QVector3D(0.0f,0.0f,0.0f), QVector3D(0.0f, 0.0f, 0.0f), QVector2D(0.0f, 0.0f)},
			{QVector3D(0.5f, 0.5f, -1.0f), QVector3D(0.0f,0.0f,0.0f), QVector2D(0.0f,0.0f)},
			{QVector3D(0.5f, -0.5f, -1.0f), QVector3D(0.0f,0.0f,0.0f), QVector2D(0.0f,0.0f)},

			{QVector3D(0.0f,0.0f,0.0f), QVector3D(0.0f,0.0f,0.0f), QVector2D(0.0f,0.0f)},
			{QVector3D(-0.5f, -0.5f, -1.0f), QVector3D(0.0f,0.0f,0.0f), QVector2D(0.0f,0.0f)},
			{QVector3D(0.5f, -0.5f, -1.0f), QVector3D(0.0f,0.0f,0.0f), QVector2D(0.0f,0.0f)}
		};

		Mesh cameraMesh = Mesh(vertices);

		mesh = cameraMesh;

		rescale();
	}

	void setFov(float f) {
		fov = f;
		rescale();
	}

	void setWidth(int w) {
		width = w;
		rescale();
	}

	void setHeight(int h) {
		height = h;
		rescale();
	}

	void rescale() {
		float ratio = float(width) / float(height);

		qDebug() << "FOV: " << fov;
		qDebug() << "RATIO: " << ratio;
		qDebug() << "WIDTH: " << float(width);
		qDebug() << "HEIGHT: " << float(height);


		scale = QVector3D(ratio, 1.0f, (fov / 180.0f));
	}

	void setupForRender() {
		QVector4D front(0.0f, 0.0f, -1.0f, 0.0);
		front = front * getModelMatrix();


		QVector3D target = QVector3D(front.x(), front.y(), front.z());
		QVector3D vup = QVector3D(0.0, -1.0f, 0.0);


		float aspect_ratio = float(width) / float(height);

		float theta = qDegreesToRadians(fov);
		float h = tan(theta / 2);
		float viewport_height = 1.0 * h;
		float viewport_width = aspect_ratio * viewport_height;

		QVector3D w = (location - target).normalized();
		QVector3D u = QVector3D().crossProduct(vup, w);
		QVector3D v = QVector3D().crossProduct(w, u);

		horizontal = viewport_width * u;
		vertical = viewport_height * v;
		lower_left_corner = location - horizontal / 2.0f - vertical / 2.0f - w;
	}

	Ray get_ray(float s, float t) const {
		return Ray(location, lower_left_corner + s * horizontal + t * vertical - location);
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

private:
	QVector3D lower_left_corner;
	QVector3D horizontal;
	QVector3D vertical;
};

#endif // !RENDERCAMERA_H