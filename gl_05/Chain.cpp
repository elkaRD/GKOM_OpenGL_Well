#include "Chain.h"
#include "Bucket.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <glm\detail\func_geometric.hpp>

Chain::Chain(GameObject* parent): GameObject(parent), lenght(20), rotation(0.0), dRotation(0.0)
{}

Chain::Chain(GameObject* parent, unsigned int lenght, float radius): GameObject(parent), lenght(lenght) , rollerRadius(radius), rotation(0.0), dRotation(0.0)
{}

void Chain::start()
{
	
	this->transform.translate(-rollerRadius+0.015f-0.0025f, 0.35f, 0.015f - 0.0075f);
	this->transform.rotate(0.0f, 0.0f, 92.0f);
	GameObject* begin = new GameObject(this);
	begin->addMesh(new ChLinkMesh(0.03f, 0.02f, 0.0025f));
	
	GameObject* prev = begin;
	for (unsigned int i = 0; i < lenght - 20; ++i)
	{
		GameObject* link = new GameObject(prev);
		link->addMesh(new ChLinkMesh(0.03f, 0.02f, 0.0025f));
		link->transform.translate(0.0f, 0.03f - 4 * 0.0025f, 0.0f);
		if(i==0)
			link->transform.rotate(2.0f, 90.0f, -90.0f);
		else if(i%2==0)
		{
			link->transform.rotate(0.0f, -90.0f, -360.0f * (0.03f - 4* 0.0025f) * 0.994f / (2 * (float) M_PI * (rollerRadius + 0.01f)));//90.0 * (0.03 - 4 * 0.0025)
		}
		else
		{
			link->transform.rotate(360.0f * (0.03f - 4 * 0.0025f) * 0.994f / (2 * (float) M_PI * (rollerRadius+ 0.01f)), 90.0f, 0.0f);
		}
		link->transform.translate(0.0007f, 0.0f, 0.0f);;
		prev = link;
	}
	stateChanger = prev;

	prev = new GameObject(begin->getParent()->getParent()->getParent());
	prev->transform.translate(0.353f, 3.5175f - (20 - 1) * 0.02f, rollerRadius + 0.01f);
	prev->transform.rotate(0.0f, 0.0f, 180.0f);
	looseState = prev;
	looseState->setTexture("textures/crank.png");

	for (unsigned int i = 0; i < lenght; ++i)
	{
		GameObject* link = new GameObject(prev);
		link->addMesh(new ChLinkMesh(0.03f, 0.02f, 0.0025f));
		link->transform.translate(0.0f, -0.03f + 4 * 0.0025f, 0.0f);
		link->transform.rotate(0.0f, 90.0f, 0.0f);
		prev = link;
		if (i == 18)
			firstLoose = prev;
	}

	GameObject* bucket = new Bucket(looseState);
	bucket->transform.rotate(0.0f, 90.0f, 180.0f);
	bucket->transform.translate(0.0f, 0.6f, 0.0f);
	bucket->transform.setScale(1.5, 1.5, 1.5);

	water = new GameObject(bucket);
	water->transform.setScale(0.2, 0.08, 0.2);
	MeshRenderer* cylinder = water->addMesh(new CylinderMesh());
	cylinder->verticalInterpolationScale(0.7, 1.0);
	cylinder->setWater();
	water->setVisible(false);

	state = 0;
	toChange = 0;
	firstLoose->getChildren()->front()->setVisible(false);
	this->setTexture("textures/crank.png");
	//prev = new Bucket(looseState);
}

void Chain::update(float delta, int controll)
{
	if (controll == 0) return;

	if (rotation > 3320)
		water->setVisible(true);
	GameObject* tmp;
	looseState->transform.setPosition(0.353f -(0.0176f*rotation / 360.0f) , (3.5175f - 19 * 0.02f) - (rollerRadius + 0.01f) * 2 * (float) M_PI * rotation / 360.0f, rollerRadius + 0.01f); //50.26
	//0.353f, 3.5175f - (50 - 1) * 0.02f, rollerRadius + 0.01
	GLfloat sLen = 3.5175f - (20 - 1) * 0.02f - looseState->transform.getPosition().y;
	//std::cout << "Rozwiniecie " << sLen << std::endl;
	//if (state % 2 == 1)
	//{
	//	stateChanger->transform.rotate(0.0f, 0.0f, dRotation);
	//}
	//else
	//{
	//	stateChanger->transform.rotate(-dRotation,0.0f,0.0f);
	//}
	int stateChanges = (int) llrint(floor(sLen / 0.02f)) - state;
	while(controll == 1 && stateChanges >= 0 && dRotation >= 0)
	{
		tmp = (stateChanger);
		stateChanger = stateChanger->getParent();
		tmp->setVisible(false);

		firstLoose = firstLoose->getChildren()->front();
		firstLoose->getChildren()->front()->setVisible(false);
		firstLoose->setVisible(true);

		toChange = 0;
		--stateChanges;
		++state;
	}
	while(controll == -1 && stateChanges < 0 && dRotation < 0)
	{
		tmp = stateChanger;
		stateChanger = stateChanger->getChildren()->front();
		stateChanger->setVisible(true);

		firstLoose->setVisible(false);
		firstLoose = firstLoose->getParent();
		toChange = 0;
		++stateChanges;
		--state;
	}

}

void Chain::tellRotation(GLfloat aRotation)
{
	dRotation = aRotation;
	rotation += aRotation;
}