#pragma once

#include "Component.h"
#include<vector>
#include<string>
#include<memory>
class Model
{
	Model();
	~Model();

	std::weak_ptr<Component> component;
	

	void updateComponets(); //access components
};