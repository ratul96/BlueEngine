#include "Camera.h"



Camera::Camera()
{

}
Camera::~Camera()
{

}
glm::mat4 Camera::getProjection()
{
	projMatrix = glm::perspective(45.0f, 1.0f, 0.1f, 1000.0f);

	return projMatrix;
}
glm::mat4 Camera::getViewMatrix()
{
	viewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -3.5f));
	viewMatrix= glm::rotate(glm::rotate(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -3.5f)), cameraX, glm::vec3(1, 0, 0)), cameraY, glm::vec3(0, 1, 0));

	return viewMatrix;
}