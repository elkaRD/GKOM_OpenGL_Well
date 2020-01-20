#include "Roller.h"

Roller::Roller(GameObject* parent, GLfloat radius, GLfloat height): GameObject(parent), radius(radius), height(height), maxAngle(10800.0), minAngle(-0.00001)
{}

Roller::Roller(GameObject* parent): Roller(parent, 0.15f, 2.0f)
{}

void Roller::start()
{
	GameObject* thick = new GameObject(this);
	thick->transform.rotate(0.0f, 0, 90.0f);
	MeshRenderer* thickMesh = new CylinderMesh(radius, height);
	thick->addMesh(thickMesh);
	
	GameObject* thin = new GameObject(thick);
	MeshRenderer* thinMesh = new CylinderMesh(radius / 4, height * 1.2 + 0.35);
	thin->transform.translate(0.0f, -0.1f, 0.0f);
	thin->addMesh(thinMesh);

	GameObject* crank = new GameObject(thick);
	crank->setTexture("textures/crank.png");
	crank->transform.translate(-0.35f+radius/4, -height*0.6 - 0.25, 0.0f);
	crank->addMesh(new CubeMesh(0.7f, 0.045f, radius/2));

	GameObject* crank2 = new GameObject(thick);
	crank2->setTexture("textures/rollerTex.png");
	crank2->transform.translate(-0.63, -height * 0.6 - 0.4f, 0.0f);
	crank2->addMesh(new CylinderMesh(radius/6, 0.3f));

	chain = new Chain(this, 2030, radius);
	thick->addChild(chain);
	chain->tellRotation(transform.getRotation().x);
	angle = 0;
	speed = 0.0f;
}

void Roller::update(float delta)
{
	//if(speed< 18.0f && speed >= 0.0f)
	if(speed >= 0)
		speed = 360.0f;
	if (speed < 0.0f)
		speed = -360.0f;
		
	//speed = 0;
	//if (speed >= 180.0f)
	//	speed = 180.0f;
	//if (speed < 0)
	//	speed = -1.0f;

	if (angle + speed * delta >= maxAngle && speed > 0.0f)
		speed = -0.01f;

	if (angle + speed * delta <= minAngle && speed < 0.0f)
		speed = 0.0f;

	transform.rotate(speed * delta, 0.0f, 0.0f);
	chain->tellRotation(speed * delta);
	angle += speed * delta;
		
}

GLfloat Roller::getRadius() const
{
	return radius;
}

GLfloat Roller::getHeight() const
{
	return height;
}