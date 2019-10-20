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
	
	std::shared_ptr<Entity>initialize();
	//std::shared_ptr<Component>updateEntityComponents(); //update with all the models accessing the components
	std::vector<std::shared_ptr<Component>> components;
	//std::shared_ptr<T>addComponent<T>();
	void addComponents();
	


};