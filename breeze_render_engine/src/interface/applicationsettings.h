#ifndef APPLICATIONSETTINGS_H
#define APPLICATIONSETTINGS_H

#include "../common.h"

class ApplicationSettings {
public:
	unsigned int APP_WIDTH;
	unsigned int APP_HEIGHT;

	unsigned int splashTime;

	float appRadius;
	float dragHeight;

	QColor innerGradientColor;
	QColor outerGradientColor;

	QVector3D COLOR_SELECTED;

	ApplicationSettings() {
		APP_WIDTH = 1600;
		APP_HEIGHT = 900;

		COLOR_SELECTED = QVector3D(0.66f, 0.29f, 0.84f);

		splashTime = 2000;

		appRadius = 50.0f;

		dragHeight = 50.0f;

		innerGradientColor = (0.10f * 255, 0.1f * 255, 0.1f * 255);
		outerGradientColor = (0.05f * 255, 0.05f * 255, 0.075f * 255);
	}
};

#endif // !APPLICATIONSETTINGS_H