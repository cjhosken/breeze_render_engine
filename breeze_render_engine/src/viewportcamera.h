#ifndef VIEWPORTCAMERA_H
#define VIEWPORTCAMERA_H

#include "../common.h"


class ViewportCamera {
public:
	QVector3D rotation;
	float zoom = 5.0f;
	float sensitivity = 10.0f;
	float zoom_sensitivity = 0.0025f;

	ViewportCamera()
	{
		rotation = QVector3D(0.0, 0.0, 0.0);
	}

	QMatrix4x4 getViewMatrix() {

		QVector3D transformed = getCameraPosition();
		QMatrix4x4 viewMatrix = QMatrix4x4();
		viewMatrix.lookAt(transformed, QVector3D(0, 0, 0), QVector3D(0, 1, 0));

		return viewMatrix;
	}

	QVector3D getCameraPosition() {
		QMatrix4x4 rxMatrix = QMatrix4x4();
		rxMatrix.setToIdentity();
		rxMatrix.rotate(rotation.x(), QVector3D(0.0, 1.0, 0.0));
		QMatrix4x4 ryMatrix = QMatrix4x4();
		ryMatrix.setToIdentity();
		ryMatrix.rotate(rotation.y(), QVector3D(1.0, 0.0, 0.0));

		QMatrix4x4 rotationMatrix = rxMatrix * ryMatrix;

		QVector4D point(0.0, 0.0, zoom, 1.0f);

		QVector3D transformed = QVector3D(rotationMatrix * point);

		return transformed;
	}

	void processMouseMovement(float xOffset, float yOffset)
	{
		xOffset *= sensitivity;
		yOffset *= sensitivity;

		rotation.setX(rotation.x() - qDegreesToRadians(xOffset));
		rotation.setY(rotation.y() + qDegreesToRadians(yOffset));
	}

	void processMouseScroll(float yOffset)
	{
		zoom -= (float)yOffset * zoom_sensitivity;
		if (zoom < 1.0f)
			zoom = 1.0f;
		if (zoom > 45.0f)
			zoom = 45.0f;
	}
};

#endif // !VIEWPORTCAMERA_H