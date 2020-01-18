#ifndef MESH_RENDERER_H
#define MESH_RENDERER_H

#include <stdlib.h>
#include <vector>
#include <limits>
#include <GL/glew.h>
#include "Vertex.h"

class MeshRenderer
{
public:
	MeshRenderer();

	void init();
	void start();
	void render() const;
	void destroy();

	//methods to use in overridden initializeMeshVertices() method:
	void scaleVertices(float x, float y, float z);
	void scaleVertices(float s);
	void verticalInterpolationScale(float lowerScale, float upperScale);
	void setColor(float r, float g, float b);
	void setLight();
	bool getLight();

protected:
	
	virtual void initializeMeshVertices(std::vector<Vertex> &vertices, std::vector<GLuint> &indices, GLenum &drawingMode) = 0;

private:
	GLuint VBO, EBO, VAO;
	GLenum drawingMode;
	GLsizei indicesSize;

	std::vector<Vertex> *vertices;
	std::vector<GLuint> *indices;

	float lerp(float b, float e, float s);
	float reversedLerp(float b, float e, float x);
	bool isLight;
};

#endif