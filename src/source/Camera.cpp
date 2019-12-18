#include "Camera.h"
#include "Entity.h"
#include "Transform.h"
#include "Core.h"

Camera::Camera()
{

}
Camera::~Camera()
{

}

void Camera::onInit()
{
        getEntity()->getCore()->cameras.push_back(getEntity()->getComponent<Camera>());
}

glm::mat4 Camera::getProjection()
{
	glm::mat4 projMatrix = glm::perspective(45.0f, 1.0f, 0.1f, 1000.0f);

	return projMatrix;
}
glm::mat4 Camera::getViewMatrix()
{
	glm::mat4 rtn(1.0f);

	rtn = getEntity()->getComponent<Transform>()->getModelMat();
	rtn = glm::inverse(rtn);

	return rtn;
}
