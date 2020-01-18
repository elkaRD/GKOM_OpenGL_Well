#ifndef CHAIN_H
#define CHAIN_H

#include "GameObject.h"
#include "ChLinkMesh.h"

class Chain : public GameObject
{
public:
	Chain(GameObject* parent);
	Chain(GameObject* parent, unsigned int lenght, float rollerRadius);

	void start();
	void update(float delta);
	void unroll(float radius);
private:
	const unsigned int lenght;
	unsigned int freeLinks;

	GLfloat rollerRadius;
	GameObject* globalParent;
};

#endif // !CHAIN_H

