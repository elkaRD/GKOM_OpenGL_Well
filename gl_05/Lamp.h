#ifndef LAMP_H
#define LAMP_H

#include "GameObject.h"
#include "CubeMesh.h"
#include "CylinderMesh.h"

class Lamp : public GameObject
{
public:
	Lamp(GameObject *parent);
	void start();
	void update(float delta);

private:

};

#endif