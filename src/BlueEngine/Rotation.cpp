#include "Rotation.h"
#include "Entity.h"
/**
* \ return type NULL Function initialising the amount of rotation 
*
*/
void Rotator:: onInit()
{
	rot = 0;
}
/**
* \ return type NULL Function updating rotation of a an object
*
*/
void Rotator::onUpdate()
{
	getEntity()->getComponent<Transform>()->SetRotation(0, rot, 0);
	rot += 0.001f;
}