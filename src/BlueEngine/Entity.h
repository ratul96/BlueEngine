#pragma once
#include "Component.h"
#include "GL/glew.h"
#include <glm/glm.hpp>
#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include <memory>
#include <iostream>

class Core;

/**
* \ brief Entity class. Each Gameobject or an individual feature like Camera or Light is first added as an Entity. Each Entity has individual Components added as a template functon which is defined as below.    
*
*/
class Entity
{
public:
/**
* \ return Template function shared pointer type which adds Components to each individual entity, while also initialising the components and storing the reference of itself within the component.
*
*/
	template <typename T>
	std::shared_ptr<T> addComponent()
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();

		components.push_back(rtn);

		rtn->entity=self;
		rtn->onInit();
		return rtn;
	}
/**
* \ return Template function shared pointer type which gets an existing Component from Entity.
*
*/
	template<typename T>
	std::shared_ptr<T> getComponent()
	{
		for (auto& c : components)
		{
			std::shared_ptr<T> rtn1 = std::dynamic_pointer_cast<T>(c);
			if (rtn1 != NULL)
			{
				return rtn1;
			}
		}

		std::cout << "Does not Exist" << std::endl;

		throw std::exception();
	}

/**
* \ return Template function Boolean type which which checks whether the Entity has the specific component.
*
*/
	template<typename T>
	bool hasComponent()
	{
		for (auto& c : components)
		{
			std::shared_ptr<T> rtn1 = std::dynamic_pointer_cast<T>(c);
			if (rtn1 != NULL)
			{
				return true;
			}
		}
		return false;
	}

/**
* \ Vector of shared pointer of Components
*
*/
	std::vector<std::shared_ptr<Component>> components;
	
	std::weak_ptr<Core>core;

	std::weak_ptr<Entity>self;

	std::shared_ptr<Core>getCore();
	
	void onInit();
	void onUpdate();
	void onDisplay();
	void onGui();


};
