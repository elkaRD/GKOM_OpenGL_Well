#include "TestObject.h"

TestObject::TestObject(GameObject* parent): GameObject(parent)
{

}

void TestObject::start()
{
	MeshRenderer* mesh = addMesh(new TubeMesh());
}

void TestObject::update(float delta)
{

}