#ifndef WELL_SCENE_H
#define WELL_SCENE_H

#include "GameScene.h"
#include "Well.h"
#include "Ground.h"
#include "Lamp.h"
#include "TestObject.h"
#include "Tree.h"

class WellScene : public GameScene
{
public:
	WellScene(ShaderProgram *shader, ShaderProgram *shader2, ShaderProgram *shader3);

	void start();
	void update(float delta);

private:
	GameObject *well;
	GameObject *well2;

	void createAvenue();
	void testObject();
};

#endif