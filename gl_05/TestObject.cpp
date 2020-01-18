#include "TestObject.h"

TestObject::TestObject(GameObject* scene): GameObject(parent)
{

}

void TestObject::start()
{
	GameObject* base1 = new GameObject(this);
	base1->transform.translate(0, 0.1f, 0);
	MeshRenderer* mesh = base1->addMesh(new CubeMesh());
	mesh->verticalInterpolationScale(1.0f, 0.6f);
	mesh->scaleVertices(1, .2f, 1);
}

void TestObject::update(float delta)
{

}