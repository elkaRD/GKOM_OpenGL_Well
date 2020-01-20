#include "Bench.h"
#include "CubeMesh.h"

Bench::Bench(GameObject* parent): GameObject(parent)
{}

void Bench::start()
{
	
	//for (auto i = 0; i < 2; ++i)
	//{
		GameObject* leg = new GameObject(this);
		MeshRenderer* mesh = new CubeMesh();
		leg->addMesh(mesh);
		GameObject* leg1 = new GameObject(this);
		MeshRenderer* mesh1 = new CubeMesh();
		leg->addMesh(mesh);
		leg->transform.translate(2.0f - 4.0 * 1, 0.0f, 0.4f);
		leg1->transform.translate(2.0f - 4.0 * 1, 0.0f, -0.4f);
	//}

	//MeshRenderer* mesh = new CubeMesh(5.0f, 0.1f, 0.4f);
	//addMesh(mesh);
}

void Bench::update(float delta)
{

}
