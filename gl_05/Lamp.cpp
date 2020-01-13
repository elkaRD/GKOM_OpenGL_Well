#include "Lamp.h"

Lamp::Lamp(GameObject *parent) : GameObject(parent)
{

}

void Lamp::start()
{
	GameObject *base1 = new GameObject(this);
	base1->addMesh(new CubeMesh());
	addChild(base1);
}

void Lamp::update(float delta)
{

}