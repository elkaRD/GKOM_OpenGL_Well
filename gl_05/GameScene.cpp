#include "GameScene.h"

GameScene::GameScene()
{
	rootObject = new GameObject(nullptr);
	rootObject->start();
}

GameScene::~GameScene()
{
	rootObject->destroy();
	delete rootObject;
}

void GameScene::start()
{
	GameObject *go = new GameObject(rootObject);
	
}

void GameScene::render()
{
	rootObject->render();
}

void GameScene::update(float delta)
{
	rootObject->update(delta);
}