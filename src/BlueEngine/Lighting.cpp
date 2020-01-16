#include "Lighting.h"
#include "Entity.h"
#include "Core.h"
#include "Resources.h"
#include "Environment.h"
#include "Transform.h"
#include "Camera.h"

void Lighting::onInit()
{
	getEntity()->getCore()->lights.push_back(getEntity()->getComponent<Lighting>());
	shader = getCore()->getResources()->load<Shaders>(getCore()->getEnvironment()->getRootDirectory() + "\\Shaders.txt");
}

glm::vec3 Lighting::getColour()
{
	objectColour=glm::vec3(1.0f, 0.5f, 0.31f);
	return objectColour;
}
glm::vec3 Lighting::getLightColour()
{
	lightColour = glm::vec3(0.0f, 0.0f, 0.0f);
	return lightColour;
}

void Lighting::setLightPosition()
{
	lightPosition.x = sin((getEntity()->getCore()->getEnvironment()->getDeltaTime())*SDL_GetTicks()) * 1.2f;
	lightPosition.y = -0.3f;
	lightPosition.z= cos((getEntity()->getCore()->getEnvironment()->getDeltaTime())*SDL_GetTicks()) * 1.5f;
}
glm::vec3 Lighting::getLightPosition()
{
	return lightPosition;
	
}
void Lighting::onDisplay()
{
	
	shader->sh->setUniform("lightPos", getLightPosition());
	shader->sh->setUniform("lightColor", vec3(0, 0, 2));
	shader->sh->setUniform("objectColor", getColour());
	
}