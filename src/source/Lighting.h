#pragma once
#include "GL/glew.h"
#include "Component.h"
#include <glm/glm.hpp>

class Lighting :public Component
{
public:
	glm::vec3 objectColour;

	glm::vec3 getColour();

	glm::vec3 lightColour;

	glm::vec3 getLightColour();

	glm::vec3 lightPosition;

	glm::vec3 getLightPosition();
};