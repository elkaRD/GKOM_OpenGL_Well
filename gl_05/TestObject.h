#ifndef TEST_OBJECT_H
#define TEST_OBJECT_H

#include "GameObject.h"
#include "CubeMesh.h"
#include "CylinderMesh.h"
#include "TubeMesh.h"
#include "PlaneMesh.h"
#include "ChLinkMesh.h"

class TestObject : public GameObject
{
public:
	TestObject(GameObject* parent);
	void start();
	void update(float delta);

private:

};

#endif
