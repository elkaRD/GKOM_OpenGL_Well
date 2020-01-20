#ifndef LIGHT_H
#define LIGHT_H

#include "GameObject.h"

class Light
{
public:
	void update(GLfloat lightIntensity, ShaderProgram* shader, ShaderProgram* shader2, glm::vec3 cameraPosition);
private:

};

#endif