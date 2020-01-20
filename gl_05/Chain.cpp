#include "Chain.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <glm\detail\func_geometric.hpp>

Chain::Chain(GameObject* parent): GameObject(parent), lenght(100), rotation(0.0), dRotation(0.0)
{}

Chain::Chain(GameObject* parent, unsigned int lenght, float radius): GameObject(parent), lenght(lenght) , rollerRadius(radius), rotation(0.0), dRotation(0.0)
{}

void Chain::start()
{
	this->setTexture("textures/rusty.png");
	this->transform.translate(-rollerRadius+0.015-0.0025, 0.35f, 0.015f - 0.0075f);
	this->transform.rotate(0.0f, 0.0f, 92.0f);
	GameObject* begin = new GameObject(this);
	begin->addMesh(new ChLinkMesh(0.03f, 0.02f, 0.0025f));
	
	GameObject* prev = begin;
	for (auto i = 0; i < lenght - 20; ++i)
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
	prev->transform.translate(0.353f, 3.5175f - (20 - 1) * 0.02f, rollerRadius + 0.01);
	prev->transform.rotate(0.0f, 0.0f, 180.0f);
	looseState = prev;

	for (auto i = 0; i < lenght; ++i)
	{
		GameObject* link = new GameObject(prev);
		link->addMesh(new ChLinkMesh(0.03f, 0.02f, 0.0025f));
		link->transform.translate(0.0f, -0.03f + 4 * 0.0025f, 0.0f);
		link->transform.rotate(0.0f, 90.0f, 0.0f);
		prev = link;
		if (i == 18)
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

	GameObject* tmp;

	looseState->transform.setPosition(0.353f -(0.0176*rotation / 360.0f) , (3.5175f - 19 * 0.02f) - (rollerRadius + 0.01f) * 2 * M_PI * rotation / 360.0f, rollerRadius + 0.01); //50.26
	//0.353f, 3.5175f - (50 - 1) * 0.02f, rollerRadius + 0.01
	GLfloat sLen = 3.5175f - (20 - 1) * 0.02f - looseState->transform.getPosition().y;
	//std::cout << "Rozwiniecie " << sLen << std::endl;
	if (state)
	{
		stateChanger->transform.rotate(0.0f, 0.0f, dRotation);
		if (llrint(floor(sLen / 0.02f)) % 2 == 0 && dRotation >= 0)
		{
			//std::cout << "Przeskok ze state " << stateChanger->transform.getRotation().z << std::endl;
			tmp = (stateChanger);
			stateChanger = stateChanger->getParent();
			tmp->setVisible(false);

			firstLoose = firstLoose->getChildren()->front();
			firstLoose->getChildren()->front()->setVisible(false);

			toChange = 0;
			state = false;
		}
		if (llrint(floor(sLen / 0.02f)) % 2 == 0 && dRotation < 0)
		{
			tmp = stateChanger;
			stateChanger = stateChanger->getChildren()->front();
			stateChanger->setVisible(true);

			firstLoose->setVisible(false);
			firstLoose = firstLoose->getParent();
			toChange = 0;
			state = false;
		}
	}
	else
	{
		stateChanger->transform.rotate(-dRotation,0.0f,0.0f);
		if (llrint(floor(sLen / 0.02f)) % 2 == 1 && dRotation >= 0)
		{
			//std::cout << "Przeskok z !state " << stateChanger->transform.getRotation().x << std::endl;
			tmp = stateChanger;
			stateChanger = stateChanger->getParent();
			tmp->setVisible(false);

			firstLoose = firstLoose->getChildren()->front();
			firstLoose->getChildren()->front()->setVisible(false);

			toChange = 0;
			state = true;
		}
		if (llrint(floor(sLen / 0.02f)) % 2 == 1 && dRotation < 0)
		{
			tmp = stateChanger;
			stateChanger = stateChanger->getChildren()->front(); 
			stateChanger->setVisible(true);

			firstLoose->setVisible(false);
			firstLoose = firstLoose->getParent();
			toChange = 0;
			state = true;
		}
	}
}

void Chain::tellRotation(GLfloat aRotation)
{
	dRotation = aRotation;
	rotation += aRotation;
}