#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "GameObject.h"

class GameScene
{
public:

	GameScene();
	~GameScene();

	void start();
	void render();
	void update(float delta);

private:
	GameObject *rootObject;
};

#endif