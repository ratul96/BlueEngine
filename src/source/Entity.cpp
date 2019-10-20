#include "Entity.h"
std::shared_ptr<Entity>Entity::initialize()
{
	std::shared_ptr<Entity> e = std::make_shared<Entity>();
	return e;
}


void Entity:: addComponents()
{
	for (auto& c : components)
	{
		c->onDisplay();
	}
}