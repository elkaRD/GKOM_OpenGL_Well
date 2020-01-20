#ifndef MESH_RENDERER_H
#define MESH_RENDERER_H

#include <stdlib.h>
#include <vector>
#include <limits>
#include <GL/glew.h>
#include "Vertex.h"

class MeshRenderer
{
public:
	MeshRenderer();

	void init();
	void start();
	void render(GLuint cubemapTexture) const;
	void destroy();

	//methods to modify meshes before sending them to GPU
	virtual void scaleVertices(float x, float y, float z);
	virtual void scaleVertices(float s);
	virtual void colorVertices(glm::vec3 color);
	virtual void verticalInterpolationScale(float lowerScale, float upperScale);

	void setColor(float r, float g, float b);
	void setLight();
	bool getLight();
	void setWater();
	bool getWater();

protected:
	
	std::vector<Vertex> *vertices;
	std::vector<Vertex> getVertices();
	virtual void initializeMeshVertices(std::vector<Vertex> &vertices, std::vector<GLuint> &indices, GLenum &drawingMode) = 0;

private:
	GLuint VBO, EBO, VAO, skyboxVAO, cucubemapTexture;
	GLenum drawingMode;
	GLsizei indicesSize;

	
	std::vector<GLuint> *indices;

	float lerp(float b, float e, float s);
	float reversedLerp(float b, float e, float x);
	bool isLight, isWater;
};

#endif