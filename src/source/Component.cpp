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
void Component::DrawTriangle()
{
	 
}

std::shared_ptr<Entity> Component::getEntity()
{
	return entity.lock();
}
