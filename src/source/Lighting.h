#pragma once
#include "GL/glew.h"
#include "Component.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Lighting :public Component
{
public:
	void onInit();
	glm::vec3 objectColour;

	glm::vec3 getColour();

	glm::vec3 lightColour;

	glm::vec3 getLightColour();

	glm::vec3 lightPosition;

	void setLightPosition(float x,float y,float z);

	glm::vec3 getLightPosition();
};