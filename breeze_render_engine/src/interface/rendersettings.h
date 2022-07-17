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

	RenderSettings() {
		width = 160;
		height = 90;

		channels = 3;
		samples = 4;
		bounces = 2;
	}
};

#endif // !RENDERSETTINGS