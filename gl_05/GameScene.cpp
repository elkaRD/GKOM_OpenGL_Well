#include "GameScene.h"

GameScene::GameScene()
{
	rootObject = new GameObject(nullptr);
}

GameScene::~GameScene()
{
	delete rootObject;
}

void GameScene::render()
{
	rootObject->render();
}

void GameScene::update(float delta)
{
	rootObject->update(delta);
}