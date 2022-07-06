#ifndef TEXTURE_H
#define TEXTURE_H

#include "../common.h"

class Texture : protected QOpenGLFunctions_4_5_Core {
public:
	const char* path;
	unsigned int TXO;

	Texture(const char* p) {
		path = p;
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