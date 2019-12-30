#include "Camera.h"
#include "Entity.h"
#include "Transform.h"
#include "Core.h"

Camera::Camera()
{
	cameraX = 0.3f, cameraY = 1.5f;
}
Camera::~Camera()
{

}

void Camera::onInit()
{
        getEntity()->getCore()->cameras.push_back(getEntity()->getComponent<Camera>());
		cameraX = 0.3f, cameraY = 1.5f;
}

glm::mat4 Camera::getProjMat()
{
	glm::mat4 projMatrix = glm::perspective(45.0f, 1.0f, 0.1f, 100.0f);

	return projMatrix;
}
glm::mat4 Camera::getViewMat()
{
	
	/*glm::mat4 rtn=glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -3.5f));
	rtn= glm::rotate(glm::rotate(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -3.5f)), cameraX, glm::vec3(1, 0, 0)), cameraY, glm::vec3(0, 1, 0))*/;
	glm::mat4 rtn(1.0f);
	rtn = getEntity()->getComponent<Transform>()->getModelMat();
	rtn = glm::inverse(rtn);
	rtn = glm::rotate(glm::rotate(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -6.5f)), cameraX, glm::vec3(1, 0, 0)), cameraY, glm::vec3(0, 1, 0));
	return rtn;
}
