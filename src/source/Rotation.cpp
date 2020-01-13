#include "Rotation.h"
#include "Entity.h"

void Rotator:: onInit()
{
	rot = 0;
}

void Rotator::onUpdate()
{
	
	getEntity()->getComponent<Transform>()->SetRotation(0, rot, 0);
	rot += 0.001f;
}