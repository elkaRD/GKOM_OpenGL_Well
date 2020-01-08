#ifndef CYLINDER_MESH_H
#define CYLINDER_MESH_H

#include "MeshRenderer.h"


class CylinderMesh : public MeshRenderer {
public:
	CylinderMesh();
protected:
	virtual void initializeMeshVertices(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, GLenum& drawingMode);
private:
	static const unsigned int DEFAULT_SEGMENTS_NUMBER = 24;
	static const unsigned int DEFAULT_LAYERS_NUMBER = 1;

	GLfloat height;
	GLfloat radius;

	GLuint segments;
	GLuint layers;

	glm::vec3 color;

	void generatePlate(std::vector<Vertex>& vertices, bool top);
	void generateWalls(std::vector<Vertex>& vertices);
	void generateIndices(std::vector<Vertex>& vertices, std::vector<GLuint>& indices);
};

#endif // !CYLINDER_MESH_H