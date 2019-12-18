#include "Entity.h"





void Entity::onInit()
{
	for (int i = 0; i < components.size(); i++)
	{
		components.at(i)->onInit();
	}
}

void Entity::onUpdate(float deltaTs)
{
	for (int i = 0; i < components.size(); i++)
	{
		components.at(i)->onUpdate(deltaTs);
	}
}
void Entity::onDisplay()
{
	for (int i=0;i<components.size();i++)
	{
		components.at(i)->onDisplay();
	}
}

std::shared_ptr<Core>Entity::getCore()
{
	return core.lock();
}

