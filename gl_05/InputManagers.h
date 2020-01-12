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
	void mousePosChanged(int x, int y);
	int getDeltaX();
	int getDeltaY();
private:
	int lastX;
	int lastY;

	int deltaX;
	int deltaY;

	bool firstUpdate;
};

#endif