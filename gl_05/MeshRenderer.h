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

	void start();
	void render() const;
	void destroy();

protected:
	
	virtual void initializeMeshVertices(std::vector<Vertex> &vertices, std::vector<GLuint> &indices, GLenum &drawingMode) = 0;

	//methods to use in overridden initializeMeshVertices() method:
	void scaleVertices(std::vector<Vertex> &vertices, float x, float y, float z);
	void verticalInterpolationScale(std::vector<Vertex> &vertices, float lowerScale, float upperScale);

private:
	GLuint VBO, EBO, VAO;
	GLenum drawingMode;
	GLsizei indicesSize;

	float lerp(float b, float e, float s);
};

#endif