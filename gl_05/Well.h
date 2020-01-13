#ifndef WELL_OBJECT_H
#define WELL_OBJECT_H

#include "GameObject.h"
#include "CubeMesh.h"
#include "CylinderMesh.h"
#include "TubeMesh.h"
#include "PlaneMesh.h"
#include "Ground.h"

class Well : public GameObject
{
public:

	Well(GameObject *parent);
	void start();
	void update(float delta);

private:
	GameObject* createStem();
};

#endif