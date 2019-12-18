#pragma once
#include "GL/glew.h"
#include "Component.h"
#include <glm/glm.hpp>
#include <memory>
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera:public Component
{
public:
	Camera();
	~Camera();

	void onInit();

	glm::mat4 viewMatrix;

	glm::mat4 projMatrix;

	glm:: mat4 getProjection();

	glm::mat4  getViewMatrix();

	float cameraX, cameraY;

};
