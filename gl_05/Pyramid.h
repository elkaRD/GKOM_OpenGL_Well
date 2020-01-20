#ifndef PYRAMID_H
#define PYRAMID_H

#include "MeshRenderer.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Pyramid : public MeshRenderer
{
public:
	Pyramid(int sides, float h, float r);

protected:
	void initializeMeshVertices(std::vector<Vertex> &vertices, std::vector<GLuint> &indices, GLenum &drawingMode);

private:
	const int sides;
	const float H;
	const float R;
};

#endif