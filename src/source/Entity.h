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

class Entity
{
public:

	//std::shared_ptr<Component>updateEntityComponents(); //update with all the models accessing the components
	//std::shared_ptr<T>addComponent<T>();

	template <typename T>
	std::shared_ptr<T> addComponent()
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();

		components.push_back(rtn);

		rtn->entity=self;//Reference of entity stored in Component
		rtn->onInit();

		return rtn;
	}

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
		//return std::shared_ptr<T>();
		// TODO: Throw non-generic Exception
		throw std::exception();
	}
	std::vector<std::shared_ptr<Component>> components;
	
	//std::shared_ptr<MeshComponent>getTransform();

	//std::weak_ptr<MeshComponent>mesh;
	
	std::weak_ptr<Core>core;

	std::weak_ptr<Entity>self;

	std::shared_ptr<Core>getCore();
	
	// onUpdate
	void onUpdate();
	void onInit();
	void onDisplay();



};
