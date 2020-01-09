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
	virtual ~GameScene();

	virtual void start();
	void render();
	virtual void update(float delta);
	void updateScene(float delta);

	ShaderProgram* getShader();

	void setTransform(glm::mat4 trans);

protected:
	GameObject *rootObject;
	ShaderProgram *shader;

	GameObject* generateObject();
	GameObject* generateObject(GameObject *parent);
	void cleanObjects();

	void registerObject(GameObject *gameObject);

private:
	std::vector<GameObject*> gameObjects;
	std::vector<GameObject*> toStart;
};

#endif