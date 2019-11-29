#include "Core.h"
#include "Transform.h"
#include "MeshComponent.h"
#include "Entity.h"
#include "Resources.h"

std::shared_ptr<Core> Core::initialize()
{
	std::shared_ptr<Core> c = std::make_shared<Core>();
	c->self = c;

	c->resources = std::make_shared<Resources>();
	c->resources->core = c;

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

std::shared_ptr<Resources>Core::getResources()
{
	return resources;
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
