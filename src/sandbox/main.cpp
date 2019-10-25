#include "source/blueengine.h"

#include <iostream>
#include <memory>



int main()
{
	std::shared_ptr<Core> core = Core::initialize();

	std::shared_ptr<Entity> entity = core->addEntity();
	


	//std::shared_ptr<Component> tr = entity->addComponent<Component>();
	std::shared_ptr<TriangleRenderer> tr = entity->addComponent<TriangleRenderer>();

	core->run();

	return 0;
}
