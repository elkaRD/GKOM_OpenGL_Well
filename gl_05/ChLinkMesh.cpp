#include "ChLinkMesh.h"
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>
#include <glm\detail\func_geometric.hpp>
#include <glm\gtc\matrix_transform.hpp>


ChLinkMesh::ChLinkMesh(): height(0.07f), width(0.04f), radius(0.005f), segments(DEFAULT_SEGMENTS_NUMBER) {}

ChLinkMesh::ChLinkMesh(GLfloat height, GLfloat width, GLfloat radius) : height(height), width(width), 
	radius(radius), segments(DEFAULT_SEGMENTS_NUMBER) {}

void ChLinkMesh::initializeMeshVertices(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, GLenum& drawingMode)
{
	generateVertices(vertices);
	generateIndices(vertices, indices);

	drawingMode = GL_TRIANGLES;
}

void ChLinkMesh::generateVertices(std::vector<Vertex>& vertices)
{
	float r = (width - 2 * radius) / 2;
	glm::mat4 transform[10] = { 
		glm::translate(glm::mat4(),glm::vec3((width-radius*2)/2,(height-width)/2,0.0f)),
		glm::rotate(glm::translate(glm::mat4(),glm::vec3(cos(glm::radians(45.0f))*(width-radius*2)/2, (height - width) / 2 + sin(glm::radians(45.0f)) * r, 0.0f)),glm::radians(45.0f), glm::vec3(0.0f, 0.0f, 1.0f)),
		glm::rotate(glm::translate(glm::mat4(),glm::vec3(cos(glm::radians(90.0f)) * (width - radius * 2) / 2, (height - width) / 2 + sin(glm::radians(90.0f)) * r, 0.0f)),glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f)),
		glm::rotate(glm::translate(glm::mat4(),glm::vec3(cos(glm::radians(135.0f)) * (width - radius * 2) / 2, (height - width) / 2 + sin(glm::radians(135.0f)) * r, 0.0f)),glm::radians(135.0f), glm::vec3(0.0f, 0.0f, 1.0f)),
		glm::rotate(glm::translate(glm::mat4(),glm::vec3(cos(glm::radians(180.0f)) * (width - radius * 2) / 2, (height - width) / 2 + sin(glm::radians(180.0f)) * r, 0.0f)),glm::radians(180.0f), glm::vec3(0.0f, 0.0f, 1.0f)),
		glm::rotate(glm::translate(glm::mat4(),glm::vec3(-(width - radius * 2) / 2,-(height-width)/2,0.0f)),glm::radians(180.0f), glm::vec3(0.0f, 0.0f, 1.0f)),
		glm::rotate(glm::translate(glm::mat4(),glm::vec3(cos(glm::radians(225.0f)) * (width - radius * 2) / 2, (width - height) / 2 + sin(glm::radians(225.0f)) * r, 0.0f)),glm::radians(225.0f), glm::vec3(0.0f, 0.0f, 1.0f)),
		glm::rotate(glm::translate(glm::mat4(),glm::vec3(cos(glm::radians(270.0f)) * (width - radius * 2) / 2, (width - height) / 2 + sin(glm::radians(270.0f)) * r, 0.0f)),glm::radians(270.0f), glm::vec3(0.0f, 0.0f, 1.0f)),
		glm::rotate(glm::translate(glm::mat4(),glm::vec3(cos(glm::radians(315.0f)) * (width - radius * 2) / 2, (width - height) / 2 + sin(glm::radians(315.0f)) * r, 0.0f)),glm::radians(315.0f), glm::vec3(0.0f, 0.0f, 1.0f)),
		glm::rotate(glm::translate(glm::mat4(),glm::vec3(cos(glm::radians(0.0f)) * (width - radius * 2) / 2, (width - height) / 2 + sin(glm::radians(0.0f)) * r, 0.0f)),glm::radians(0.0f), glm::vec3(0.0f, 0.0f, 1.0f))
	};
	for (auto i = 0; i < 10; ++i)
	{
		for (float angle = 0.0f; angle <= 360.0f; angle += 360.0f / segments)
		{
			glm::vec4 radial = glm::vec4(cosf(angle * M_PI / 180.0f) * radius, 0.0f, -sinf(angle * M_PI / 180.0f) * radius, 1.0f);
				radial = transform[i] * radial;
			glm::vec3 aRadial = glm::vec3(radial.x, radial.y, radial.z);
			vertices.push_back(Vertex(aRadial, color, glm::vec2(i % 2 == 0 ? 1.0f : 0.0f, 1.0f - angle / 360.0f), glm::normalize(aRadial)));
		}
	}

}

void ChLinkMesh::generateIndices(std::vector<Vertex>& vertices, std::vector<GLuint>& indices)
{
	for (unsigned int l = 0; l < 10; ++l)
	{
		unsigned int verticesperlayer = segments + 1;
		for (unsigned int i = 0; i <= verticesperlayer - 2; ++i)
		{
			indices.push_back((i + l * verticesperlayer)%vertices.size());
			indices.push_back((i + 1 + l * verticesperlayer)% vertices.size());
			indices.push_back((i + verticesperlayer * (l + 1))%vertices.size());
			indices.push_back((i + 1 + l * verticesperlayer)%vertices.size());
			indices.push_back((i + verticesperlayer * (l + 1))%vertices.size());
			indices.push_back((i + 1 + verticesperlayer * (l + 1))%vertices.size());
		}
	}
}

GLfloat ChLinkMesh::getHeight() const
{
	return height;
}

GLfloat ChLinkMesh::getRadius() const
{
	return radius;
}