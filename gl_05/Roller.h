#ifndef ROLLER_H
#define ROLLER_H

#include "GameObject.h"
#include "CylinderMesh.h"
#include "CubeMesh.h"
#include "Chain.h"

class Roller : public GameObject
{
public:
	Roller(GameObject* parent);
	Roller(GameObject* parent, GLfloat radius, GLfloat height);
	void start();
	void update(float delta);
	GLfloat getRadius() const;
	GLfloat getHeight() const;
private:
	GLfloat radius;
	GLfloat height;

	Chain* chain;

	float wait;
};

#endif // !ROLLER_H

