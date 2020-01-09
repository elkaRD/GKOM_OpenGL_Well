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

	void setPosition(float x, float y, float z);
	void setRotation(float x, float y, float z);
	void setScale(float x, float y, float z);

	void setScale(float scale);

	void translate(const glm::vec3 &position);
	void rotate(const glm::vec3 &rotation);
	//void scale(const glm::vec3 &scale);

	void translate(float x, float y, float z);
	void rotate(float x, float y, float z);
	//void scale(float x, float y, float z);

	glm::vec3 getPosition() const;
	glm::vec3 getRotation() const;
	glm::vec3 getScale() const;

	glm::mat4 getTransform() const;
	//glm::vec4 getTransform(const Transform &parentTransform) const;
	glm::mat4 getTransform(const glm::mat4 &parentTransform) const;

private:
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
};

#endif