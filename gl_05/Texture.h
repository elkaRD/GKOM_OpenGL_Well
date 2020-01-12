#ifndef TEXTURE_H
#define TEXTURE_H

#include <exception>
#include <GL/glew.h>
#include <SOIL.h>
#include "shprogram.h"

class Texture
{
public:
	Texture(ShaderProgram *shader, const char *fname);
	void use();

private:
	ShaderProgram *theProgram;
	GLuint texture0;

	GLuint LoadMipmapTexture(GLuint texId, const char* fname);
};

#endif