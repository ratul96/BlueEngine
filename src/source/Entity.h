#pragma once
#include "Component.h"
#include "GL/glew.h"
#include<GLM/glm.hpp>
#include<SDL2/SDL.h>
#include<string>
#include<vector>
#include<memory>
#include<iostream>

class Entity
{
public:
	Entity();
	~Entity();
	
	std::shared_ptr<Component>updateEntityComponents(); //update with all the models accessing the components
protected:
	std::vector<std::shared_ptr<Component>> components;

	


};