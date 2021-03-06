#pragma once
#include "GL/glew.h"
#include "Component.h"
#include <glm/glm.hpp>
#include <memory>
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/**
* \ brief Class implementing Camera as a component feature for BlueEngine. Core has an instance for individual cameras to implement multiple cameras for the future.
*
*/
class Camera:public Component
{
public:
	Camera();
	~Camera();

	void onInit();

	glm::mat4 viewMatrix;

	glm::mat4 projMatrix;

	glm:: mat4 getProjMat();

	glm::mat4  getViewMat();

	float cameraX, cameraY;

	void ChangeCameraAngleX(float value) { cameraX += value; }
	void ChangeCameraAngleY(float value) { cameraY += value; }
	void onUpdate();
	
};
