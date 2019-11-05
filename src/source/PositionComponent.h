#pragma once
#include "Component.h"
#include "GL/glew.h"
#include<glm/glm.hpp>
#include<iostream>

class PositionComponent:public Component
{
public:
	PositionComponent();
	~PositionComponent();
	
	const GLfloat positions[25] = {
  0.0f, 0.5f, 0.0f,
  -0.5f, -0.5f, 0.0f,
  0.5f, -0.5f, 0.0f
	};

	const GLfloat colors[25] = {
	  1.0f, 0.0f, 0.0f, 1.0f,
	  0.0f, 1.0f, 0.0f, 1.0f,
	  0.0f, 0.0f, 1.0f, 1.0f
	};

	GLuint positionsVboId = 0;

	GLuint colorsVboId = 0;

	void createVBO();
	
};