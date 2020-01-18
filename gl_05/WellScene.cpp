#include "WellScene.h"

WellScene::WellScene(ShaderProgram *shader) : GameScene(shader)
{

}

void WellScene::start()
{
	well = new Ground(rootObject);
	well->transform.setPosition(0, 0, 0);

	well2 = new Well(well);
	well2->transform.setPosition(-30, 0, -20);

	//Lamp *lamp = new Lamp(rootObject);

	//well->addChild(new TestObject(this));

	createAvenue();
	testObject();
}

void WellScene::update(float delta)
{
	//well->transform.translate(0.2f * delta, 0, 0);
	//well->transform.rotate(15.0f * delta, 0, 0);
	//well->transform.rotate(0, 0, 15.0f * delta);

	//well2->transform.rotate(0, 0, 450.0f * delta);
}

void WellScene::createAvenue()
{
	const int spaceBetweenLamps = 9;

	GameObject *avenue = new GameObject(rootObject);
	

	for (int x = -10; x <= 20; ++x)
	{
		GameObject *lamp = new Lamp(avenue);
		lamp->transform.translate(x * spaceBetweenLamps, 0, 0);
	}
}

void WellScene::testObject()
{

	GameObject* test = new TestObject(rootObject);

	//GameObject* object = new TestObject(test);
	test->transform.translate(-10, 10, -10);

}