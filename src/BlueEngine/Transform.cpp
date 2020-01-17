#include "Transform.h"
#include <SDL2/SDL.h>

Transform::Transform()
{

}
Transform::~Transform()
{

}
/**
* \ return type NULL Function setting rotation of a an object
*
*/
void Transform::SetRotation(float x, float y, float z)
{
	rotation = glm::vec3(x, y, z);
}
/**
* \ return type NULL Function setting position of a an object
*
*/
void Transform:: SetPosition(float positionX, float positionY, float positionZ)
{
	position.x = positionX;
	position.y = positionY;
	position.z = positionZ;
}
/**
* \ return type Mat4 Function to return Inverse Model Matrix
*
*/
glm::mat4 Transform::getInvModelMat()
{
	invmodelMatrix = glm::rotate(glm::mat4(1.0f), -rotation.y, glm::vec3(0, 1, 0));

	return invmodelMatrix;

}
/**
* \ return type Mat4 Function to return Model Matrix
*
*/
glm::mat4 Transform::getModelMat()
{

	glm::mat4 rtn(1.0f);

	rtn = glm::translate(rtn, position);
	rtn= glm::scale(rtn, glm::vec3(1));
	rtn = glm::rotate(rtn, rotation.y, glm::vec3(0, 1, 0));
	rtn = glm::rotate(rtn, rotation.x, glm::vec3(1, 0, 0));
	rtn = glm::rotate(rtn, rotation.z, glm::vec3(0, 0, 1));
	
	return rtn;
}
/**
* \ return type Vector 3 Function to return Position that is set
*
*/
glm::vec3 Transform::GetPosition()
{
	return position;
}