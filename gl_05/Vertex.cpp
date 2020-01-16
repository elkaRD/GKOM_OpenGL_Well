#include "Vertex.h"

Vertex::Vertex()
{

}

Vertex::Vertex(glm::vec3 coord, glm::vec3 color, glm::vec2 texCoord) : coord(coord), color(color), texCoord(texCoord), normal(glm::vec3())
{

}

Vertex::Vertex(glm::vec3 coord, glm::vec3 color, glm::vec2 texCoord, glm::vec3 normal) : coord(coord), color(color), 
	texCoord(texCoord), normal(normal)
{

}