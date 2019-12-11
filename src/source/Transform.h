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
	
	glm::vec3 rotation;

	glm:: vec3 scale;

	glm::mat4 modelMatrix;

	glm::mat4 getModelMat()
	{
		// TODO
		
		modelMatrix = glm::translate(glm::mat4(1.0f), position);
		modelMatrix = glm::rotate(modelMatrix, rotation.y, glm::vec3(0, 1, 0));

		return modelMatrix;
	}

	
	// rotation
	// scale
	//return m;

	
};
