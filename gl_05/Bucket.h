#ifndef BUCKET_H
#define BUCKET_H

#include "GameObject.h"
#include "TubeMesh.h"
#include "CylinderMesh.h"
#include "ChLinkMesh.h"

class Bucket : public GameObject
{
public:
	Bucket(GameObject* parent);
	void start();
	void update(float delta);
private:
	int state;
};

#endif //BUCKET_H