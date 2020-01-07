#include "CylinderMesh.h"
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>

void CylinderMesh::initializeMeshVertices(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, GLenum& drawingMode)
{
	//generate top plane
	glm::vec3 planeCenter = glm::vec3(0.0f, height / 2.0f, 0.0f);
	vertices.push_back(Vertex(planeCenter, color, glm::vec2(0.0f, 0.0f)));
	float h_layer = height / layers;

	for (unsigned int slice = 0; slice <= layers; ++slice)
	{
		for (float angle = 0.0f; angle < 360.0f; angle += 360.0f / segments)
		{
			//std::cout
			vertices.push_back(Vertex(glm::vec3(cosf(angle * M_PI / 180.0f) * radius, height / 2.0f - h_layer * slice,
				-sinf(angle * M_PI / 180.0f) * radius), color, glm::vec2(0.0f, 0.0f)));
		}
		//std::cout << slice << std::endl;
	}
	//generate bottom plane
	planeCenter = glm::vec3(0.0f, -height / 2.0f, 0.0f);
	vertices.push_back(Vertex(planeCenter, color, glm::vec2(0.0f, 0.0f)));
	//std::cout << vertices.size() << std::endl;
	//indices
	for (unsigned int i = 0; i < segments; ++i)
	{
		indices.push_back(0);
		indices.push_back(i+1);
		indices.push_back(i+2 == segments + 1 ? 1 : i + 2);
		indices.push_back(vertices.size() - 1);
		indices.push_back(vertices.size() - i - 2);
		indices.push_back(i + 2 == segments + 1 ? vertices.size() - 2 : vertices.size() - i - 3);
		//std::cout << 0 << ", " << i + 1 << ", " << i + 1 % (vertices.size() - 1) + 1 << std::endl;
	}
	for (unsigned int l = 0; l < layers; ++l)
	{
		for (unsigned int i = 1; i <= segments; ++i)
		{
			indices.push_back(i + l * segments);
			indices.push_back(i + 1 + l * segments);
			indices.push_back(i + segments * (l+1));
			indices.push_back(i + 1 + l * segments);
			indices.push_back(i + segments * (l+1));
			indices.push_back(i + 1 + segments * (l+1));
		}
	}
	
	drawingMode = GL_TRIANGLES;
}

CylinderMesh::CylinderMesh() : height(5.0f), radius(1.0f), segments(DEFAULT_SEGMENTS_NUMBER), layers(DEFAULT_LAYERS_NUMBER),
color(glm::vec3(1.0f, 0.0f, 0.0f)) {}