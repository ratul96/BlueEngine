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
	objectColour=glm::vec3(1.0f, 1.0f, 1.0f);
	return objectColour;
}
glm::vec3 Lighting::getLightColour()
{
	lightColour.x = sin(SDL_GetTicks()*2.0f);
	lightColour.y = sin(SDL_GetTicks()*0.7f);
	lightColour.z = sin(SDL_GetTicks()*1.3f);
	return lightColour;
}

void Lighting::setLightPosition(float x,float y)
{
	lightPosition.x = x;
	lightPosition.y = y;
	lightPosition.z=-0.3f;

	
}
glm::vec3 Lighting::getLightPosition()
{
	
	return lightPosition;
}