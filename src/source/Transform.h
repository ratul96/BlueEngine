#pragma once
#include "Component.h"
#include "GL/glew.h"
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<iostream>

class Transform:public Component
{
public:
	Transform();
	~Transform();
	
	
	glm::vec3 position;

	void SetPosition(float positionX, float positionY, float positionZ)
	{
		position.x = positionX;
		position.y = positionY;
		position.z = positionZ;
	}

	void SetRotation(float x, float y, float z);
	
	glm::vec3 rotation;

	glm:: vec3 scale;

	glm::mat4 modelMatrix;

	glm::mat4 invmodelMatrix;

	glm::mat4 getModelMat()
	{
		// TODO
		
		glm::mat4 rtn(1.0f);

		rtn = glm::translate(rtn, position);
		rtn = glm::rotate(rtn, rotation.y, glm::vec3(0, 1, 0));
		// TODO: xrot
		// TODO: zrot
		// TODO: scale
		// TODO: Remember to initilize scale to 1, 1, 1 in onInit!!
		
		return rtn;
	}

	glm::mat4 getInvModelMat()
	{
		invmodelMatrix = glm::rotate(glm::mat4(1.0f), -rotation.y, glm::vec3(0, 1, 0));

		return invmodelMatrix;

	}

	void Update(float deltaTs);
	
	
};
