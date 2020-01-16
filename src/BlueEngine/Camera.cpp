#include "Camera.h"
#include "Entity.h"
#include "Transform.h"
#include "Core.h"
#include "Environment.h"

Camera::Camera()
{
	cameraX = 0.3f, cameraY = 1.5f;
}
Camera::~Camera()
{

}
/**
* \ brief Initialising and adding individual camera to be instantiated within core. Virtual function for the component being inherited from Component class.
*
*/
void Camera::onInit()
{
        getEntity()->getCore()->cameras.push_back(getEntity()->getComponent<Camera>());
		cameraX = 0.3f, cameraY = 1.5f;
}
/**
* \ return Projection Matrix for the perspective of the camera
*
*/
glm::mat4 Camera::getProjMat()
{
	glm::mat4 projMatrix = glm::perspective(45.0f, 1.0f, 0.1f, 100.0f);

	return projMatrix;
}
/**
* \ return View Matrix for the perspective of the camera
*
*/
glm::mat4 Camera::getViewMat()
{
	glm::mat4 rtn(1.0f);
	rtn = getEntity()->getComponent<Transform>()->getModelMat();
	rtn = glm::inverse(rtn);
	rtn = glm::rotate(glm::rotate(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -10.5f)), cameraX, glm::vec3(1, 0, 0)), cameraY, glm::vec3(0, 1, 0));
	return rtn;
}
/**
* \ return null for updating Camera with key press. Virtual function for the component being inherited from Component class.
*
*/
void Camera::onUpdate()
{
	if (getCore()->getKeyboard()->getKey(SDLK_LEFT))
	{
		std::cout << "working" << std::endl;
		getCore()->getKeyboard()->clearKeys();
	}
	
	if (getCore()->getKeyboard()->getKey(SDLK_RIGHT))
	{
		std::cout << "Right Working" << std::endl;
		ChangeCameraAngleY(getCore()->getEnvironment()->getDeltaTime()*5.0f);
		getCore()->getKeyboard()->clearKeys();
	}
}
