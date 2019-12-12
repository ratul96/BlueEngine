#include "Component.h"
#include "Mesh.h"



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
void Component::onaudioInit() {}


std::shared_ptr<Entity> Component::getEntity()
{
	return entity.lock();
}
/*std::shared_ptr<Resources>Component::getResources()
{
	 return getEntity()->getCore()->getResources();
}*/
