#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <vector>
#include "Transform.h"
#include "MeshRenderer.h"
//#include "GameEngine.h"
#include "GameScene.h"
#include"Texture.h"

class GameScene;

class GameObject
{
public:
	GameObject(GameObject *parent, GameScene *scene);
	virtual ~GameObject();

	Transform transform;

	void renderObject(const glm::mat4 &parentTransform);
	void updateObject(float delta);

	void addChild(GameObject *child);
	void removeChild(GameObject *child);

	void startObject();

	virtual void render();
	virtual void update(float delta);

	virtual void start();
	virtual void destroy();

	GameScene *scene; //TODO: make it protected

protected:

	GameObject *parent;
	std::vector<GameObject*> children;
	std::vector<MeshRenderer*> meshes;

	Texture *texture;

	
};

#endif