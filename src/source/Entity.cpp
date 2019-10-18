#include "Entity.h"

Entity::Entity()
{

}
Entity::~Entity()
{

}
std::shared_ptr<Component>Entity::updateEntityComponents()
{
	std::shared_ptr<Component>c = std::make_shared<Component>();
	components.push_back(c);
	return c;


}