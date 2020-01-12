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

	//up and down texCoords multipliers
	float ud_x = 1;
	float ud_y = 1;

	//left and right texCoords multipliers
	float lr_x = 1;
	float lr_y = 1;

	//near and far texCoords multipliers
	float nf_x = 1;
	float nf_y = 1;

	if (y > x) nf_y = y / x;
	if (x > y) nf_x = x / y;

	if (z > x) ud_y = z / x;
	if (x > z) ud_x = x / z;

	if (y > z) lr_y = y / z;
	if (z > y) lr_x = z / y;

	//up
	vertices.push_back(Vertex(vec3(-0.5f, 0.5f, 0.5f),		vec3(1.0f), vec2(0.0f * ud_x, 1.0f * ud_y)));
	vertices.push_back(Vertex(vec3(0.5f, 0.5f, 0.5f),		vec3(1.0f), vec2(1.0f * ud_x, 1.0f * ud_y)));
	vertices.push_back(Vertex(vec3(-0.5f, 0.5f, -0.5f),		vec3(1.0f), vec2(0.0f * ud_x, 0.0f * ud_y)));
	vertices.push_back(Vertex(vec3(0.5f, 0.5f, -0.5f),		vec3(1.0f), vec2(1.0f * ud_x, 0.0f * ud_y)));

	//down
	vertices.push_back(Vertex(vec3(-0.5f, -0.5f, 0.5f),		vec3(1.0f), vec2(0.0f * ud_x, 1.0f * ud_y)));
	vertices.push_back(Vertex(vec3(0.5f, -0.5f, 0.5f),		vec3(1.0f), vec2(1.0f * ud_x, 1.0f * ud_y)));
	vertices.push_back(Vertex(vec3(-0.5f, -0.5f, -0.5f),	vec3(1.0f), vec2(0.0f * ud_x, 0.0f * ud_y)));
	vertices.push_back(Vertex(vec3(0.5f, -0.5f, -0.5f),		vec3(1.0f), vec2(1.0f * ud_x, 0.0f * ud_y)));

	//near
	vertices.push_back(Vertex(vec3(-0.5f, 0.5f, 0.5f),		vec3(1.0f), vec2(1.0f * nf_x, 0.0f * nf_y)));
	vertices.push_back(Vertex(vec3(0.5f, 0.5f, 0.5f),		vec3(1.0f), vec2(0.0f * nf_x, 0.0f * nf_y)));
	vertices.push_back(Vertex(vec3(-0.5f, -0.5f, 0.5f),		vec3(1.0f), vec2(1.0f * nf_x, 1.0f * nf_y)));
	vertices.push_back(Vertex(vec3(0.5f, -0.5f, 0.5f),		vec3(1.0f), vec2(0.0f * nf_x, 1.0f * nf_y)));

	//far
	vertices.push_back(Vertex(vec3(-0.5f, 0.5f, -0.5f),		vec3(1.0f), vec2(1.0f * nf_x, 0.0f * nf_y)));
	vertices.push_back(Vertex(vec3(0.5f, 0.5f, -0.5f),		vec3(1.0f), vec2(0.0f * nf_x, 0.0f * nf_y)));
	vertices.push_back(Vertex(vec3(-0.5f, -0.5f, -0.5f),	vec3(1.0f), vec2(1.0f * nf_x, 1.0f * nf_y)));
	vertices.push_back(Vertex(vec3(0.5f, -0.5f, -0.5f),		vec3(1.0f), vec2(0.0f * nf_x, 1.0f * nf_y)));

	//left
	vertices.push_back(Vertex(vec3(-0.5f, 0.5f, -0.5f),		vec3(1.0f), vec2(1.0f * lr_x, 0.0f * lr_y)));
	vertices.push_back(Vertex(vec3(-0.5f, 0.5f, 0.5f),		vec3(1.0f), vec2(0.0f * lr_x, 0.0f * lr_y)));
	vertices.push_back(Vertex(vec3(-0.5f, -0.5f, -0.5f),	vec3(1.0f), vec2(1.0f * lr_x, 1.0f * lr_y)));
	vertices.push_back(Vertex(vec3(-0.5f, -0.5f, 0.5f),		vec3(1.0f), vec2(0.0f * lr_x, 1.0f * lr_y)));

	//right
	vertices.push_back(Vertex(vec3(0.5f, 0.5f, 0.5f),		vec3(1.0f), vec2(1.0f * lr_x, 0.0f * lr_y)));
	vertices.push_back(Vertex(vec3(0.5f, 0.5f, -0.5f),		vec3(1.0f), vec2(0.0f * lr_x, 0.0f * lr_y)));
	vertices.push_back(Vertex(vec3(0.5f, -0.5f, 0.5f),		vec3(1.0f), vec2(1.0f * lr_x, 1.0f * lr_y)));
	vertices.push_back(Vertex(vec3(0.5f, -0.5f, -0.5f),		vec3(1.0f), vec2(0.0f * lr_x, 1.0f * lr_y)));

	for (int i = 0; i < 6; ++i)
	{
		indices.push_back(i*4 + 2);
		indices.push_back(i*4 + 1);
		indices.push_back(i*4 + 0);

		indices.push_back(i*4 + 2);
		indices.push_back(i*4 + 3);
		indices.push_back(i*4 + 1);
	}

	if (x != z)
	{
		if (x > z)
		{

		}
	}

	scaleVertices(vertices, x, y, z);

	drawingMode = GL_TRIANGLES;
}