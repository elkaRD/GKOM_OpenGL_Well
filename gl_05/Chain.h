#ifndef CHAIN_H
#define CHAIN_H

#include "GameObject.h"
#include "ChLinkMesh.h"
#include "CubeMesh.h"

class Chain : public GameObject
{
public:
	Chain(GameObject* parent);
	Chain(GameObject* parent, unsigned int lenght, float rollerRadius);

	void start();
	void update(float delta, int controll);
	void unroll(float radius);
	void tellRotation(GLfloat);
private:
	const unsigned int lenght;
	unsigned int freeLinks;

	GLfloat rollerRadius;
	float rotation;
	float dRotation;
	GLfloat toChange;

	unsigned int state;
	GameObject* stateChanger;
	GameObject* looseState;
	GameObject* firstLoose;
	GameObject* water;
};

#endif // !CHAIN_H

