#ifndef GROUND_H
#define GROUND_H

#include "GameObject.h"
#include "PlaneMesh.h"


class Ground : public GameObject 
{
public:
	Ground(GameObject* parent);
	void start();
	void update(float delta);
};
#endif // !GROUND_H

