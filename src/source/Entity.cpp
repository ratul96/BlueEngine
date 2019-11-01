#include "Entity.h"

Entity::~Entity()
{

}

std::shared_ptr<MeshComponent> Entity::getTransform()
{
	return std::shared_ptr<MeshComponent>();
}

void Entity:: onUpdate()
{
	
	for (int i=0;i<components.size();i++)
	{
		components.at(i)->DrawTriangle();
	}
}

