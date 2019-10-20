#pragma once
#include "MaterialComponent.h"
#include "MeshComponent.h"
#include "PositionComponent.h" 
#include<memory>
#include<iostream>

class Component
{
public:
	Component();
	~Component();

	//void updateComponents(); //get the components here

	//void onInit(); //Initialize window

	//void onBegin();

	//void ontick();

	virtual void onDisplay();

protected:

	/*std::weak_ptr<MaterialComponent> material;
	std::weak_ptr<MeshComponent> mesh;*/
	std::weak_ptr<PositionComponent> position;



	
};