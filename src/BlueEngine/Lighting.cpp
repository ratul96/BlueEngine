#include "Lighting.h"
#include "Entity.h"
#include "Core.h"
#include "Resources.h"
#include "Environment.h"
#include "Transform.h"
#include "Camera.h"
/**
* \ brief Initialising and adding individual Light to be instantiated within core. Virtual function for the component being inherited from Component class.
*         Loading appropriate shaders from root directory
*/
void Lighting::onInit()
{
	getEntity()->getCore()->lights.push_back(getEntity()->getComponent<Lighting>());
	shader = getCore()->getResources()->load<Shaders>(getCore()->getEnvironment()->getRootDirectory() + "\\Resources\\" + "\\Shaders.txt");
}
/**
* \ return Function to return Vector3 for object colour
*
*/
glm::vec3 Lighting::getColour()
{
	objectColour=glm::vec3(1.0f, 0.5f, 0.31f);
	return objectColour;
}
/**
* \ return Function to return Vector3 for light colour
*
*/
glm::vec3 Lighting::getLightColour()
{
	lightColour = glm::vec3(0.0f, 0.0f, 0.0f);
	return lightColour;
}
/**
* \ return type NULL Function for setting light position
*
*/
void Lighting::setLightPosition()
{
	lightPosition.x = sin(SDL_GetTicks()) * 2.0f;
	lightPosition.y = -0.3f;
	lightPosition.z= cos(SDL_GetTicks()) * 2.5f;
}
/**
* \ return Function to return Vector3 for light position
*
*/
glm::vec3 Lighting::getLightPosition()
{
	return lightPosition;
	
}
/**
* \ return type NULL setting uniforms for Lighting Shader
*
*/
void Lighting::onDisplay()
{
	
	shader->sh->setUniform("lightPos", getLightPosition());
	shader->sh->setUniform("lightColor", vec3(0, 0, 2));
	shader->sh->setUniform("objectColor", getColour());
	
}