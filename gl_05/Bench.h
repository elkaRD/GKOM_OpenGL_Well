#ifndef BENCH_H

#include "GameObject.h"
#include "CubeMesh.h"

class Bench : public GameObject
{
public:
	Bench(GameObject* parent);
	void start();
	void update(float delta);
private:
	float width;
};

#endif // !BENCH_H
