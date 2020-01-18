#include "TestObject.h"

TestObject::TestObject(GameObject* parent): GameObject(parent)
{

}

void TestObject::start()
{
	MeshRenderer* mesh = addMesh(new ChLinkMesh());
}

void TestObject::update(float delta)
{

}