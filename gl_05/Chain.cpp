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
	//GameObject* upper = parent;
	//while (upper != nullptr && upper->getParent() != nullptr)
	//	upper = upper->getParent();
	//globalParent = new GameObject(upper);
	std::cout << "Chain starting" << std::endl;
	this->setTexture("textures/rusty.png");
	this->transform.translate(-rollerRadius+0.015-0.0025, 0.0f, 0.015f - 0.0075f);
	this->transform.rotate(0.0f, 0.0f, 90.0f);
	GameObject* begin = new GameObject(this);
	begin->addMesh(new ChLinkMesh(0.03f, 0.02f, 0.0025f));
	
	GameObject* prev = begin;
	for (auto i = 0; i < lenght; ++i)
	{
		GameObject* link = new GameObject(prev);
		link->addMesh(new ChLinkMesh(0.03f, 0.02f, 0.0025f));
		link->transform.translate(0.0f, 0.03f - 4 * 0.0025f, 0.0f);
		if(i==0)
			link->transform.rotate(2.0f, 90.0f, -90.0f);
		else if(i%2==0)
		{
			link->transform.rotate(2.0f, -90.0f, -360.0 * (0.03f - 4* 0.0025f) / (2 * M_PI * (rollerRadius + 0.01f)));//90.0 * (0.03 - 4 * 0.0025)
		}
		else
		{
			link->transform.rotate(360.0 * (0.03f - 4 * 0.0025f) / (2 * M_PI * (rollerRadius+ 0.01f)), 90.0f, -2.0f);
		}
		prev = link;
	}

	//GameObject* prev = begin;
	//for (auto i = 0; i < lenght; ++i)
	//{
	//	GameObject* link = new GameObject(prev);
	//	link->addMesh(new ChLinkMesh(0.03f, 0.02f, 0.0025f));
	//	link->transform.translate(0.0f, 0.03f - 4 * 0.0025f, 0.0f);
	//	link->transform.rotate(0.0f, 90.0f, 0.0f);
	//	prev = link;
	//}
}

void Chain::update(float delta)
{

}