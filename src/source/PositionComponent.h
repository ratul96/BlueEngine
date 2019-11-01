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
	void SetPosition();

	
};