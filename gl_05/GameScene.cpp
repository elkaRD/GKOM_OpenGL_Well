#include "GameScene.h"

GameScene::GameScene(ShaderProgram *shader) : shader(shader)
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
	rootObject->renderObject(glm::mat4());
}

void GameScene::update(float delta)
{
	
}

void GameScene::destroy()
{

}

void GameScene::updateScene(float delta)
{
	for (auto &objectToInit : objectsToInit)
		objectToInit->startObject();

	objectsToInit.clear();

	rootObject->updateObject(delta);
	update(delta);
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

void GameScene::registerObject(GameObject *gameObject)
{
	gameObjects.push_back(gameObject);
	objectsToInit.push_back(gameObject);
}