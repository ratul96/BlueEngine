#pragma once
#include "Component.h"
#include "GL/glew.h"
#include<glm/glm.hpp>
#include <rend/rend.h>
#include<sr1/memory>
#include<iostream>

class MeshComponent :public Component
{
public:
	MeshComponent();
	~MeshComponent();

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
	std::string obj;
	
		
		
		
	
};
