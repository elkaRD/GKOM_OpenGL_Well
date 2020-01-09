#include "WellScene.h"

WellScene::WellScene(ShaderProgram *shader) : GameScene(shader)
{

}

void WellScene::start()
{
	well = new Well(rootObject);
	well->transform.setPosition(-2, 0, 0);

	well2 = new Well(well);
	well2->transform.setPosition(3, 0, 0);
}

void WellScene::update(float delta)
{
	well->transform.translate(0.2f * delta, 0, 0);
	well->transform.rotate(15.0f * delta, 0, 0);
	well->transform.rotate(0, 0, 15.0f * delta);

	well2->transform.rotate(0, 0, 450.0f * delta);
}