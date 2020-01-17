#include "ChLinkMesh.h"
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>
#include <glm\detail\func_geometric.hpp>
#include <glm\gtc\matrix_transform.hpp>


ChLinkMesh::ChLinkMesh(): height(5.0f), width(3.0f), radius(0.5f), segments(DEFAULT_SEGMENTS_NUMBER) {}

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
	glm::mat4 transform[5] = { 
		glm::translate(glm::mat4(),glm::vec3((width-radius)/2,(height-width)/2,0.0f)),
		glm::translate(glm::rotate(glm::translate(glm::mat4(),glm::vec3(0.0f, (height - width) / 2, 0.0f)),glm::radians(45.0f), glm::vec3(0.0f, 0.0f, 1.0f)),glm::vec3((width - radius) / 2,(height - width) / 2,0.0f)),
		glm::translate(glm::rotate(glm::translate(glm::mat4(),glm::vec3(0.0f, (height - width) , 0.0f)),glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f)),glm::vec3((width - radius) / 2,(height - width) / 2,0.0f)),
		glm::translate(glm::rotate(glm::translate(glm::mat4(),glm::vec3(0.0f, (height - width) / 2, 0.0f)),glm::radians(135.0f), glm::vec3(0.0f, 0.0f, 1.0f)),glm::vec3((width - radius) / 2,(height - width) / 2,0.0f)),
		glm::translate(glm::rotate(glm::translate(glm::mat4(),glm::vec3(0.0f, (height - width) / 2, 0.0f)),glm::radians(180.0f), glm::vec3(0.0f, 0.0f, 1.0f)),glm::vec3((width - radius) / 2,(height - width) / 2,0.0f)),
	//	glm::rotate(glm::translate(glm::mat4(),glm::vec3(0.0f, (height - width) / 2, 0.0f)),glm::radians(45.0f), glm::vec3(0.0f, 0.0f, 1.0f))
	//	
	//	
	//
	//
		//glm::translate(glm::rotate(glm::translate(glm::mat4(),glm::vec3((width - radius) / 2,0.0f,0.0f)), glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f)), ),
		//glm::translate(glm::rotate(glm::translate(glm::mat4(),glm::vec3((width - radius) / 2,0.0f,0.0f)), glm::radians(135.0f), glm::vec3(0.0f, 0.0f, 1.0f)), glm::vec3(0.0f, (height - width) / 2, 0.0f)),
		//glm::translate(glm::rotate(glm::translate(glm::mat4(),glm::vec3((width - radius) / 2,0.0f,0.0f)), glm::radians(180.0f), glm::vec3(0.0f, 0.0f, 1.0f)), glm::vec3(0.0f, (height - width) / 2, 0.0f)),
	};
	for (auto i = 0; i < 4; ++i)
	{
		for (float angle = 0.0f; angle <= 360.0f; angle += 360.0f / segments)
		{
			glm::vec4 radial = glm::vec4(cosf(angle * M_PI / 180.0f) * radius, 0.0f, -sinf(angle * M_PI / 180.0f) * radius, 1.0f);
				radial = transform[i] * radial;
			//glm::vec3 aRadial = glm::vec3(cosf(angle * M_PI / 180.0f) * radius, 0.0f, -sinf(angle * M_PI / 180.0f) * radius);
			//aRadial.y += i*1.0f;
			glm::vec3 aRadial = glm::vec3(radial.x, radial.y, radial.z);
			vertices.push_back(Vertex(aRadial, color, glm::vec2(i % 2 == 0 ? 1.0f : 0.0f, 1.0f - angle / 360.0f), glm::normalize(aRadial)));
			std::cout << aRadial.x << ", " << aRadial.y << ", " << aRadial.z << std::endl;
		}
	}
	std::cout << "Chain Vertices size: " << vertices.size() << std::endl;
}

void ChLinkMesh::generateIndices(std::vector<Vertex>& vertices, std::vector<GLuint>& indices)
{
	for (unsigned int l = 0; l < 3; ++l)
	{
		unsigned int verticesperlayer = segments + 1;
		for (unsigned int i = 0; i <= verticesperlayer - 2; ++i)
		{
			indices.push_back(i + l * verticesperlayer);
			indices.push_back(i + 1 + l * verticesperlayer);
			indices.push_back(i + verticesperlayer * (l + 1));
			indices.push_back(i + 1 + l * verticesperlayer);
			indices.push_back(i + verticesperlayer * (l + 1));
			indices.push_back(i + 1 + verticesperlayer * (l + 1));
		}
	}

	for (auto i : indices) {
		std::cout << i << std::endl;
	}
	std::cout << indices.size() << std::endl;
}