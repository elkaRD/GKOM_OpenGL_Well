#include "Chain.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <glm\detail\func_geometric.hpp>

Chain::Chain(GameObject* parent): GameObject(parent), lenght(100)
{}

Chain::Chain(GameObject* parent, unsigned int lenght, float radius): GameObject(parent), lenght(lenght) , rollerRadius(radius)
{}

void Chain::start()
{
	this->setTexture("textures/rusty.png");
	this->transform.translate(-rollerRadius+0.015-0.0025, 0.35f, 0.015f - 0.0075f);
	this->transform.rotate(0.0f, 0.0f, 92.0f);
	GameObject* begin = new GameObject(this);
	begin->addMesh(new ChLinkMesh(0.03f, 0.02f, 0.0025f));
	
	GameObject* prev = begin;
	for (auto i = 0; i < lenght - 50; ++i)
	{
		GameObject* link = new GameObject(prev);
		link->addMesh(new ChLinkMesh(0.03f, 0.02f, 0.0025f));
		link->transform.translate(0.0f, 0.03f - 4 * 0.0025f, 0.0f);
		if(i==0)
			link->transform.rotate(2.0f, 90.0f, -90.0f);
		else if(i%2==0)
		{
			link->transform.rotate(0.0f, -90.0f, -360.0 * (0.03f - 4* 0.0025f) * 0.994f / (2 * M_PI * (rollerRadius + 0.01f)));//90.0 * (0.03 - 4 * 0.0025)
		}
		else
		{
			link->transform.rotate(360.0 * (0.03f - 4 * 0.0025f) * 0.994f / (2 * M_PI * (rollerRadius+ 0.01f)), 90.0f, 0.0f);
		}
		link->transform.translate(0.0007, 0.0f, 0.0f);;
		prev = link;
	}
	stateChanger = prev;

	prev = new GameObject(begin->getParent()->getParent()->getParent());
	prev->transform.translate(0.353f, 3.5175f - (50 - 1) * 0.02f, rollerRadius + 0.01);
	prev->transform.rotate(0.0f, 0.0f, 180.0f);
	looseState = prev;

	for (auto i = 0; i < lenght; ++i)
	{
		GameObject* link = new GameObject(prev);
		link->addMesh(new ChLinkMesh(0.03f, 0.02f, 0.0025f));
		link->transform.translate(0.0f, -0.03f + 4 * 0.0025f, 0.0f);
		link->transform.rotate(0.0f, 90.0f, 0.0f);
		prev = link;
		if (i == 48)
			firstLoose = prev;
	}

	//hook = new GameObject(prev);
	//hook->addMesh(new CubeMesh(0.01f, 0.01f, 0.01f));
	//hook->transform.translate(0.0f, -0.03f + 4 * 0.0025f, 0.0f);
	state = false;
	toChange = 0;
	firstLoose->getChildren()->front()->setVisible(false);
}

void Chain::update(float delta)
{
	firstLoose->setVisible(true);
	
	float changeDelta = 2 * M_PI * (rollerRadius + 0.01f) * (rotation / 360.0f);

	toChange += changeDelta * delta;
	GameObject* tmp = looseState;
	looseState->transform.translate(0.0007f * changeDelta / 2 * M_PI * rollerRadius, -changeDelta * delta, 0.0f);
	
	if (state)
	{
		stateChanger->transform.rotate(0.0f, 0.0f, rotation * delta);
		if (toChange  >= rollerRadius * M_PI * 2 / 50.76)
		{
			tmp = (stateChanger);
			stateChanger = stateChanger->getParent();
			tmp->setVisible(false);

			firstLoose = firstLoose->getChildren()->front();
			firstLoose->getChildren()->front()->setVisible(false);

			toChange = 0;
			state = false;
		}
	}
	else
	{
		stateChanger->transform.rotate(-rotation * delta, 0.0f, 0.0f);
		if (toChange >= rollerRadius * M_PI * 2 / 50.76)
		{
			tmp = stateChanger;
			stateChanger = stateChanger->getParent();
			tmp->setVisible(false);

			firstLoose = firstLoose->getChildren()->front();
			firstLoose->getChildren()->front()->setVisible(false);

			toChange = 0;
			state = true;
		}
	}
}

void Chain::tellRotation(GLfloat aRotation)
{
	rotation = aRotation;
}