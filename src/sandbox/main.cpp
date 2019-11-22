#include "source/blueengine.h"

#include <iostream>
#include <memory>



int main()
{
	std::shared_ptr<Core> core = Core::initialize();

	std::shared_ptr<Entity> entity = core->addEntity();
	
	std::shared_ptr<Renderer> tr = entity->addComponent<Renderer>();

	// TODO
	entity->getComponent<Transform>()->SetPosition(0, 0, -10);
	

	core->run();

	return 0;
}
