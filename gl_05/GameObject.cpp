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

void GameObject::renderObject(const glm::vec4 &parentTransform)
{
	glm::vec4 transformMatrix = transform.getTransform(parentTransform);

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

void GameObject::render()
{

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