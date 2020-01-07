#include "GameObject.h"

GameObject::GameObject(GameObject* parent) : parent(parent)
{
	if (parent != nullptr)
		parent->addChild(this);
}

GameObject::~GameObject()
{
	parent->removeChild(this);
}

void GameObject::renderObject(const glm::mat4 &parentTransform)
{
	glm::mat4 transformMatrix = transform.getTransform(parentTransform);

	render();

	for (auto &child : children)
	{
		child->renderObject(transformMatrix);
	}
}

void GameObject::updateObject(float delta)
{
	update(delta);

	for (auto &child : children)
	{
		child->updateObject(delta);
	}
}

void GameObject::startObject()
{
	start();

	for (auto &mesh : meshes)
	{
		mesh->start();
	}
}

void GameObject::render()
{
	//TODO: temp solution. Discuss setting transform in engine when iterating over all gameobjects
	//GameEngine::getInstance().setTransform(transform.getTransform());

	for (const auto &mesh : meshes)
	{
		mesh->render();
	}
}

void GameObject::update(float delta)
{

}

void GameObject::start()
{

}

void GameObject::destroy()
{

}

void GameObject::addChild(GameObject *child)
{
	auto itGameObject = find(children.begin(), children.end(), child);
	if (itGameObject != children.end()) return;

	children.push_back(child);
}

void GameObject::removeChild(GameObject *child)
{
	auto objectToRemove = find(children.begin(), children.end(), child);
	iter_swap(objectToRemove, children.end() - 1);
	children.pop_back();
}