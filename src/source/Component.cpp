#include "Component.h"
#include "Mesh.h"
#include "Entity.h"


Component::Component()
{
	
}
Component::~Component()
{

}
/*void Component::onInit()
{
	std::cout << "Initialize window here" << std::endl;
}
void Component::onBegin()
{
	std::cout << "Began" << std::endl;
}*/

void Component::onUpdate() { }
void Component::onInit() { }
void Component::onDisplay() { }



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