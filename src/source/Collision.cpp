#include "Collision.h"
#include "Transform.h"
#include "Core.h"
#include "Entity.h"

bool Collision::isColliding(glm::vec3 a, glm::vec3 b)
{
	collideX = false;
	collideY = false;
	collideZ = false;
	if (a.x < b.x)
	{
		if (a.x + 1 > b.x - 0.9)
		{
			collideX = true;
		}
	}
	else
	{
		if (b.x + 1 > a.x - 0.9)
		{
			collideX = true;
		}
	}
	if (a.y < b.y)
	{
		if (a.y + 1 > b.y - 0.9)
		{
			collideY = true;
		}
	}
	else
	{
		if (b.y + 1 > a.y - 0.9)
		{
			collideY = true;
		}
	}
	if (a.z < b.z)
	{
		if (a.z + 1 > b.z - 0.9)
		{
			collideZ = true;
		}
	}
	else
	{
		if (b.z + 1 > a.z - 0.9)
		{
			collideZ = true;
		}
	}
	if (collideX&&collideY&&collideZ)
	{
		return true;
	}
	return false;
}
void Collision::Collide()
{
	//If collision working GetPosition
	bool colliding = false;
	std::shared_ptr<Transform>tr = getEntity()->getComponent<Transform>();
	std::shared_ptr<Transform>trc = getEntities<Collision>()->getEntity()->getComponent<Transform>();
		if (isColliding(tr->GetPosition(), trc->GetPosition()))
		{
			colliding=true;
			std::cout<<"Collided"<<std::endl;
	    }
		
		if (!isColliding)
		{
			tr->GetPosition();
	    }
}