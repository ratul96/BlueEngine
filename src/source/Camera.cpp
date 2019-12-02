#include "Camera.h"



Camera::Camera()
{

}
Camera::~Camera()
{

}
void Camera::getProjection()
{
	projMatrix = glm::perspective(45.0f, 1.0f, 0.1f, 1000f);

	return projMatrix;
}
void Camera::getViewMatrix()
{

}