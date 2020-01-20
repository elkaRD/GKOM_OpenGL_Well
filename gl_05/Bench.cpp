#include "Bench.h"
#include "CubeMesh.h"

Bench::Bench(GameObject* parent): GameObject(parent)
{}

void Bench::start()
{
	
	for (auto i = 0; i < 2; ++i)
	{
		GameObject* leg = new GameObject(this);
		MeshRenderer* mesh = new CubeMesh(0.05f, 0.6f, 0.3f);
		leg->addMesh(mesh);
		leg->transform.translate(0.0f, -0.3f, 1.5f - 3.0 * i);
		leg->transform.rotate(0.0f, 90.0f, 0.0f);
	}

	MeshRenderer* mesh = new CubeMesh();
	addMesh(mesh);
	mesh->scaleVertices(0.5f, 0.05f, 4.0f);
	transform.translate(0.0f, 0.5f, 0.0f);
	setTexture("textures/wood1.png");
}

void Bench::update(float delta)
{

}
