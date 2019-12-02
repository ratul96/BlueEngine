#pragma once
#include "GL/glew.h"
#include "Component.h"
#include<glm/glm.hpp>
#include<sr1/memory>
#include<iostream>

class Camera::public Component
{
	Camera();
	~Camera();

	glm::mat4 viewMatrix;

	glm::mat4 projMatrix;

	glm:: mat4 getProjection();

	glm::mat4  getViewMatrix();
	


};