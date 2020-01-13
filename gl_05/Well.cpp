#include "Well.h"

Well::Well(GameObject *parent) : GameObject(parent)
{

}

void Well::start()
{
	GameObject *hole = new GameObject(this);
	hole->transform.translate(0, -12.04, 0);
	MeshRenderer *mesh = hole->addMesh(new TubeMesh());
	hole->setTexture("textures/brickwall.jpg");

	GameObject *stem1 = createStem();
	stem1->transform.translate(-1.6, 0, 0);

	GameObject *stem2 = createStem();
	stem2->transform.translate( 1.6, 0, 0);
}

void Well::update(float delta)
{

}

GameObject* Well::createStem()
{
	GameObject *stem1 = new GameObject(this);
	stem1->transform.setPosition(0, 3, 0);
	MeshRenderer *cube = stem1->addMesh(new CubeMesh());
	//cube->verticalInterpolationScale(1.2f, 0.3f);
	cube->scaleVertices(0.2, 4, 0.2f);

	GameObject *oblique1 = new GameObject(stem1);
	oblique1->transform.setRotation(45, 0, 0);
	oblique1->transform.setPosition(0, 1.6, -0.5f);
	cube = oblique1->addMesh(new CubeMesh());
	//cube->verticalInterpolationScale(1.2f, 0.3f);
	cube->scaleVertices(0.23, 1.2, 0.23f);

	GameObject *oblique2 = new GameObject(stem1);
	oblique2->transform.setRotation(-45, 0, 0);
	oblique2->transform.setPosition(0, 1.6, 0.5f);
	cube = oblique2->addMesh(new CubeMesh());
	//cube->verticalInterpolationScale(1.2f, 0.3f);
	cube->scaleVertices(0.23, 1.2, 0.23f);

	return stem1;
}