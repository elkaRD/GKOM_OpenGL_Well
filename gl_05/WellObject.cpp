#include "WellObject.h"

Well::Well(GameObject *parent, GameScene *scene) : GameObject(parent, scene)
{
	//startObject();
}

void Well::start()
{
	meshes.push_back(new CubeMesh());
}