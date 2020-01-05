#ifndef MESH_RENDERER_H
#define MESH_RENDERER_H

#include <stdlib.h>
#include <vector>
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

private:
	GLuint VBO, EBO, VAO;
	GLenum drawingMode;
	GLsizei indicesSize;
};

#endif