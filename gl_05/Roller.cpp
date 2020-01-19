#include "Roller.h"

Roller::Roller(GameObject* parent, GLfloat radius, GLfloat height): GameObject(parent), radius(radius), height(height)
{}

Roller::Roller(GameObject* parent): Roller(parent, 0.15f, 2.0f)
{}

void Roller::start()
{
	GameObject* thick = new GameObject(this);
	thick->transform.rotate(0.0f, 0, 90.0f);
	MeshRenderer* thickMesh = new CylinderMesh(radius, height);
	thick->addMesh(thickMesh);
	thick->addMesh(new CylinderMesh(radius / 4, height * 1.2 + 0.5));

	GameObject* crank = new GameObject(thick);
	crank->setTexture("textures/crank.png");
	crank->transform.translate(0.35f-radius/4, -height*0.6 - 0.25, 0.0f);
	crank->addMesh(new CubeMesh(0.7f, 0.075f, radius/2));

	chain = new Chain(this, 2060, radius);
	thick->addChild(chain);
	chain->tellRotation(transform.getRotation().x);
}

void Roller::update(float delta)
{
	//transform.rotate(5.0f * delta, 0.0f, 0.0f);
	chain->tellRotation(transform.getRotation().x);
}

GLfloat Roller::getRadius() const
{
	return radius;
}

GLfloat Roller::getHeight() const
{
	return height;
}