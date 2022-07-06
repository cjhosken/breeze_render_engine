#ifndef RENDERCAMERA_H
#define RENDERCAMERA_H

#include "../common.h"
#include "shader.h"
#include "model.h"
#include "ray.h"

#include "../interface/rendersettings.h"

class RenderCamera : public Model {
public:
	RenderSettings settings;

	RenderCamera() : Model() {
		settings = RenderSettings();
		settings.fov = 35.0f;

		rescale();
	}

	void init() {
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
	}

	void rescale() {
		scale = QVector3D(float(settings.width) / float(settings.height), 1.0f, settings.fov / 180.0f);
	}

	void setupForRender() {
		QVector4D front(0.0f, 0.0f, -1.0f, 0.0);
		front = front * getModelMatrix();


		QVector3D target = QVector3D(front.x(), front.y(), front.z());
		QVector3D vup = QVector3D(0.0, -1.0f, 0.0);


		float aspect_ratio = float(settings.width) / float(settings.height);

		float theta = qDegreesToRadians(settings.fov);
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

private:
	QVector3D lower_left_corner;
	QVector3D horizontal;
	QVector3D vertical;
};

#endif // !RENDERCAMERA_H