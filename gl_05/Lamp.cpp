#include "Lamp.h"

Lamp::Lamp(GameObject *parent) : GameObject(parent)
{

}

void Lamp::start()
{
	GameObject *base1 = new GameObject(this);
	base1->transform.translate(0, 0.1f, 0);
	MeshRenderer *mesh = base1->addMesh(new CubeMesh());
	mesh->verticalInterpolationScale(1.0f, 0.6f);
	mesh->scaleVertices(1, .2f, 1);

	GameObject *base2 = new GameObject(base1);
	base2->transform.translate(0, 0.45f, 0);
	mesh = base2->addMesh(new CylinderMesh());
	mesh->verticalInterpolationScale(1.2, 0.7f);
	mesh->scaleVertices(0.2f, 0.15f, 0.2f);

	GameObject *base3 = new GameObject(base2);
	base3->transform.translate(0, 0.4f, 0);
	mesh = base3->addMesh(new CylinderMesh());
	//mesh->verticalInterpolationScale(1, 0.5f);
	mesh->scaleVertices(0.18f, 0.015f, 0.18f);

	GameObject *base4 = new GameObject(base3);
	base4->transform.translate(0, 1.5f, 0);
	mesh = base4->addMesh(new CylinderMesh());
	//mesh->verticalInterpolationScale(1, 0.5f);
	mesh->scaleVertices(0.12f, 0.7f, 0.12f);

	GameObject *base5 = new GameObject(base4);
	base5->transform.translate(0, 2, 0);
	mesh = base5->addMesh(new CubeMesh());
	mesh->verticalInterpolationScale(0.5f, 0.8f);
	mesh->scaleVertices(0.9f);
	//mesh->scaleVertices(0.12f, 0.55f, 0.12f);

	GameObject *base6 = new GameObject(base5);
	base6->transform.translate(0, 0.5f, 0);
	mesh = base6->addMesh(new CubeMesh());
	mesh->verticalInterpolationScale(1.3f, 0);
	mesh->scaleVertices(0.9f);
	mesh->scaleVertices(1, 0.4f, 1);
}

void Lamp::update(float delta)
{

}