#include "Entity.h"




void Entity:: onUpdate()
{
	
	for (int i=0;i<components.size();i++)
	{
		components.at(i)->DrawTriangle();
	}
}
std::shared_ptr<Core>Entity::getCore()
{
	return core.lock();
}

