#ifndef TUBE_MESH_H
#define TUBE_MESH_H

#include "MeshRenderer.h"


class TubeMesh : public MeshRenderer {
public:
	TubeMesh();
	TubeMesh(float r, float t, float h);
protected:
	virtual void initializeMeshVertices(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, GLenum& drawingMode);
	void generateWalls(std::vector<Vertex>& vertices);
	void generateIndices(std::vector<Vertex>& vertices, std::vector<GLuint>& indices);
private:
	static const unsigned int DEFAULT_SEGMENTS_NUMBER = 24;

	GLfloat height;
	GLfloat radius;
	GLfloat wallThickness;

	GLuint segments;
	static const GLuint layers = 1;
	const char texMode;

	glm::vec2 texScale;

	glm::vec3 color;
};

#endif // !TUBE_MESH_H