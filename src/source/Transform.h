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

	void SetPosition(float positionX, float positionY, float positionZ);

	glm::vec3 GetPosition();

	void SetRotation(float x, float y, float z);
	
	glm::vec3 rotation;

	glm:: vec3 scale;

	glm::mat4 modelMatrix;

	glm::mat4 invmodelMatrix;

	glm::mat4 getModelMat();

	glm::mat4 getInvModelMat();

	void Update();
	
	
};
