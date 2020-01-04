#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Transform
{
public:
	Transform();

	void setPosition(const glm::vec3 &position);
	void setRotation(const glm::vec3 &rotation);
	void setScale(const glm::vec3 &scale);

	glm::vec3 getPosition() const;
	glm::vec3 getRotation() const;
	glm::vec3 getScale() const;

	glm::vec4 getTransform() const;
	//glm::vec4 getTransform(const Transform &parentTransform) const;
	glm::vec4 getTransform(const glm::vec4 &parentTransform) const;

private:
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
};

#endif