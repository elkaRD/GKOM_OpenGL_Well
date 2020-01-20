#ifndef INPUT_MANAGERS_H
#define INPUT_MANAGERS_H

#include <unordered_map>
#include <GLFW/glfw3.h>

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
};

class MouseManager
{
public:
	MouseManager();

	void nextFrame();
	void mousePosChanged(double x, double y);
	double getDeltaX();
	double getDeltaY();
private:
	double lastX;
	double lastY;

	double deltaX;
	double deltaY;

	bool firstUpdate;
};

#endif