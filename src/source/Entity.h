#pragma once
#include "Model.h"
#include "GL/glew.h"
#include<GLM/glm.hpp>
#include<SDL2/SDL.h>
#include<string>
#include<vector>
#include<memory>

class Entity
{
public:
	Entity();
	~Entity();
	
	void updateModelEntityComponents(); //update with all the models accessing the components
protected:
	std::vector<shared_ptr<Component>> components;

};