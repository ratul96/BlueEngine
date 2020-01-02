#include "Lighting.h"

glm::vec3 Lighting::getColour()
{
	objectColour = glm::vec3(1.0f, 0.5f, 0.31f);

	return objectColour;
}
glm::vec3 Lighting::getLightColour()
{
	lightColour = glm::vec3(1.0f, 1.0f, 1.0f);

	return lightColour;
}
glm::vec3 Lighting::getLightPosition()
{
	lightPosition = glm::vec3(1.2f, 1.0f, 2.0f);

	return lightPosition;
}