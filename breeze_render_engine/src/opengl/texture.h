#ifndef TEXTURE_H
#define TEXTURE_H

#include "../common.h"

class Texture : protected QOpenGLExtraFunctions {
public:
	QFileInfo path;
	unsigned int TXO;

	Texture(const char* p) {
		path = QFileInfo(p);
		load();
	}

	void load();

	Texture(const Texture& s) {
		path = s.path;
		load();
	}

	Texture& operator=(Texture const& t) {
		path = t.path;
		load();

		return *this;
	};
};

#endif // !TEXTURE_H