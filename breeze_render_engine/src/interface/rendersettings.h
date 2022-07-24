#ifndef RENDERSETTINGS_H
#define RENDERSETTINGS_H

class RenderSettings {
public:
	int width;
	int height;
	int channels;
	int samples;
	int bounces;
	float fov;

	bool dof;
	float distance;
	float aperture;

	RenderSettings() {
		width = 160;
		height = 90;

		channels = 3;
		samples = 4;
		bounces = 2;

		dof = false;
		distance = 1.0f;
		aperture = 2.0f;
	}
};

#endif // !RENDERSETTINGS