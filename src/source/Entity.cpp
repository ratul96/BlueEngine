#include "Entity.h"

void Entity:: onDisplay()
{
	for (int i=0;i<components.size();i++)
	{
		components.at(i)->onDisplay();
	}
}

