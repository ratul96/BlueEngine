#include "Entity.h"

/**
* \ return type NULL. Function to call on each Components' Initialise by looping through each entity within its Initialise.
*
*/
void Entity::onInit()
{
	for (int i = 0; i < components.size(); i++)
	{
		components.at(i)->onInit();
	}
}

void Entity::onUpdate()
{
	for (int i = 0; i < components.size(); i++)
	{
		components.at(i)->onUpdate();
	}
}

void Entity::onDisplay()
{
	for (int i=0;i<components.size();i++)
	{
		components.at(i)->onDisplay();
	}
}

void Entity::onGui()
{
	for (int i = 0; i < components.size(); i++)
	{
		components.at(i)->onGui();
	}
}

std::shared_ptr<Core>Entity::getCore()
{
	return core.lock();
}

