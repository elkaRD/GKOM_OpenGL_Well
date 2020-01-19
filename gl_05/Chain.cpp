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
	std::cout << "Chain starting" << std::endl;
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
			link->transform.rotate(2.0f, -90.0f, -360.0 * (0.03f - 4* 0.0025f) * 0.994f / (2 * M_PI * (rollerRadius + 0.01f)));//90.0 * (0.03 - 4 * 0.0025)
		}
		else
		{
			link->transform.rotate(360.0 * (0.03f - 4 * 0.0025f) * 0.994f / (2 * M_PI * (rollerRadius+ 0.01f)), 90.0f, -2.0f);
		}
		prev = link;
	}

	stateChanger = prev;
	//prev->setTexture("textures/iipw.png");

	looseState = new GameObject(begin->getParent()->getParent()->getParent());
	//looseState->addMesh(new CubeMesh(0.01f, 0.01f, 0.01f));
	looseState->transform.translate(0.35f, 3.52f, rollerRadius + 0.01);
	prev = looseState;

	for (auto i = 0; i < 50; ++i)
	{
		GameObject* link = new GameObject(prev);
		if (prev == looseState)
			firstLoose = link;
		link->addMesh(new ChLinkMesh(0.03f, 0.02f, 0.0025f));
		link->transform.translate(0.0f, -0.03f + 4 * 0.0025f, 0.0f);
		link->transform.rotate(0.0f, 90.0f, 0.0f);
		prev = link;
	}

	hook = new GameObject(prev);
	hook->addMesh(new CubeMesh(0.01f, 0.01f, 0.01f));
	hook->transform.translate(0.0f, -0.03f + 4 * 0.0025f, 0.0f);
	lastRotation = rotation;
	state = false;
}

void Chain::update(float delta)
{
	GLfloat dRot = rotation - lastRotation;
	toChange = -2 * M_PI * rollerRadius * dRot / 360.0f;
	looseState->transform.translate(-sin(glm::radians(2.0f)) * 2 * M_PI * rollerRadius * dRot / 360.0f, toChange, 0.0f);
	if (toChange < 0.03f - 0.01f)
		toChange = 0;
	GameObject* tmp;
	if (state)
	{
		stateChanger->transform.rotate(0.0f, 0.0f, dRot);
		if (stateChanger->transform.getRotation().z >= 180)
		{
			//stateChanger->transform.setRotation(0.0f, 90.0f, 0.0f);
			tmp = stateChanger;
			stateChanger = stateChanger->getParent();
			
			//stateChanger->transform.rotate(2.0f, 0.0f, rotation + 9.5f);
			state = false;
		}
	}
	else
	{
		stateChanger->transform.rotate(-dRot, 0.0f, 0.0f);
		if (stateChanger->transform.getRotation().x <= 0)
		{
			//stateChanger->transform.setRotation(0.0f, 90.0f, 0.0f);
			tmp = stateChanger;
			stateChanger = stateChanger->getParent();
			//stateChanger->transform.rotate(rotation + 9.5f, 0.0f, 2.0f);
			state = true;
		}
	}

	lastRotation = rotation;
}

void Chain::tellRotation(GLfloat aRotation)
{
	rotation = aRotation;
}