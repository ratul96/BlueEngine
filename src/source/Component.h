#pragma once
#include "MaterialComponent.h"
#include "MeshComponent.h"
#include "PositionComponent.h"

class Component
{
public:
	Component();
	~Component();

	void updateComponents(); //get the components here

protected:

	std::weak_ptr<MaterialComponent> material;
	std::weak_ptr<MeshComponent> mesh;



	
};