#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include "Transform.h"
#include "MeshRenderer.h"
#include "GameScene.h"
#include"Texture.h"

#define M_PI       3.14159265358979323846

class GameScene;

class GameObject
{
public:
	GameObject(GameObject *parent);
	GameObject(GameScene *scene);
	virtual ~GameObject();

	Transform transform;

	void startObject();
	void destroyObject();
	void renderObject(const glm::mat4& parentTransform, ShaderProgram* shader, ShaderProgram* shader2, ShaderProgram* shader3, GLuint cubemapTexture);
	void updateObject(float delta, GLint controll);
	void setVisible(bool isVisible);

	void addChild(GameObject *child);
	void removeChild(GameObject *child);

	MeshRenderer* addMesh(MeshRenderer *mesh);
	void setTexture(const char *fileName);

	virtual void start();
	virtual void destroy();
	virtual void render();
	virtual void update(float delta);
	virtual void update(float delta, GLint controll);

	GameObject* getParent();
	void setParent(GameObject* parent);
	GameObject* GameObject::getRoot();

	//for chain animation
	std::vector<GameObject*>* getChildren();
	bool visible;
private:
	Texture *texture;
	std::vector<MeshRenderer*> meshes;
	bool firstUpdate = true;
	

protected:
	GameObject *parent;
	GameScene *scene;

	std::vector<GameObject*> children;

	int randomInt(int min, int max) const;
	float randomFloat(float min, float max) const;
};

#endif