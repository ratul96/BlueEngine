#include "Core.h"
std::shared_ptr<Core> Core::initialize()
{
	std::shared_ptr<Core> c = std::make_shared<Core>();
	return c;
}
void Core::addEntity()
{
	for (auto& e : entities)
	{
		e->addComponents();
	}
}
void Core::runEntityComponents()
{
	
}