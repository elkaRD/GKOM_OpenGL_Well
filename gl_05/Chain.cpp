#include "Chain.h"

Chain::Chain(GameObject* parent): GameObject(parent), lenght(100)
{}

Chain::Chain(GameObject* parent, unsigned int lenght, float radius): GameObject(parent), lenght(lenght) , rollerRadius(radius)
{}

void Chain::start()
{
	//GameObject* upper = parent;
	//while (upper != nullptr && upper->getParent() != nullptr)
	//	upper = upper->getParent();
	//globalParent = new GameObject(upper);w

	this->setTexture("textures/rusty.png");
	GameObject* begin = new GameObject(this);
	begin->addMesh(new ChLinkMesh(0.03f, 0.02f, 0.0025f));
	this->transform.setPosition(-rollerRadius, 0.0f, 0.0f);
	this->transform.rotate(0.0f, 0.0f, 90.0f);
	
	GameObject* prev = begin;
	for (auto i = 0; i < lenght; ++i)
	{
		GameObject* link = new GameObject(prev);
		link->addMesh(new ChLinkMesh(0.03f, 0.02f, 0.0025f));
		link->transform.setPosition(0.0f, 0.03f - 4 * 0.0025f, 0.0f);
		link->transform.rotate(0.0f, 90.0f, 0.0f);
		prev = link;
	}
}

void Chain::update(float delta)
{

}