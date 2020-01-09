#include "GameScene.h"

GameScene::GameScene(ShaderProgram *shader) : shader(shader)
{
	rootObject = new GameObject(nullptr, this);
	rootObject->start();
}

GameScene::~GameScene()
{
	rootObject->destroy();
	delete rootObject;
}

void GameScene::start()
{
	//GameObject *go = new GameObject(rootObject, this);
	
}

void GameScene::render()
{
	rootObject->renderObject(glm::mat4());
}

void GameScene::update(float delta)
{
	rootObject->update(delta);
}

ShaderProgram* GameScene::getShader()
{
	return shader;
}

void GameScene::setTransform(glm::mat4 trans)
{
	GLuint transformLoc = glGetUniformLocation(shader->get_programID(), "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
}