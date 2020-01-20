#include "Tree.h"

Tree::Tree(GameObject *parent) : GameObject(parent)
{

}

void Tree::start()
{
	GameObject *root = new GameObject(this);
	MeshRenderer *mesh = root->addMesh(new CylinderMesh());
	mesh->scaleVertices(0.8f, 0.75f, 0.8f);
	mesh->verticalInterpolationScale(1, randomFloat(0.2f, 0.6f));
	root->transform.translate(0, randomFloat(1, 2), 0);
	root->setTexture("textures/wood1.png");

	GameObject *p = this;
	int levels = 3;
	if (rand() % 3 == 0) levels = 4;
	else if (rand() % 4 == 0) levels = 5;

	for (int i = 0; i < levels; ++i)
	{
		GameObject *g = new GameObject(p);
		g->addMesh(new Pyramid(randomInt(5, 8), randomFloat(4, 5) * pow(0.8f, i), randomFloat(4, 5) * pow(0.7f, i)));
		g->transform.translate(0, randomFloat(2.5f, 3.0f) * pow(0.85f, i), 0);
		g->transform.rotate(0, randomFloat(0, 360), 0);
		g->setTexture("textures/leaves.jpg");

		p = g;
	}
}

void Tree::update(float delta)
{

}