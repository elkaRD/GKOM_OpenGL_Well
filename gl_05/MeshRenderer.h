#ifndef MESH_RENDERER_H
#define MESH_RENDERER_H

#include <stdlib.h>
#include <vector>
#include <GL/glew.h>
#include "Vertex.h"

template < typename T, size_t N >
size_t countof(T(&arr)[N])
{
	return std::extent< T[N] >::value;
}

class MeshRenderer
{
public:

	void start();
	void render() const;

protected:
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	int drawingMode;

	virtual void initializeMeshVertices() = 0;

private:
	GLuint VBO, EBO, VAO;
};

#endif