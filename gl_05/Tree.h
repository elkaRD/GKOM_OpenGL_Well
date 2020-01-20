#ifndef TREE_H
#define TREE_H

#include "GameObject.h"
#include "Pyramid.h"
#include "CubeMesh.h"
#include "CylinderMesh.h"

class Tree : public GameObject
{
public:
	Tree(GameObject *parent);

	void start();
	void update(float delta);
private:

	std::vector<GameObject*> treeLayers;

	float minAngle;
	float maxAngle;
	float swayTime;
	float swayDuration;
};

#endif