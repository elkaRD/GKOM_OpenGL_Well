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
	GameObject *roller;
	const float fullAnimationDuration = 7;
	const float fluentActivation = 2;
	const float rotationSpeed = 300;
	float rollTime = 0;
	bool direction = true;

	GameObject* createStem(GameObject *parent);
	GameObject* createPeak(GameObject *parent);
	GameObject* createRoller(GameObject *parent);
};

#endif