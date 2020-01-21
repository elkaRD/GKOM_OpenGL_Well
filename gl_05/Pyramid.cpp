#include "Pyramid.h"

using namespace glm;

Pyramid::Pyramid(int sides, float h, float r) : sides(sides), H(h), R(r)
{

}

void Pyramid::initializeMeshVertices(std::vector<Vertex> &vertices, std::vector<GLuint> &indices, GLenum &drawingMode)
{
	const float texMulti = 3;

	float prevX = R * cos(radians((float)(360.0f / sides * (sides - 1))));
	float prevZ = R * sin(radians((float)(360.0f / sides * (sides - 1))));

	for (int i = 0; i < sides; ++i)
	{
		float x = R * cos(radians((float)(360.0f / sides * i)));
		float z = R * sin(radians((float)(360.0f / sides * i)));

		glm::vec3 v1 = glm::vec3(prevX, -H, prevZ);
		glm::vec3 v2 = glm::vec3(x, -H, z);
		glm::vec3 normal = glm::cross(v2, v1);

		vertices.push_back(Vertex(vec3(0.0f, H, 0.0f), vec3(1.0f), vec2(0.5f * texMulti, 1.0f * texMulti), normal));
		vertices.push_back(Vertex(vec3(prevX, 0, prevZ), vec3(1.0f), vec2(0, 0), normal));
		vertices.push_back(Vertex(vec3(x, 0, z), vec3(1.0f), vec2(1.0f * texMulti, 0), normal));

		vertices.push_back(Vertex(vec3(0.0f, 0.0f, 0.0f), vec3(1.0f), vec2(0.5f * texMulti, 1.0f * texMulti), vec3(0, -1.0f, 0)));
		vertices.push_back(Vertex(vec3(prevX, 0, prevZ), vec3(1.0f), vec2(0, 0), vec3(0, -1.0f, 0)));
		vertices.push_back(Vertex(vec3(x, 0, z), vec3(1.0f), vec2(1.0f * texMulti, 0), vec3(0, -1.0f, 0)));

		prevX = x;
		prevZ = z;
	}

	

	for (int i = 0; i < sides * 2; ++i)
	{
		indices.push_back(3 * i);
		indices.push_back(3 * i + 1);
		indices.push_back(3 * i + 2);
	}

	drawingMode = GL_TRIANGLES;
}