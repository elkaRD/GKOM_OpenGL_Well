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
	
}

void GameScene::render()
{
	rootObject->renderObject(glm::mat4());
}

void GameScene::update(float delta)
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

void GameScene::setTransform(glm::mat4 trans)
{
	GLuint transformLoc = glGetUniformLocation(shader->get_programID(), "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
}

GameObject* GameScene::generateObject()
{
	return generateObject(rootObject);
}

GameObject* GameScene::generateObject(GameObject *parent) //TODO: generateObject -> regirsterObject
{
	if (parent == nullptr) throw std::exception("tried to create gameobject without parent");

	GameObject *gameObject = new GameObject(parent, this);
	gameObjects.push_back(gameObject);
	gameObject->startObject();
	return gameObject;
}

void GameScene::cleanObjects()
{
	rootObject->destroy(); //TODO: add destroyObject method
}

void GameScene::registerObject(GameObject *gameObject)
{
	gameObjects.push_back(gameObject);
	toStart.push_back(gameObject); //TODO: every frame call start method on all objects from this vector (then remove object from the vector)
}