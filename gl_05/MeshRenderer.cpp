#include "MeshRenderer.h"

MeshRenderer::MeshRenderer()
{
	vertices = new std::vector<Vertex>();
	indices = new std::vector<GLuint>();
	isLight = false;
}

void MeshRenderer::init()
{
	initializeMeshVertices(*vertices, *indices, drawingMode);
}

void MeshRenderer::start()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices->size() * sizeof(Vertex), &(*vertices)[0], GL_STATIC_DRAW);

	// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
	glBindVertexArray(VAO);


	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices->size() * sizeof(GLuint), &(*indices)[0], GL_STATIC_DRAW);

	// vertex geometry data
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	// vertex color data
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// vertex texture coordinates
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(GLfloat), (GLvoid*)(8 * sizeof(GLfloat)));
	glEnableVertexAttribArray(3);

	glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind

	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)
	
	indicesSize = indices->size();

	delete vertices;
	delete indices;
}

void MeshRenderer::render() const
{
	glBindVertexArray(VAO);
	glDrawElements(drawingMode, indicesSize, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void MeshRenderer::destroy()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void MeshRenderer::scaleVertices(float x, float y, float z)
{
	for (auto &vertex : *vertices)
	{
		vertex.coord[0] *= x;
		vertex.coord[1] *= y;
		vertex.coord[2] *= z;
	}
}

void MeshRenderer::scaleVertices(float s)
{
	for (auto &vertex : *vertices)
	{
		vertex.coord[0] *= s;
		vertex.coord[1] *= s;
		vertex.coord[2] *= s;
	}
}

void MeshRenderer::verticalInterpolationScale(float lowerScale, float upperScale)
{
	float maxY = std::numeric_limits<float>::min();
	float minY = std::numeric_limits<float>::max();

	for (const auto &vertex : *vertices)
	{
		if (vertex.coord[1] > maxY) maxY = vertex.coord[1];
		if (vertex.coord[1] < minY) minY = vertex.coord[1];
	}

	for (auto &vertex : *vertices)
	{
		vertex.coord[0] *= lerp(lowerScale, upperScale, reversedLerp(minY, maxY, vertex.coord[1]));
		vertex.coord[2] *= lerp(lowerScale, upperScale, reversedLerp(minY, maxY, vertex.coord[1]));
	}
}

void MeshRenderer::setColor(float r, float g, float b)
{
	for (auto &vertex : *vertices)
	{
		vertex.color[0] = r;
		vertex.color[1] = g;
		vertex.color[2] = b;
	}
}

float MeshRenderer::lerp(float b, float e, float s)
{
	return (e - b) * s + b;
}

float MeshRenderer::reversedLerp(float b, float e, float x)
{
	return (x - b) / (e - b);
}

void MeshRenderer::setLight()
{
	isLight = true;
}

bool MeshRenderer::getLight()
{
	return isLight;
}