#include "Well.h"

Well::Well(GameObject *parent) : GameObject(parent)
{

}

void Well::start()
{
	meshes.push_back(new CubeMesh());
}

void Well::update(float delta)
{
	transform.rotate(0, 30.0f * delta, 0);
}