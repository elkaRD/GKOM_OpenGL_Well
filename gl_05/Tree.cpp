#include "Tree.h"

Tree::Tree(GameObject *parent) : GameObject(parent)
{

}

void Tree::start()
{
	GameObject *p = this;
	int levels = 3;
	if (rand() % 3 == 0) levels = 4;
	else if (rand() % 4 == 0) levels = 5;

	for (int i = 0; i < levels; ++i)
	{
		GameObject *g2 = new GameObject(p);
		g2->addMesh(new Pyramid(randomInt(5, 8), randomFloat(4, 5) * pow(0.8f, i), randomFloat(4, 5) * pow(0.7f, i)));
		g2->transform.translate(0, randomFloat(2.5f, 3.0f) * pow(0.85f, i), 0);

		p = g2;
	}
}

void Tree::update(float delta)
{

}