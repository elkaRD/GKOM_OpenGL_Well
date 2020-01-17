#include "ChLinkMesh.h"
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>
#include <glm\detail\func_geometric.hpp>


ChLinkMesh::ChLinkMesh(): height(5.0f), width(3.0f), radius(1.0f), segments(DEFAULT_SEGMENTS_NUMBER) {}

ChLinkMesh::ChLinkMesh(GLfloat height, GLfloat width, GLfloat radius) : height(height), width(width), 
	radius(radius), segments(DEFAULT_SEGMENTS_NUMBER) {}

void ChLinkMesh::initializeMeshVertices(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, GLenum& drawingMode)
{

}

void ChLinkMesh::generateVertices(std::vector<Vertex>& vertices)
{
	unsigned int i = 0;
	for (float angle = 0.0f; angle < 360.0f; angle += 360.0f / segments)
	{
		glm::vec3 radial = glm::vec3(cosf(angle * M_PI / 180.0f) * radius, 0.0f, -sinf(angle * M_PI / 180.0f) * radius);
		vertices.push_back(Vertex(radial, color, glm::vec2(i%2 == 0 ? 1.0f : 0.0f, 1.0f - angle / 360.0f), glm::normalize(radial)));
	}
}

void ChLinkMesh::generateIndices(std::vector<Vertex>& vertices, std::vector<GLuint>& indices)
{

}