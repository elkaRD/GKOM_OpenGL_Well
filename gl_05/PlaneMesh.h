#ifndef PLANE_MESH_H
#define PLANE_MESH_H

#include "MeshRenderer.h"

class PlaneMesh : public MeshRenderer
{
public:
	PlaneMesh();
protected:
	virtual void initializeMeshVertices(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, GLenum& drawingMode);
private:
	static const unsigned int HOLE_SEG = 24;

	GLfloat length;
	GLfloat width;
	glm::vec2 holeCenter;
	GLfloat holeRadius;

	glm::vec3 color;
};

#endif // !PLANE_MESH_H
