#include "TubeMesh.h"

#define _USE_MATH_DEFINES
#include <math.h>

#include <iostream>
#include <glm\detail\func_geometric.hpp>

TubeMesh::TubeMesh(): height(30.0f), radius(1.075f), wallThickness(0.125f), segments(DEFAULT_SEGMENTS_NUMBER), texScale(3.0f, 30.0f), 
	texMode('r') {}

TubeMesh::TubeMesh(float r, float t, float h): height(h), radius(r), wallThickness(t), segments(DEFAULT_SEGMENTS_NUMBER), texScale(1.0f,1.0f),
	texMode('r') {}

void TubeMesh::initializeMeshVertices(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, GLenum& drawingMode)
{
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

void TubeMesh::generateWalls(std::vector<Vertex>& vertices)
{
	//outer tube
	for (unsigned int slice = 0; slice <= layers; ++slice)
	{
		glm::vec3 sliceCenter = glm::vec3(0.0f, height / 2.0f - height / layers * slice, 0.0f);
		float uCoord = 0.5f + 0.5f / layers * slice;
		for (float angle = 0.0f; angle < 360.0f; angle += 360.0f / segments)
		{
			glm::vec2 tex = texMode == 'r' ? glm::vec2(1.0f - angle / 360.0f, slice / layers) * texScale : glm::vec2(uCoord, 1.0f - angle / 360.0f);
			glm::vec3 radial = glm::vec3(cosf(angle * M_PI / 180.0f) * (radius), 0.0f, -sinf(angle * M_PI / 180.0f) * (radius));
			vertices.push_back(Vertex(sliceCenter + radial, color, tex, glm::normalize(radial)));
		}
		vertices.push_back(Vertex(sliceCenter + glm::vec3(cosf(0.0f) * (radius),
			0.0f, -sinf(0.0f) * (radius)), color, texMode == 'r' ? glm::vec2(0.0f, slice / layers) * texScale : glm::vec2(uCoord, 0.0f),glm::vec3(1.0f,0.0f,0.0f)));
	}
	//inner tube
	for (int slice = layers; slice >= 0; --slice)
	{
		glm::vec3 sliceCenter = glm::vec3(0.0f, height / 2.0f - height / layers * slice, 0.0f);
		float uCoord = 0.5f + 0.5f / layers * slice;
		for (float angle = 0.0f; angle < 360.0f; angle += 360.0f / segments)
		{
			glm::vec2 tex = texMode == 'r' ? glm::vec2(1.0f - angle / 360.0f, slice / layers) * texScale : glm::vec2(uCoord, 1.0f - angle / 360.0f);
			glm::vec3 radial = glm::vec3(cosf(angle * M_PI / 180.0f), 0.0f, -sinf(angle * M_PI / 180.0f)) * (radius - wallThickness);
			vertices.push_back(Vertex(sliceCenter + radial, color, tex, -glm::normalize(radial)));
		}
		vertices.push_back(Vertex(sliceCenter + glm::vec3(cosf(0.0f) * (radius - wallThickness),
			0.0f, -sinf(0.0f) * (radius - wallThickness)), color, texMode == 'r' ? glm::vec2(0.0f, slice / layers) * texScale
			: glm::vec2(uCoord, 0.0f), -glm::vec3(cosf(0.0f), 0.0f, -sinf(0.0f))));
	}
	//std::cout << vertices.size() << std::endl;

	glm::vec3 center = glm::vec3(0.0f, height / 2.0f, 0.0f);
	glm::vec2 textureCenter = glm::vec2(0.25f, 0.25f);
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	//top and bottom 
	for (int j = 0; j != 2; ++j)
	{
		for (int i = 0; i != 2; ++i)
		{
			for (float angle = 0.0f; angle < 360.0f; angle += 360.0f / segments)
			{
				glm::vec2 tex = texMode == 'r' ? glm::vec2(angle / 360.0f * texScale.x, i / 12.0f) : textureCenter + glm::vec2(cosf(angle * M_PI / 180.0f) * (radius - wallThickness * i) / 4 / radius,
					-sinf(angle * M_PI / 180.0f) * (radius - wallThickness * i) / 4 / radius);
				vertices.push_back(Vertex(center + glm::vec3(cosf(angle * M_PI / 180.0f) * (radius - wallThickness * i), 0.0f,
					-sinf(angle * M_PI / 180.0f) * (radius - wallThickness * i)), color, tex, up));
			}
			glm::vec2 tex = texMode == 'r' ? glm::vec2(1.0f * texScale.x, i / 12.0f) : textureCenter + glm::vec2(cosf(0.0f * M_PI / 180.0f) * (radius - wallThickness * i) / 4 / radius,
				-sinf(0.0f * M_PI / 180.0f) * (radius - wallThickness * i) / 4 / radius);
			if(texMode=='r')
				vertices.push_back(Vertex(center + glm::vec3(cosf(0.0f * M_PI / 180.0f) * (radius - wallThickness * i), 0.0f,
					-sinf(0.0f * M_PI / 180.0f) * (radius - wallThickness * i)), color, tex, up));
		}
		center.y -= height;
		up = glm::vec3(0.0f, -1.0f, 0.0f);
		textureCenter = glm::vec2(0.25f, 0.75f);
	}
	//std::cout << vertices.size() << std::endl;
}

void TubeMesh::generateIndices(std::vector<Vertex>& vertices, std::vector<GLuint>& indices)
{
	for (unsigned int l = 0; l <= layers * 2; ++l)
	{
		if (l == layers)
			continue;
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

	unsigned int offset = layers * 4 * (segments + 1);
	if (texMode != 'r')
		for (unsigned int k = 0; k < 4; k += 2)
		{
			for (unsigned int i = 0; i <= segments - 1; ++i)
			{
				indices.push_back(i % segments + k * segments + offset);
				indices.push_back(i != segments - 1 ? i % segments + 1 + k * segments + offset : i % segments + 1 + (k - 1) * segments + offset);
				indices.push_back(i % segments + segments * (k + 1) + offset);
				indices.push_back((i + 1) % segments + k * segments + offset);
				indices.push_back(i % segments + segments * (k + 1) + offset);
				indices.push_back((i + 1) % segments + segments * (k + 1) + offset);
			}
		}
	else
		for (unsigned int k = 0; k < 4; k += 2)
		{
			int verticesperlayer = segments + 1;
			for (unsigned int i = 0; i <= segments -1 ; ++i)
			{
				indices.push_back(i + k * verticesperlayer + offset);
				indices.push_back(i + 1 + k * verticesperlayer + offset);
				indices.push_back(i + verticesperlayer * (k + 1) + offset);
				indices.push_back(i + 1 + k * verticesperlayer + offset);
				indices.push_back(i + verticesperlayer * (k + 1) + offset);
				indices.push_back(i + 1 + verticesperlayer * (k + 1) + offset);
			}
		}

}