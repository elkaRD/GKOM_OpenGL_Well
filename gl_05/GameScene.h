#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include <glm/gtc/type_ptr.hpp>
#include "GameObject.h"
#include "shprogram.h"

class GameObject;

class GameScene
{
public:

	GameScene(ShaderProgram * shader);
	~GameScene();

	virtual void start();
	void render();
	virtual void update(float delta);

	ShaderProgram* getShader();

	void setTransform(glm::mat4 trans);

protected:
	GameObject *rootObject;
	ShaderProgram *shader;
};

#endif