#include "Well.h"
#include "Roller.h"

Well::Well(GameObject *parent) : GameObject(parent)
{

}

void Well::start()
{
	GameObject *hole = new GameObject(this);
	hole->transform.translate(0, -12.04, 0);
	MeshRenderer *mesh = hole->addMesh(new TubeMesh());
	hole->setTexture("textures/brickwall.jpg");

	GameObject *peak = createPeak(this);
	roller = createRoller(this);
}

void Well::update(float delta)
{
	//rollTime += delta;

	//float d = 1;

	//if (rollTime < fluentActivation)
	//{
	//	float s = rollTime / fluentActivation;
	//	d = (sin(M_PI * s - M_PI / 2) + 1) / 2;
	//}
	//else if (rollTime > fullAnimationDuration - fluentActivation)
	//{
	//	float s = (rollTime - (fullAnimationDuration - fluentActivation)) / fluentActivation;
	//	d = (sin(M_PI * s + M_PI / 2) + 1) / 2;
	//}

	//if (rollTime >= fullAnimationDuration)
	//{
	//	d = 0;
	//	direction = !direction;
	//	rollTime = 0;
	//}

	//if (direction) d *= -1;

	//roller->transform.rotate(rotationSpeed * d * delta, 0, 0);
}

GameObject* Well::createStem(GameObject *parent)
{
	GameObject *stem1 = new GameObject(parent);
	stem1->transform.setPosition(0, 3, 0);
	MeshRenderer *cube = stem1->addMesh(new CubeMesh());
	cube->scaleVertices(0.2, 4, 0.2f);

	GameObject *oblique1 = new GameObject(stem1);
	oblique1->transform.setRotation(45, 0, 0);
	oblique1->transform.setPosition(0, 1.6, -0.5f);
	cube = oblique1->addMesh(new CubeMesh());
	cube->scaleVertices(0.23, 1.2, 0.32f);

	GameObject *oblique2 = new GameObject(stem1);
	oblique2->transform.setRotation(-45, 0, 0);
	oblique2->transform.setPosition(0, 1.6, 0.5f);
	cube = oblique2->addMesh(new CubeMesh());
	cube->scaleVertices(0.23, 1.2, 0.32f);

	GameObject *smallerOblique1 = new GameObject(stem1);
	smallerOblique1->transform.setRotation(45, 0, 0);
	smallerOblique1->transform.setPosition(0, 1.3, 0.4f);
	cube = smallerOblique1->addMesh(new CubeMesh());
	cube->scaleVertices(0.12, 1.1, 0.12f);

	GameObject *smallerOblique2 = new GameObject(stem1);
	smallerOblique2->transform.setRotation(-45, 0, 0);
	smallerOblique2->transform.setPosition(0, 1.3, -0.4f);
	cube = smallerOblique2->addMesh(new CubeMesh());
	cube->scaleVertices(0.12, 1.1, 0.12f);

	return stem1;
}

GameObject* Well::createPeak(GameObject *parent)
{
	GameObject *pivot = new GameObject(parent);

	GameObject *stem1 = createStem(pivot);
	stem1->transform.translate(-1.6, 0, 0);

	GameObject *stem2 = createStem(pivot);
	stem2->transform.translate(1.6, 0, 0);

	GameObject *horizontal = new GameObject(pivot);
	horizontal->transform.setRotation(-45, 0, 0);
	horizontal->transform.setPosition(0, 5.1, 0);
	MeshRenderer *cube = horizontal->addMesh(new CubeMesh());
	cube->scaleVertices(4.2, 0.32, 0.32);

	GameObject *peak1 = new GameObject(pivot);
	peak1->transform.setRotation(-45, 0, 0);
	peak1->transform.setPosition(0, 4.8, -0.6);
	cube = peak1->addMesh(new CubeMesh());
	cube->scaleVertices(4.5, 0.11, 1.6);

	GameObject *peak2 = new GameObject(pivot);
	peak2->transform.setRotation(45, 0, 0);
	peak2->transform.setPosition(0, 4.8, 0.6);
	cube = peak2->addMesh(new CubeMesh());
	cube->scaleVertices(4.5, 0.11, 1.6);

	GameObject *middlePeak = new GameObject(pivot);
	middlePeak->transform.rotate(0, 0, 90);
	middlePeak->transform.translate(0, 5.4, 0);
	MeshRenderer *mesh = middlePeak->addMesh(new CylinderMesh());
	mesh->scaleVertices(0.1f, 0.95f, 0.1f);

	return pivot;
}

GameObject* Well::createRoller(GameObject *parent)
{
	Roller* roller = new Roller(this);
	roller->setTexture("textures/rollerTex.png");
	roller->transform.translate(0, 3.5, 0);


	//horizontal->transform.rotate(0, 0, 90);
	//horizontal->transform.translate(0.5f, 0, 0);
	//MeshRenderer *mesh = horizontal->addMesh(new CylinderMesh());
	//mesh->scaleVertices(0.08f, 0.8, 0.08f);

	//GameObject *thicker = new GameObject(horizontal);
	//thicker->transform.translate(0,0.5,0);
	//mesh = thicker->addMesh(new CylinderMesh());
	//mesh->scaleVertices(0.2f, 0.32, 0.2f);

	//GameObject *vertical = new GameObject(horizontal);
	//vertical->transform.translate(-0.4, -2, 0);
	//mesh = vertical->addMesh(new CubeMesh());
	//mesh->scaleVertices(1.1f, 0.08, 0.17f);

	//GameObject *handle = new GameObject(vertical);
	//handle->transform.translate(-0.4,-0.21,0);
	//mesh = handle->addMesh(new CylinderMesh());
	//mesh->scaleVertices(0.06f, 0.1, 0.06f);

	return roller;
}