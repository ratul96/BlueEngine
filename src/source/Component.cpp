#include "Component.h"


Component::Component()
{
	position = new PositionComponent();
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
void Component::onDisplay()
{
	position->displayPosition();
}
