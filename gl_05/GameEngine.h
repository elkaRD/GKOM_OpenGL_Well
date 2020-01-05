#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#define GLEW_STATIC
#include <GL/glew.h>
#include "shprogram.h"
#include <GLFW/glfw3.h>
#include <SOIL.h>
#include <iostream>
using namespace std;
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "CubeMesh.h"

class GameEngine
{
public:
	static GameEngine &getInstance();

	int init();
	void run();

private:
	static GameEngine *instance;

	GameEngine();

	const GLuint WIDTH = 800, HEIGHT = 600;

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
	GLuint LoadMipmapTexture(GLuint texId, const char* fname);
};

#endif