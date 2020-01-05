#ifndef CUBE_MESH_H
#define CUBE_MESH_H

#include "MeshRenderer.h"

class CubeMesh : public MeshRenderer
{
public:

protected:
	virtual void initializeMeshVertices(std::vector<Vertex> &vertices, std::vector<GLuint> &indices, GLenum &drawingMode);

private:

};

#endif