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
/**
* \ return type NULL. Function to call on each Components' Update by looping through each entity within its Update.
*
*/
void Entity::onUpdate()
{
	for (int i = 0; i < components.size(); i++)
	{
		components.at(i)->onUpdate();
	}
}
/**
* \ return type NULL. Function to call on each Components' Display by looping through each entity within its Display.
*
*/
void Entity::onDisplay()
{
	for (int i=0;i<components.size();i++)
	{
		components.at(i)->onDisplay();
	}
}
/**
* \ return type NULL. Function to call on each Components' GUI by looping through each entity within its Graphical User Interface.
*
*/
void Entity::onGui()
{
	for (int i = 0; i < components.size(); i++)
	{
		components.at(i)->onGui();
	}
}
/**
* \ return type shared pointer of type Core.
*
*/
std::shared_ptr<Core>Entity::getCore()
{
	return core.lock();
}

