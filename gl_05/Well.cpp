#include "Well.h"

Well::Well(GameObject *parent) : GameObject(parent)
{

}

void Well::start()
{
	meshes.push_back(new TubeMesh());
	setTexture("textures/brickwall.jpg");
}

void Well::update(float delta)
{

}