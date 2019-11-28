#include "Component.h"
#include "MeshComponent.h"



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
std::shared_ptr<Resources>Component::getResources()
{
	 getEntity()->getCore()->getResources();
}
