#ifndef WELL_OBJECT_H
#define WELL_OBJECT_H

#include "GameObject.h"
#include "CubeMesh.h"
#include "CylinderMesh.h"
#include "TubeMesh.h"

class Well : public GameObject
{
public:

	Well(GameObject *parent);
	void start();
	void update(float delta);

private:

};

#endif