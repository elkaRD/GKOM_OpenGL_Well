#include "Well.h"

Well::Well(GameObject *parent) : GameObject(parent)
{

}

void Well::start()
{
	meshes.push_back(new TubeMesh());
}

void Well::update(float delta)
{
	//transform.rotate(0, 300.0f * delta, 0);
}