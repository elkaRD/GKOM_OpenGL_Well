#ifndef TREE_H
#define TREE_H

#include "GameObject.h"
#include "Pyramid.h"
#include "CubeMesh.h"

class Tree : public GameObject
{
public:
	Tree(GameObject *parent);

	void start();
	void update(float delta);
private:

};

#endif