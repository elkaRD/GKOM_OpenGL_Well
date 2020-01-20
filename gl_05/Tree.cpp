#include "Tree.h"

Tree::Tree(GameObject *parent) : GameObject(parent)
{

}

void Tree::start()
{
	GameObject *g1 = new GameObject(this);
	g1->addMesh(new Pyramid());
	//MeshRenderer *mesh = g1->addMesh(new CubeMesh());
	//mesh->verticalInterpolationScale(1, 0);
}

void Tree::update(float delta)
{

}