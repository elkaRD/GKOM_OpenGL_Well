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

	void startScene();
	void destroyScene();
	void updateScene(float delta);

	virtual void start();
	void render();
	virtual void update(float delta);
	virtual void destroy();

	ShaderProgram* getShader();

	void setTransform(glm::mat4 trans);
	void registerObject(GameObject *gameObject);

protected:
	GameObject *rootObject;
	ShaderProgram *shader;

private:
	std::vector<GameObject*> gameObjects;
};

#endif