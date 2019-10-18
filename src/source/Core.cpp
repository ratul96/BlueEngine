#include "Core.h"
std::shared_ptr<Core> Core::initialize()
{
	std::shared_ptr<Core> c = std::make_shared<Core>();
	return c;
}
std::shared_ptr<Entity> Core::addEntity()
{
	std::shared_ptr<Entity> e = std::make_shared<Entity>();
	entities.push_back(e);
	return e;
}
void Core::runEntityComponents()
{
	
}