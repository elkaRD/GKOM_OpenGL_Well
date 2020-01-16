#include "CylinderMesh.h"
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>
#include <glm\detail\func_geometric.hpp>

void CylinderMesh::initializeMeshVertices(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, GLenum& drawingMode)
{
	generatePlate(vertices, true);
	generatePlate(vertices, false);
	generateWalls(vertices);
	generateIndices(vertices, indices);

	//for (size_t i = 0; i < indices.size(); i++)
	//{
	//	std::cout << indices[i] << ", ";
	//	if (i % 3 == 2)
	//		std::cout << std::endl;
	//}
	
	drawingMode = GL_TRIANGLES;
}

CylinderMesh::CylinderMesh() : height(5.0f), radius(1.0f), segments(DEFAULT_SEGMENTS_NUMBER), layers(DEFAULT_LAYERS_NUMBER),
color(glm::vec3(1.0f, 0.0f, 0.0f)) {}

void CylinderMesh::generatePlate(std::vector<Vertex>& vertices, bool top)
{
	glm::vec3 center = glm::vec3(0.0f, top ? height / 2.0f : -height / 2.0f, 0.0f);
	glm::vec2 textureCenter = top ? glm::vec2(0.25f, 0.25f) : glm::vec2(0.25f, 0.75f);
	glm::vec3 normal = top ? glm::vec3(0.0f, 1.0f, 0.0f) : glm::vec3(0.0f, -1.0f, 0.0f);
	
	vertices.push_back(Vertex(center, color, textureCenter));

	for (float angle = 0.0f; angle < 360.0f; angle += 360.0f / segments)
	{
		vertices.push_back(Vertex(center + glm::vec3(cosf(angle * M_PI / 180.0f) * radius, 0.0f,
			-sinf(angle * M_PI / 180.0f) * radius), color, textureCenter + glm::vec2(cosf(angle * M_PI / 180.0f) * 0.25f,
				-sinf(angle * M_PI / 180.0f) * 0.25f), normal));
	}

}

void CylinderMesh::generateWalls(std::vector<Vertex>& vertices)
{
	for (unsigned int slice = 0; slice <= layers; ++slice)
	{ 
		glm::vec3 sliceCenter = glm::vec3(0.0f, height / 2.0f - height / layers * slice, 0.0f);
		float uCoord = 0.5f + 0.5f / layers * slice;
		for (float angle = 0.0f; angle < 360.0f; angle += 360.0f / segments)
		{
			glm::vec3 radial = glm::vec3(cosf(angle * M_PI / 180.0f) * radius, 0.0f, -sinf(angle * M_PI / 180.0f) * radius);
			vertices.push_back(Vertex(sliceCenter + radial, color, glm::vec2(uCoord, 1.0f - angle / 360.0f), glm::normalize(radial)));
		}
		vertices.push_back(Vertex(sliceCenter + glm::vec3(cosf(0.0f) * radius, 0.0f, -sinf(0.0f) * radius), color, glm::vec2(uCoord, 0.0f),
			glm::vec3(cosf(0.0f), 0.0f, -sinf(0.0f))));
	}
}

void CylinderMesh::generateIndices(std::vector<Vertex>& vertices, std::vector<GLuint>& indices)
{
	unsigned int verticesOnPlate = segments + 1;
	for (unsigned int j = 0; j < 2; ++j)
	{
		for (unsigned int i = 0; i < segments; ++i)
		{
			indices.push_back(0 + verticesOnPlate * j);
			indices.push_back(i + 1 + verticesOnPlate * j);
			indices.push_back(i + 2 == segments + 1 ? 1 + verticesOnPlate * j : i + 2 + verticesOnPlate * j);
		}
	}

	for (unsigned int l = 0; l < layers; ++l)
	{
		unsigned int verticesperlayer = segments + 1;
		for (unsigned int i = 0; i <= verticesperlayer-2 ; ++i)
		{
			indices.push_back(i + l * verticesperlayer + verticesOnPlate * 2);
			indices.push_back(i + 1 + l * verticesperlayer + verticesOnPlate * 2);
			indices.push_back(i + verticesperlayer * (l + 1) + verticesOnPlate * 2);
			indices.push_back(i + 1 + l * verticesperlayer + verticesOnPlate * 2);
			indices.push_back(i + verticesperlayer * (l + 1) + verticesOnPlate * 2);
			indices.push_back(i + 1 + verticesperlayer * (l + 1) + verticesOnPlate * 2);
			//std::cout << i + l * verticesperlayer << ", " << i + 1 + l * verticesperlayer
			//	<< ", " << i + verticesperlayer * (l + 1) << std::endl << i + 1 + l * verticesperlayer
			//	<< ", " << i + verticesperlayer * (l + 1) << ", " << i + 1 + verticesperlayer * (l + 1) << std::endl;
		}
	}
}
