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
	
	
	GLuint positionsVboId ;

	GLuint colorsVboId;

	//void createVBO();

	
	


	glm::vec3 position;
	
	glm::vec3 rotation;

	glm:: vec3 scale;

	glm::mat4 modelMatrix;

	glm::mat4 getModelMat()
	{
		// TODO
		position = glm::vec3(0, 0, -10);
		modelMatrix = glm::translate(glm::mat4(1.0f), position);

		return modelMatrix;
	}

	
	// rotation
	// scale
	//return m;

	
};
