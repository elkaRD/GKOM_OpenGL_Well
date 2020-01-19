#ifndef CUBE_MESH_H
#define CUBE_MESH_H

#include "MeshRenderer.h"

class CubeMesh : public MeshRenderer
{
public:
	CubeMesh();
	CubeMesh(float size);
	CubeMesh(float x, float y, float z);

	void scaleVertices(float x, float y, float z);
	void scaleTexCoords(int walls, float x, float y);

protected:
	virtual void initializeMeshVertices(std::vector<Vertex> &vertices, std::vector<GLuint> &indices, GLenum &drawingMode);

private:
	float x, y, z;
};

#endif