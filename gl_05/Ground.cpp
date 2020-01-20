#include "Ground.h"

Ground::Ground(GameObject* parent) : GameObject(parent)
{

}

void Ground::start() 
{
	
	GameObject* ground1 = new GameObject(this);
	ground1->addMesh(new PlaneMesh(1000.0f,1000.0f,1.45f,glm::vec2(-30.0f,487.0f),1000.0f,1000.0f));
	ground1->transform.translate(0.0f, 0.0f, -507.0f);
	ground1->setTexture("textures/grass.png");
	GameObject* ground2 = new GameObject(this);
	ground2->addMesh(new PlaneMesh(1000.0f, 1000.0f, 1000.0f, 1000.0f));
	ground2->setTexture("textures/grass.png");
	ground2->transform.translate(0.0f, 0.0f, 497.0f);
}

void Ground::update(float delta)
{
	//just stay where you are
}