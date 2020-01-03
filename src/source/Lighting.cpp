#include "Lighting.h"
#include "Entity.h"
#include "Core.h"

void Lighting::onInit()
{
	getEntity()->getCore()->lights.push_back(getEntity()->getComponent<Lighting>());
	
	
}

glm::vec3 Lighting::getColour()
{
	lightColour = glm::vec3(1.0f, 1.0f, 1.0f);
	return objectColour;
}
glm::vec3 Lighting::getLightColour()
{
	objectColour = glm::vec3(1.0f, 0.5f, 0.31f);
	return lightColour;
}

void Lighting::setLightPosition(float x, float y, float z)
{
	lightPosition.x = x;
	lightPosition.y = y;
	lightPosition.z = z;
}
glm::vec3 Lighting::getLightPosition()
{
	return lightPosition;
}