#include "WellScene.h"
#include <string>

WellScene::WellScene(ShaderProgram *shader, ShaderProgram *shader2) : GameScene(shader, shader2)
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
		//int tmp = x + 10;
		//auto s = std::to_string(tmp);
		//std::string point = "pointLightsPosition[" + s + "].position";
		shader->Use();
		//glUniform3f(glGetUniformLocation(shader->get_programID(), point.c_str()), x * spaceBetweenLamps , 4, 0);
	}
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition0"), -10 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition1"), -9 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition2"), -8 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition3"), -7 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition4"), -6 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition5"), -5 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition6"), -4 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition7"), -3 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition8"), -2 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition9"), -1 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition10"), -0 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition11"), 1 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition12"), 2 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition13"), 3 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition14"), 4 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition15"), 5 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition16"), 6 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition17"), 7 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition18"), 8 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition19"), 9 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition20"), 10 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition21"), 11 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition22"), 12 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition23"), 13 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition24"), 14 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition25"), 15 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition26"), 16 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition27"), 17 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition28"), 18 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition29"), 19 * spaceBetweenLamps, 4, 0);
}

void WellScene::testObject()
{

	GameObject* test = new TestObject(rootObject);

	//GameObject* object = new TestObject(test);
	test->transform.translate(-10, 10, -10);

}