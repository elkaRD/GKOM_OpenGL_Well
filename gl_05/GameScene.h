#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include <glm/gtc/type_ptr.hpp>
#include "GameObject.h"
#include "shprogram.h"

class GameObject;

class GameScene
{
public:

	GameScene(ShaderProgram * shader, ShaderProgram * shader2);
	virtual ~GameScene();

	void startScene();
	void destroyScene();
	void updateScene(float delta);

	virtual void start();
	void render();
	virtual void update(float delta);
	virtual void destroy();

	ShaderProgram* getShader();
	ShaderProgram* getShader2();

	void setTransform(glm::mat4 trans);
	void registerObject(GameObject *gameObject);

	GameObject* getRoot();

protected:
	GameObject *rootObject;
	ShaderProgram *shader;
	ShaderProgram *shader2;

	int randomInt(int min, int max) const;
	float randomFloat(float min, float max) const;

private:
	std::vector<GameObject*> gameObjects;
};

#endif