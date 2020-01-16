#include "Component.h"
#include "Mesh.h"
#include "Entity.h"
#include "Core.h"

void Component::onUpdate() { }
void Component::onInit() { }
void Component::onDisplay() { }
void Component::onGui(){}

std::shared_ptr<Entity> Component::getEntity()
{
	return entity.lock();
}
std::shared_ptr<Core>Component::getCore()
{
	return getEntity()->getCore();
}
std::shared_ptr<Keyboard>Component::getKeyBoard()
{
	return getCore()->getKeyboard();
}
