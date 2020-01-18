#include "GameScene.h"

GameScene::GameScene(ShaderProgram *shader, ShaderProgram *shader2) : shader(shader), shader2(shader2)
{
	rootObject = new GameObject(this);
	rootObject->start();
}

GameScene::~GameScene()
{
	rootObject->destroy();
	delete rootObject;
}

void GameScene::startScene()
{
	start();
}

void GameScene::destroyScene()
{
	destroy();
}

void GameScene::start()
{
	
}

void GameScene::render()
{
	rootObject->renderObject(glm::mat4(), shader, shader2);
}

void GameScene::update(float delta)
{
	
}

void GameScene::destroy()
{

}

void GameScene::updateScene(float delta)
{
	rootObject->updateObject(delta);
	update(delta);
}

ShaderProgram* GameScene::getShader()
{
	return shader;
}

ShaderProgram* GameScene::getShader2()
{
	return shader2;
}

void GameScene::setTransform(glm::mat4 trans)
{
	shader->Use();
	GLuint transformLoc = glGetUniformLocation(shader->get_programID(), "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
	shader2->Use();
	transformLoc = glGetUniformLocation(shader2->get_programID(), "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
}

void GameScene::registerObject(GameObject *gameObject)
{
	gameObjects.push_back(gameObject);
}