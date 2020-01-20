#include "InputManagers.h"

void KeyboardManager::nextFrame()
{
	for (auto &it : keysPressed)
		it.second = false;
}

void KeyboardManager::keyStateChanged(int key, int state)
{
	if (state != GLFW_PRESS && state != GLFW_RELEASE) return;

	keysStates[key] = state == GLFW_PRESS;
	if (state == GLFW_PRESS) keysPressed[key] = true;
}

bool KeyboardManager::isHold(int key)
{
	return keysStates[key] || keysPressed[key];
}

bool KeyboardManager::wasPressed(int key)
{
	return keysPressed[key];
}

MouseManager::MouseManager() : firstUpdate(true)
{

}

void MouseManager::nextFrame()
{
	deltaX = 0;
	deltaY = 0;
}

void MouseManager::mousePosChanged(double x, double y)
{
	deltaX = x - lastX;
	deltaY = y - lastY;
	lastX = x;
	lastY = y;

	if (firstUpdate)
	{
		deltaX = 0;
		deltaY = 0;
		firstUpdate = false;
	}
}

double MouseManager::getDeltaX()
{
	return deltaX;
}

double MouseManager::getDeltaY()
{
	return deltaY;
}