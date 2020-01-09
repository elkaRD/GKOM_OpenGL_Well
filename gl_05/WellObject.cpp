#include "WellObject.h"

Well::Well(GameObject *parent, GameScene *scene) : GameObject(parent, scene)
{

}

void Well::start()
{
	/*static int debug = 0;

	if (debug == 0)
	{
		meshes.push_back(new CubeMesh());
		transform.setPosition(glm::vec3(-2, 0, 0));
		transform.setRotation(glm::vec3(0, 0, 45));
		debug++;
	}
	else
	{
		meshes.push_back(new CubeMesh());
		transform.setPosition(glm::vec3(1, 1, 0));
		transform.setRotation(glm::vec3(0, 30, 0));
	}*/

	meshes.push_back(new CubeMesh());
}