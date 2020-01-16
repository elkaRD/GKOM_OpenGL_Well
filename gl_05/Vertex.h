#ifndef VERTEX_H
#define VERTEX_H

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

class Vertex
{
public:
	Vertex();
	Vertex(glm::vec3 coord, glm::vec3 color, glm::vec2 texCoord);

	glm::vec3 coord;
	glm::vec3 color;
	glm::vec2 texCoord;
};

#endif