#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#define GLEW_STATIC
#include <GL/glew.h>
#include "shprogram.h"
#include <GLFW/glfw3.h>
#include <SOIL.h>
#include <iostream>
#include <unordered_map>
using namespace std;
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "CubeMesh.h"

class GameEngine
{
public:
	static GameEngine &getInstance();

	void init();
	void run();

private:
	static GameEngine *instance;
	GLFWwindow *window;
	ShaderProgram *theProgram;

	glm::vec3 cameraPosition;
	glm::vec2 cameraRotation;

	GameEngine();

	GLuint screenWidth = 1280, screenHeight = 720;

	void setCamera();

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	static void window_size_callback(GLFWwindow* window, int width, int height);
	static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

	void handleKeyboardEvent();
	void handleMouseEvent();
	void handleScreenResizeEvent(int widht, int height);

	GLuint LoadMipmapTexture(GLuint texId, const char* fname);

	class KeyboardManager
	{
	public:
		void nextFrame();
		void keyStateChanged(int key, int state);
		bool isHold(int key);
		bool wasPressed(int key);

	private:
		std::unordered_map<int, bool> keysStates;
		std::unordered_map<int, bool> keysPressed;
	} keyboardManager;

	class MouseManager
	{
	public:
		MouseManager();

		void nextFrame();
		void mousePosChanged(int x, int y);
		int getDeltaX();
		int getDeltaY();
	private:
		int lastX;
		int lastY;

		int deltaX;
		int deltaY;

		bool firstUpdate;
	} mouseManager;
};

#endif