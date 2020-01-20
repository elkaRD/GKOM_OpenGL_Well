#include "Well.h"
#include "Roller.h"
#include "Bucket.h"

Well::Well(GameObject *parent) : GameObject(parent)
{

}

void Well::start()
{
	this->transform.translate(0.0f, -1.1f, 0.0f);
	GameObject *hole = new GameObject(this);
	hole->transform.translate(0, -12.04f, 0);
	MeshRenderer *mesh = hole->addMesh(new TubeMesh());
	hole->setTexture("textures/brickwall.jpg");

	GameObject* stem1 = new GameObject(hole);
	stem1->transform.setPosition(0, 3, 0);
	MeshRenderer* cube = stem1->addMesh(new CylinderMesh());
	cube->setWater();

	GameObject *peak = createPeak(this);
	peak->setTexture("textures/wood.png");
	roller = createRoller(this);

	GameObject* bucket = new Bucket(this);
	bucket->transform.setPosition(-1.6f, 1.5f, 1.0f);
	bucket->transform.setScale(1.5, 1.5, 1.5);

	GameObject* bed = new GameObject(hole);
	bed->addMesh(new CubeMesh(3.0f, 0.1f, 3.0f));
	bed->transform.translate(0.0f, -15.0f, 0.0f);
}

void Well::update(float delta)
{

}

GameObject* Well::createStem(GameObject *parent)
{
	GameObject *stem1 = new GameObject(parent);
	stem1->transform.setPosition(0, 3, 0);
	MeshRenderer *cube = stem1->addMesh(new CubeMesh());
	cube->scaleVertices(0.2f, 4, 0.2f);
	stem1->setTexture("textures/wood1.png");

	GameObject *smallerOblique1 = new GameObject(stem1);
	smallerOblique1->transform.setRotation(45, 0, 0);
	smallerOblique1->transform.setPosition(0, 1.3f, 0.4f);
	cube = smallerOblique1->addMesh(new CubeMesh());
	cube->scaleVertices(0.12f, 1.1f, 0.12f);

	GameObject *smallerOblique2 = new GameObject(stem1);
	smallerOblique2->transform.setRotation(-45, 0, 0);
	smallerOblique2->transform.setPosition(0, 1.3f, -0.4f);
	cube = smallerOblique2->addMesh(new CubeMesh());
	cube->scaleVertices(0.12f, 1.1f, 0.12f);

	GameObject *oblique1 = new GameObject(stem1);
	oblique1->transform.setRotation(54, 0, 0);
	oblique1->transform.setPosition(0, 1.8f, -0.5f);
	cube = oblique1->addMesh(new CubeMesh());
	cube->scaleVertices(0.23f, 1.2f, 0.32f);

	GameObject *oblique2 = new GameObject(stem1);
	oblique2->transform.setRotation(-54, 0, 0);
	oblique2->transform.setPosition(0, 1.8f, 0.5f);
	cube = oblique2->addMesh(new CubeMesh());
	cube->scaleVertices(0.23f, 1.2f, 0.32f);

	return stem1;
}

GameObject* Well::createPeak(GameObject *parent)
{
	GameObject *pivot = new GameObject(parent);

	GameObject *stem1 = createStem(pivot);
	stem1->transform.translate(-1.17f, 0, 0);

	GameObject *stem2 = createStem(pivot);
	stem2->transform.translate(1.17f, 0, 0);

	GameObject *peak1 = new GameObject(pivot);
	peak1->transform.setRotation(-36, 0, 0);
	peak1->transform.setPosition(0, 4.85f, -0.7f);
	MeshRenderer *cube = peak1->addMesh(new CubeMesh());
	cube->scaleVertices(3.29f, 0.15f, 1.7f);
	peak1->setTexture("textures/wood.png");

	GameObject *peak2 = new GameObject(pivot);
	peak2->transform.setRotation(36, 0, 0);
	peak2->transform.setPosition(0, 4.85f, 0.7f);
	cube = peak2->addMesh(new CubeMesh());
	cube->scaleVertices(3.29f, 0.15f, 1.7f);

	GameObject *middlePeak = new GameObject(pivot);
	middlePeak->transform.rotate(0, 0, 90);
	middlePeak->transform.translate(0, 5.37f, 0);
	MeshRenderer *mesh = middlePeak->addMesh(new CylinderMesh());
	mesh->scaleVertices(0.12f, 0.75f, 0.12f);
	middlePeak->setTexture("textures/rollerTex.png");

	GameObject *horizontal = new GameObject(pivot);
	horizontal->transform.setRotation(-45, 0, 0);
	horizontal->transform.setPosition(0, 5.12f, 0);
	cube = horizontal->addMesh(new CubeMesh());
	cube->scaleVertices(3.07f, 0.32f, 0.32f);
	horizontal->setTexture("textures/wood1.png");

	return pivot;
}

GameObject* Well::createRoller(GameObject *parent)
{
	Roller* roller = new Roller(this);
	roller->setTexture("textures/rollerTex.png");
	roller->transform.translate(0, 3.5, 0);

	return roller;
}