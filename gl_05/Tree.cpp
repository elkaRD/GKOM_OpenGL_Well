#include "Tree.h"

Tree::Tree(GameObject *parent) : GameObject(parent)
{

}

void Tree::start()
{
	GameObject *root = new GameObject(this);
	MeshRenderer *mesh = root->addMesh(new CylinderMesh());
	mesh->scaleVertices(0.8f, 0.75f, 0.8f);
	mesh->verticalInterpolationScale(1, randomFloat(0.2f, 0.6f));
	mesh->colorVertices(glm::vec3(1) * randomFloat(0.6f, 1.0f));
	root->transform.translate(0, randomFloat(1, 2), 0);
	root->setTexture("textures/wood1.png");

	GameObject *p = this;
	int levels = 3;
	if (rand() % 3 == 0) levels = 4;
	else if (rand() % 4 == 0) levels = 5;

	for (int i = 0; i < levels; ++i)
	{
		GameObject *g = new GameObject(p);
		MeshRenderer *mesh = g->addMesh(new Pyramid(randomInt(5, 8), randomFloat(4, 5) * pow(0.8f, i), randomFloat(4, 5) * pow(0.7f, i)));
		mesh->colorVertices(glm::vec3(1) * randomFloat(0.9f, 1.2f));
		g->transform.translate(0, randomFloat(2.5f, 3.0f) * pow(0.85f, i), 0);
		g->setTexture("textures/leaves.jpg");
		treeLayers.push_back(g);

		p = g;
	}

	minAngle = randomFloat(-10, 5);
	maxAngle = randomFloat(5, 30);
	swayDuration = randomFloat(4, 6);
	swayTime = randomFloat(0, 5);
}

void Tree::update(float delta)
{
	swayTime += delta;

	if (swayTime > swayDuration)
	{
		swayTime -= swayDuration;
	}

	float d = maxAngle - minAngle;
	d *= (sinf(2 * (float) M_PI * swayTime / swayDuration) + 1) / 2;

	float multiplier = 0.1f;

	for (unsigned int i = 0; i < treeLayers.size(); ++i)
	{
		treeLayers[i]->transform.setRotation(0, 0, (d + minAngle) * multiplier);
		multiplier *= 1.3f;
	}
}