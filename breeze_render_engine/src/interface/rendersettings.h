#ifndef RENDERSETTINGS_H
#define RENDERSETTINGS_H

class RenderSettings {
public:
	int width;
	int height;
	int channels;
	int samples;
	int depth;
	float fov;

	RenderSettings() {
		width = 160;
		height = 90;

		channels = 3;
		samples = 4;
		depth = 2;

		fov = 45.0f;
	}
};

#endif // !RENDERSETTINGS