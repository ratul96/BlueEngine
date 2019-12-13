#include "source/blueengine.h"
#include "Renderer.h"
#include <iostream>
#include <memory>



int main()
{
	std::shared_ptr<Core> core = Core::initialize();

	std::shared_ptr<Entity> entity = core->addEntity();
	
	std::shared_ptr<Renderer> tr = entity->addComponent<Renderer>();
	//call load function here
	//core->getContext()->createMesh();
	std::shared_ptr<MeshComponent>me = core->getResources()->load<MeshComponent>("W:/gep_sdk-20191121/gep_sdk/BlueEngine/curuthers.obj");
	// TODO
	tr->setMesh(me);
	entity->getComponent<Transform>()->SetPosition(0, 0, -10);
	

	core->run();

	return 0;
}
