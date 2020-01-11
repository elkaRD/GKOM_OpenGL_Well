#include "CubeMesh.h"

using namespace glm;

CubeMesh::CubeMesh() : x(1.0f), y(1.0f), z(1.0f)
{

}

CubeMesh::CubeMesh(float size) : x(size), y(size), z(size)
{

}

CubeMesh::CubeMesh(float x, float y, float z) : x(x), y(y), z(z)
{

}

void CubeMesh::initializeMeshVertices(std::vector<Vertex> &vertices, std::vector<GLuint> &indices, GLenum &drawingMode)
{
	vertices.reserve(32);

	vertices.push_back(Vertex(vec3(-0.5f, 0.5f, 0.5f), vec3(1.0f), vec2(0.0f, 1.0f)));
	vertices.push_back(Vertex(vec3(0.5f, 0.5f, 0.5f), vec3(1.0f), vec2(1.0f, 1.0f)));
	vertices.push_back(Vertex(vec3(-0.5f, 0.5f, -0.5f), vec3(1.0f), vec2(0.0f, 0.0f)));
	vertices.push_back(Vertex(vec3(0.5f, 0.5f, -0.5f), vec3(1.0f), vec2(1.0f, 0.0f)));

	vertices.push_back(Vertex(vec3(-0.5f, -0.5f, 0.5f), vec3(1.0f), vec2(0.0f, 1.0f)));
	vertices.push_back(Vertex(vec3(0.5f, -0.5f, 0.5f), vec3(1.0f), vec2(1.0f, 1.0f)));
	vertices.push_back(Vertex(vec3(-0.5f, -0.5f, -0.5f), vec3(1.0f), vec2(0.0f, 0.0f)));
	vertices.push_back(Vertex(vec3(0.5f, -0.5f, -0.5f), vec3(1.0f), vec2(1.0f, 0.0f)));

	vertices.push_back(Vertex(vec3(-0.5f, 0.5f, 0.5f), vec3(1.0f), vec2(1.0f, 0.0f)));
	vertices.push_back(Vertex(vec3(0.5f, 0.5f, 0.5f), vec3(1.0f), vec2(0.0f, 0.0f)));
	vertices.push_back(Vertex(vec3(-0.5f, -0.5f, 0.5f), vec3(1.0f), vec2(1.0f, 1.0f)));
	vertices.push_back(Vertex(vec3(0.5f, -0.5f, 0.5f), vec3(1.0f), vec2(0.0f, 1.0f)));

	vertices.push_back(Vertex(vec3(-0.5f, 0.5f, -0.5f), vec3(1.0f), vec2(1.0f, 0.0f)));
	vertices.push_back(Vertex(vec3(0.5f, 0.5f, -0.5f), vec3(1.0f), vec2(0.0f, 0.0f)));
	vertices.push_back(Vertex(vec3(-0.5f, -0.5f, -0.5f), vec3(1.0f), vec2(1.0f, 1.0f)));
	vertices.push_back(Vertex(vec3(0.5f, -0.5f, -0.5f), vec3(1.0f), vec2(0.0f, 1.0f)));

	vertices.push_back(Vertex(vec3(-0.5f, 0.5f, -0.5f), vec3(1.0f), vec2(1.0f, 0.0f)));
	vertices.push_back(Vertex(vec3(-0.5f, 0.5f, 0.5f), vec3(1.0f), vec2(0.0f, 0.0f)));
	vertices.push_back(Vertex(vec3(-0.5f, -0.5f, -0.5f), vec3(1.0f), vec2(1.0f, 1.0f)));
	vertices.push_back(Vertex(vec3(-0.5f, -0.5f, 0.5f), vec3(1.0f), vec2(0.0f, 1.0f)));

	vertices.push_back(Vertex(vec3(0.5f, 0.5f, 0.5f), vec3(1.0f), vec2(1.0f, 0.0f)));
	vertices.push_back(Vertex(vec3(0.5f, 0.5f, -0.5f), vec3(1.0f), vec2(0.0f, 0.0f)));
	vertices.push_back(Vertex(vec3(0.5f, -0.5f, 0.5f), vec3(1.0f), vec2(1.0f, 1.0f)));
	vertices.push_back(Vertex(vec3(0.5f, -0.5f, -0.5f), vec3(1.0f), vec2(0.0f, 1.0f)));

	for (int i = 0; i < 6; ++i)
	{
		indices.push_back(i*4 + 2);
		indices.push_back(i*4 + 1);
		indices.push_back(i*4 + 0);

		indices.push_back(i*4 + 2);
		indices.push_back(i*4 + 3);
		indices.push_back(i*4 + 1);
	}

	scaleVertices(vertices, x, y, z);

	drawingMode = GL_TRIANGLES;
}