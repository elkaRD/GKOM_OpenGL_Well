#include "TestObject.h"

TestObject::TestObject(GameObject* parent): GameObject(parent)
{

}

void TestObject::start()
{
	MeshRenderer* mesh = addMesh(new ChLinkMesh());

	GameObject* backPannel = new GameObject(this);
	backPannel->setTexture("textures/weiti.png");
	backPannel->transform.rotate(90.0f, 0.0f, 0.0f);
	backPannel->transform.translate(0.0f, 0.0f, -1.0f);
	backPannel->addMesh(new PlaneMesh(3.0f, 5.0f, 1.0f, 1.0f));
}

void TestObject::update(float delta)
{

}