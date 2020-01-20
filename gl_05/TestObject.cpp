#include "TestObject.h"

TestObject::TestObject(GameObject* parent): GameObject(parent)
{

}

void TestObject::start()
{
	MeshRenderer* mesh = addMesh(new CubeMesh());

	GameObject* backPannel = new GameObject(this);
	backPannel->setTexture("textures/weiti.png");
	backPannel->transform.rotate(90.0f, 0.0f, 0.0f);
	backPannel->transform.translate(0.0f, 0.0f, -1.0f);
	backPannel->addMesh(new ChLinkMesh(3.0f, 2.0f, 0.25f));
}

void TestObject::update(float delta)
{

}