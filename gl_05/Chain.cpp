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
		if (i == lenght - 51)
		{
			prev->setTexture("textures/iipw.png");
		}
		if (i == lenght - 50)
		{
			prev->setTexture("textures/rusty.png");
		}
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
		link->transform.translate(0.0007, 0.0f, 0.0f);
		//links.push_back(prev);
		prev = link;
	}
	//links.push_back(prev);
	stateChanger = prev; //--links.end();

	prev = new GameObject(begin->getParent()->getParent()->getParent());
	prev->transform.translate(0.35f, 3.5175f - (50 - 1) * 0.02f, rollerRadius + 0.01);
	prev->transform.rotate(0.0f, 0.0f, 180.0f);
	//links.push_back(prev);
	//looseState = --links.end();
	looseState = prev;
	//(*looseState)->addMesh(new CubeMesh(0.01f, 0.01f, 0.01f));

	

	for (auto i = 0; i < lenght; ++i)
	{
		GameObject* link = new GameObject(prev);
		link->addMesh(new ChLinkMesh(0.03f, 0.02f, 0.0025f));
		link->transform.translate(0.0f, -0.03f + 4 * 0.0025f, 0.0f);
		link->transform.rotate(0.0f, 90.0f, 0.0f);
		prev = link;
		//links.push_back(prev);
		if(i == 48)
			link->setTexture("textures/weiti.png");
		if (i == 49)
			firstLoose = prev;// --links.end();
		if (i >= 49)
			link->setVisible(false);
	}

	//hook = new GameObject(prev);
	//hook->addMesh(new CubeMesh(0.01f, 0.01f, 0.01f));
	//hook->transform.translate(0.0f, -0.03f + 4 * 0.0025f, 0.0f);
	lastRotation = rotation;
	state = false;
	toChange = 0;
	//std::cout << links.size() << std::endl;
}

void Chain::update(float delta)
{
	//GLfloat dRot = rotation - lastRotation;
	toChange += 2 * M_PI * (rollerRadius /*+ 0.0725f*/) * (rotation*delta / 360.0f);
	GameObject* tmp = looseState;
	tmp->transform.translate(0.0f, -2 * M_PI * (rollerRadius + 0.01f)  * (rotation * delta / 360.0f), 0.0f);
	//	-sin(glm::radians(2.0f)) * 2 * M_PI * rollerRadius * dRot / 360.0f
	
	if (state)
	{
		stateChanger->transform.rotate(0.0f, 0.0f, rotation * delta);
		if (toChange > 0.02f)
		{
			tmp = (stateChanger);
			stateChanger = stateChanger->getParent();
			tmp->setVisible(false);

			//firstLoose = firstLoose->getChildren();
			firstLoose->setVisible(true);

			toChange = 0;
			state = false;
		}
	}
	else
	{
		stateChanger->transform.rotate(-rotation * delta, 0.0f, 0.0f);
		if (toChange > 0.02f)
		{
			tmp = stateChanger;
			stateChanger = stateChanger->getParent();
			tmp->setVisible(false);
			firstLoose = firstLoose->getChildren()->front();
			std::cout << firstLoose->visible << std::endl;
			firstLoose->setVisible(true);
			std::cout << firstLoose->visible << std::endl;
			toChange = 0;
			state = true;
		}
	}

	lastRotation = rotation;
}

void Chain::tellRotation(GLfloat aRotation)
{
	rotation = aRotation;
}