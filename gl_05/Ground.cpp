#include "Ground.h"

Ground::Ground(GameObject* parent) : GameObject(parent)
{

}

void Ground::start() 
{
	meshes.push_back(new PlaneMesh());
}

void Ground::update(float delta)
{
	//just stay where you are
}