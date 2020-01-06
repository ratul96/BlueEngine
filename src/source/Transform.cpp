#include "Transform.h"
#include <SDL2/SDL.h>
Transform::Transform()
{

}
Transform::~Transform()
{

}

void Transform::SetRotation(float x, float y, float z)
{
	rotation = glm::vec3(x, y, z);
}

void Transform::Update()
{
/*
	rotation.y += deltaTs * 0.5f;
	while (rotation.y > (3.14159265358979323846 * 2.0))
	{
		rotation.y -= (float)(3.14159265358979323846 * 2.0);
	}
*/
}
void Transform:: SetPosition(float positionX, float positionY, float positionZ)
{
	position.x = positionX;
	position.y = positionY;
	position.z = positionZ;
}

glm::mat4 Transform::getInvModelMat()
{
	invmodelMatrix = glm::rotate(glm::mat4(1.0f), -rotation.y, glm::vec3(0, 1, 0));

	return invmodelMatrix;

}

glm::mat4 Transform::getModelMat()
{
	// TODO

	glm::mat4 rtn(1.0f);

	rtn = glm::translate(rtn, position);
	rtn= glm::scale(rtn, glm::vec3(1));
	rtn = glm::rotate(rtn, rotation.y, glm::vec3(0, 1, 0));
	rtn = glm::rotate(rtn, rotation.x, glm::vec3(1, 0, 0));
	rtn = glm::rotate(rtn, rotation.z, glm::vec3(0, 0, 1));
	


	return rtn;
}
glm::vec3 Transform::GetPosition()
{
	return position;
}