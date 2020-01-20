#include "Pyramid.h"

using namespace glm;

void Pyramid::initializeMeshVertices(std::vector<Vertex> &vertices, std::vector<GLuint> &indices, GLenum &drawingMode)
{
	vertices.push_back(Vertex(vec3(0.0f, 1.0f, 0.0f), vec3(1.0f), vec2(0.5f, 1.0f), vec3()));

	for (int i = 0; i < 6; ++i)
	{
		float x = cos(radians((float)(360 / 6 * i)));
		float z = sin(radians((float)(360 / 6 * i)));
		vertices.push_back(Vertex(vec3(x, 0.5f, z), vec3(1.0f), vec2(0.5f, 1.0f), vec3()));
	}

	for (int i = 0; i < 6; ++i)
	{
		indices.push_back(0);
		indices.push_back((i+1)%6);
		indices.push_back((i+2)%6);
	}

	drawingMode = GL_TRIANGLES;
}