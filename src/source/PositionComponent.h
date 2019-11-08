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

	GLuint positionsVboId ;

	GLuint colorsVboId;

	void createVBO();

/*
	glm::vec3 position;
	vec3 rotation;
	vec3 scale;

	mat4 getModel();

	mat4 m(1.0f);
	m = translate(m, position);
	// rotation
	// scale
	return m;
*/
	
};
