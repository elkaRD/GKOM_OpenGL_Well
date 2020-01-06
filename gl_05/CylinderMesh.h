#ifndef CYLINDER_MESH_H
#define CYLINDER_MESH_H

#include "MeshRenderer.h"


class CylinderMesh : public MeshRenderer {
public:

protected:
	virtual void initializeMeshVertices(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, GLenum& drawingMode);
private:
	static const unsigned int DEFAULT_SEGMENTS_NUMBER = 18;
	static const unsigned int DEAFULT_LAYERS_NUMBER = 3;
};

#endif // !CYLINDER_MESH_H