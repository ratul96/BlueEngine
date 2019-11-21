#include "Core.h"
#include "Transform.h"

std::shared_ptr<Core> Core::initialize()
{
	std::shared_ptr<Core> c = std::make_shared<Core>();
	c->self = c;
	return c;
}

std::shared_ptr<Entity> Core::addEntity()
{
	std::shared_ptr<Entity> rtn = std::make_shared<Entity>();

	rtn->self = rtn;
	rtn->core = self;

	entities.push_back(rtn);

	rtn->addComponent<Transform>();

	return rtn;
}

void Core::run()
{
	while (true)
	{
		// go through.. call update

		for (int i = 0; i < entities.size(); i++)
		{
			entities.at(i)->onUpdate();
		}

		for (int i = 0; i < entities.size(); i++)
		{
			entities.at(i)->onInit();
		}

		for (int i = 0; i < entities.size(); i++)
		{
			entities.at(i)->onDisplay();
		}
	}
}
