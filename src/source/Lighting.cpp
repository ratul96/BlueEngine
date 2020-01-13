#include "Lighting.h"
#include "Entity.h"
#include "Core.h"
#include "Environment.h"

void Lighting::onInit()
{
	getEntity()->getCore()->lights.push_back(getEntity()->getComponent<Lighting>());
}

glm::vec3 Lighting::getColour()
{
	objectColour=glm::vec3(1.0f, 0.5f, 0.31f);
	return objectColour;
}
glm::vec3 Lighting::getLightColour()
{
	lightColour = glm::vec3(1.0f, 1.0f, 1.0f);
	return lightColour;
}

void Lighting::setLightPosition()
{
	lightPosition.x = sin(SDL_GetTicks()) * 1.2f;
	lightPosition.y = -0.3f;
	lightPosition.z= cos(SDL_GetTicks()) * 1.5f;
}
glm::vec3 Lighting::getLightPosition()
{
	return lightPosition;
}