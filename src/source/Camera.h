#pragma once
#include "GL/glew.h"
#include "Component.h"
#include<glm/glm.hpp>
#include<sr1/memory>
#include<iostream>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>

class Camera:public Component
{
public:
	Camera();
	~Camera();

	glm::mat4 viewMatrix;

	glm::mat4 projMatrix;

	glm:: mat4 getProjection();

	glm::mat4  getViewMatrix();

	float cameraX, cameraY;
	


};