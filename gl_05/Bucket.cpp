#include "Bucket.h"

Bucket::Bucket(GameObject* parent) : GameObject(parent), state(0)
{

}

void Bucket::start()
{
	GameObject* bucket1 = new GameObject(this);
	MeshRenderer* mesh1 = new TubeMesh(0.2, 0.005, 0.4);
	bucket1->addMesh(mesh1);
	mesh1->verticalInterpolationScale(0.8, 1.0);

	GameObject* bucket2 = new GameObject(this);
	MeshRenderer* mesh2 = new CylinderMesh(0.16f, 0.005);
	bucket2->addMesh(mesh2);
	bucket2->transform.setPosition(0.0f, -0.2, 0.0f);

	GameObject* bucket3 = new GameObject(this);
	MeshRenderer* mesh3 = new TubeMesh(0.16, 0.005, 0.03);
	bucket3->addMesh(mesh3);
	mesh3->verticalInterpolationScale(1.04, 1.0);
	bucket3->transform.setPosition(0.0f, -0.215, 0.0f);

	GameObject* handler1 = new GameObject(this);
	MeshRenderer* mesh4 = new ChLinkMesh(0.03, 0.03, 0.005);
	handler1->transform.setPosition(0.0, 0.205, -0.2);
	handler1->addMesh(mesh4);

	GameObject* handler2 = new GameObject(this);
	MeshRenderer* mesh5 = new ChLinkMesh(0.03, 0.03, 0.005);
	handler2->transform.setPosition(0.0, 0.205, 0.2);
	handler2->addMesh(mesh5);

	GameObject* handler = new GameObject(this);
	MeshRenderer* mesh6 = new CylinderMesh(1);
	handler->transform.setPosition(0.0, 0.205, 0.0);
	handler->transform.rotate(0.0f, 90.0f, 90.0f);
	handler->addMesh(mesh6);


	this->setTexture("textures/ocynk.png");

}

void Bucket::update(float delta)
{

}