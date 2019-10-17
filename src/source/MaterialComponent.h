#pragma once

#include<string>
#include<memory>
#include<GL/glew.h>
#include<glm/glm.hpp>

class MaterialComponent
{
public:
	MaterialComponent();
	~MaterialComponent();

	void LoadShaders();

};