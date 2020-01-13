#include "Well.h"

Well::Well(GameObject *parent) : GameObject(parent)
{

}

void Well::start()
{
	addMesh(new TubeMesh());
	setTexture("textures/brickwall.jpg");

	MeshRenderer *cube = new CubeMesh();
	addMesh(cube);
	cube->verticalInterpolationScale(1.2f, 0.3f);
}

void Well::update(float delta)
{

}