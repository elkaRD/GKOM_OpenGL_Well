#ifndef WELL_SCENE_H
#define WELL_SCENE_H

#include "GameScene.h"
#include "Well.h"
#include "Ground.h"
#include "Lamp.h"

class WellScene : public GameScene
{
public:
	WellScene(ShaderProgram *shader);

	void start();
	void update(float delta);

private:
	GameObject *well;
	GameObject *well2;

	void createAvenue();
};

#endif