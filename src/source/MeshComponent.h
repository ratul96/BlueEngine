#pragma once
#include "Component.h"
#include "GL/glew.h"
#include<glm/glm.hpp>
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

	const char* obj =
		"v -1 1 0           \n" \
		"v -1 -1 0          \n" \
		"v 1 -1 0           \n" \
		"v 1 1 0            \n" \
		"                   \n" \
		"vt 0 1             \n" \
		"vt 0 0             \n" \
		"vt 1 0             \n" \
		"vt 1 1             \n" \
		"                   \n" \
		"f 1/1 2/2 3/3 4/4  \n" \
		"                   \n";
	
};
