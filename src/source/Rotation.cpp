#include "Rotation.h"
#include "Entity.h"

void Rotator:: onInit()
{
	rot = 0;
}

void Rotator::onUpdate(float getridofme)
{
	getEntity()->getComponent<Transform>()->SetRotation(0, rot, 0);
	rot += 0.01f;
}