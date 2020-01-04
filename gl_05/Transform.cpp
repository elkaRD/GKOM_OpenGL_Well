#include "Transform.h"

Transform::Transform()
{
	position = glm::vec3(0.0f);
	rotation = glm::vec3(0.0f);
	scale = glm::vec3(1.0f);
}

void Transform::setPosition(const glm::vec3 &position)
{
	this->position = position;
}

void Transform::setRotation(const glm::vec3 &rotation)
{
	this->rotation = rotation;
}

void Transform::setScale(const glm::vec3 &scale)
{
	this->scale = scale;
}

glm::vec3 Transform::getPosition() const
{
	return position;
}

glm::vec3 Transform::getRotation() const
{
	return rotation;
}

glm::vec3 Transform::getScale() const
{
	return scale;
}

glm::vec4 Transform::getTransform() const
{
	return getTransform(glm::vec4(1.0f));
}

//glm::vec4 Transform::getTransform(const Transform &parentTransform) const
//{
//	return getTransform(parentTransform.getLastTransform());
//}

glm::vec4 Transform::getTransform(const glm::vec4 &parentTransform) const
{
	glm::mat4 temp = glm::mat4(1.0f);

	temp = glm::scale(temp, scale);
	temp = glm::translate(temp, position);

	temp = glm::rotate(temp, glm::radians(rotation.y), glm::vec3(0, 1, 0));
	temp = glm::rotate(temp, glm::radians(rotation.x), glm::vec3(1, 0, 0));
	temp = glm::rotate(temp, glm::radians(rotation.z), glm::vec3(0, 0, 1));

	return parentTransform * temp;
}