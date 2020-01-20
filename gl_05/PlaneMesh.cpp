#include "PlaneMesh.h"

#define _USE_MATH_DEFINES
#include <math.h>

#include <iostream>


PlaneMesh::PlaneMesh(): width(10.0f), length(10.0f), holeRadius(0.0f), texScale(10.0f,10.0f) {}

PlaneMesh::PlaneMesh(GLfloat aWidth, GLfloat aLength, GLfloat scaleU, GLfloat scaleV): width(aWidth), length(aLength), holeRadius(0.0f),
	texScale(scaleU, scaleV) {}

PlaneMesh::PlaneMesh(GLfloat aWidth, GLfloat aLength, GLfloat aHoleRadius, glm::vec2 aHoleCenter, GLfloat scaleU, GLfloat scaleV):
	width(aWidth), length(aLength), texScale(scaleU, scaleV), holeCenter(aHoleCenter), holeRadius(aHoleRadius) {}

void PlaneMesh::initializeMeshVertices(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, GLenum& drawingMode)
{
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	vertices.push_back(Vertex(glm::vec3(-width / 2, 0, -length / 2), color, glm::vec2(0.0f, 0.0f) * texScale, up));
	vertices.push_back(Vertex(glm::vec3(width / 2, 0, -length / 2), color, glm::vec2(1.0f, 0.0f) * texScale, up));

	if (holeRadius != 0.0f)
	{
		for (int i = 0; i != 2; ++i)
		{
			GLfloat z = i == 0 ? holeCenter.y - holeRadius : holeCenter.y + holeRadius;
			GLfloat v = i == 0 ? (holeCenter.y - holeRadius) / length + 0.5f : (holeCenter.y + holeRadius) / length + 0.5f;
			vertices.push_back(Vertex(glm::vec3(-width / 2, 0, z), color, glm::vec2(0.0f, v) * texScale, up));
			vertices.push_back(Vertex(glm::vec3(holeCenter.x - holeRadius, 0, z), color, glm::vec2((holeCenter.x - holeRadius) / length + 0.5f, v) * texScale, up));
			vertices.push_back(Vertex(glm::vec3(holeCenter.x + holeRadius, 0, z), color, glm::vec2((holeCenter.x + holeRadius) / length + 0.5f, v) * texScale, up));
			vertices.push_back(Vertex(glm::vec3(width / 2, 0, z), color, glm::vec2(1.0f, v) * texScale, up));
		}
	}
	vertices.push_back(Vertex(glm::vec3(-width / 2, 0, length / 2), color, glm::vec2(0.0f, 1.0f) * texScale, up));
	vertices.push_back(Vertex(glm::vec3(width / 2, 0, length / 2), color, glm::vec2(1.0f, 1.0f) * texScale, up));
	if ( holeRadius != 0.0f) 
	{
		glm::vec3 center = glm::vec3(holeCenter.x, 0.0f, holeCenter.y);
		glm::vec2 texCenter = glm::vec2((0.5f + holeCenter.x / width), (0.5f + holeCenter.y / length));
		for (float angle = 0.0f; angle < 360.0f; angle += 360.0f / HOLE_SEG)
		{
			vertices.push_back(Vertex(center + glm::vec3(cosf(angle * (float) M_PI / 180.0f) * holeRadius, 0.0f,-sinf(angle * (float)M_PI / 180.0f) * holeRadius),
				color,texCenter * texScale + glm::vec2(cosf(angle * (float) M_PI / 180.0f) * holeRadius / width,
					-sinf(angle * (float)M_PI / 180.0f) * holeRadius / length) * texScale, up));
		}
	}
	
	if (holeRadius == 0.0f)
	{
		indices = { 0, 1, 2, 1, 2, 3 };
	}
	else {
		indices = { 0, 1, 2, 2, 5, 1, 2, 3, 7, 2, 6, 7, 4, 5, 8, 5, 8, 9, 6, 9, 10, 10, 9, 11 };
		for (unsigned int i = 12; i < vertices.size()-2; ++i)
		{
				indices.push_back(i);
				indices.push_back(i + 1);
			if (vertices[i].coord.x >= holeCenter.x && vertices[i].coord.z >= holeCenter.y &&
			vertices[i + 1].coord.x >= holeCenter.x && vertices[i + 1].coord.z >= holeCenter.y)
				indices.push_back(8);
			else if (vertices[i].coord.x <= holeCenter.x && vertices[i].coord.z >= holeCenter.y &&
			vertices[i + 1].coord.x <= holeCenter.x && vertices[i + 1].coord.z >= holeCenter.y)
				indices.push_back(7);
			else if (vertices[i].coord.x >= holeCenter.x && vertices[i].coord.z <= holeCenter.y &&
			vertices[i + 1].coord.x >= holeCenter.x && vertices[i + 1].coord.z <= holeCenter.y)
				indices.push_back(4);
			else if (vertices[i].coord.x <= holeCenter.x && vertices[i].coord.z <= holeCenter.y /*&& 
			vertices[i + 1].coord.x <= holeCenter.x && vertices[i + 1].coord.z <= holeCenter.y*/)
				indices.push_back(3);	
		}
		indices.push_back(vertices.size() - 2);
		indices.push_back(vertices.size() - 1);
		indices.push_back(8);
		indices.push_back(vertices.size()-1);
		indices.push_back(12);
		indices.push_back(8);
	}
	
	//for (auto v : indices) {
	//	std::cout << v << std::endl;
	//}
	drawingMode = GL_TRIANGLES;
}