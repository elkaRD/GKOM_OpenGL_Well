#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <vector>
#include "Transform.h"

class GameObject
{
public:
	GameObject(GameObject *parent);
	virtual ~GameObject();

	Transform transform;

	void renderObject(const glm::vec4 &parentTransform);
	void updateObject(float delta);

	void addChild(GameObject *child);
	void removeChild(GameObject *child);

	virtual void render();
	virtual void update(float delta);

	virtual void start();
	virtual void destroy();

protected:
	

private:

	GameObject *parent;
	std::vector<GameObject*> children;
};

#endif