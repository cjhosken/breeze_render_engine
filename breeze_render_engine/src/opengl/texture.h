#ifndef TEXTURE_H
#define TEXTURE_H

#include "../common.h"

class Texture : protected QOpenGLFunctions_4_5_Core {
public:
	const char* path;
	unsigned int TXO;
	bool alpha;

	Texture(const char* p, bool a) {
		path = p;
		alpha = a;
		load();
	}

	void load();

	Texture(const Texture& s) {
		path = s.path;
		alpha = s.alpha;
		load();
	}

	Texture& operator=(Texture const& t) {
		path = t.path;
		alpha = t.alpha;
		load();

		return *this;
	};
};

#endif // !TEXTURE_H