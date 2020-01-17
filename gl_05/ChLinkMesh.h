#ifndef CH_LINK_MESH_H
#define CH_LINK_MESH_H

#include "MeshRenderer.h"


class ChLinkMesh : public MeshRenderer {
public:
	ChLinkMesh();
	ChLinkMesh(GLfloat height, GLfloat width, GLfloat radius);
protected:
	virtual void initializeMeshVertices(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, GLenum& drawingMode);
	void generateVertices(std::vector<Vertex>& vertices);
	void generateIndices(std::vector<Vertex>& vertices, std::vector<GLuint>& indices);
private:
	static const unsigned int DEFAULT_SEGMENTS_NUMBER = 12;

	GLfloat height;
	GLfloat width;
	GLfloat radius;

	GLuint segments;

	glm::vec3 color;

};

#endif // !CH_LINK_MESH_H



