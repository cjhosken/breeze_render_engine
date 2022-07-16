#include "texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

void Texture::load() {
	initializeOpenGLFunctions();

	glGenTextures(1, &TXO);
	glBindTexture(GL_TEXTURE_2D, TXO);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int width, height, nrChannels;

	unsigned char* data;

	bool load = false;

	QTemporaryDir tempDir;
	if (tempDir.isValid()) {
		const QString tempFile = tempDir.path() + path.fileName();
		if (QFile::copy(path.absoluteFilePath(), tempFile)) {
			data = stbi_load(tempFile.toStdString().c_str(), &width, &height, &nrChannels, 0);
			load = true;
		}
	}
	if (load && data)
	{
		if (alpha) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		} else{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		}
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
}