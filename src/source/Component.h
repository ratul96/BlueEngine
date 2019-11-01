#pragma once
#include<memory>
#include<iostream>
#include<SDL2/SDL.h>



class Component
{
public:
	Component();
	~Component();

	//void updateComponents(); //get the components here

	//void onInit(); //Initialize window

	//void onBegin();

	//void ontick();

	virtual void DrawTriangle();

	
	
protected:

	/*std::weak_ptr<MaterialComponent> material;
	std::weak_ptr<MeshComponent> mesh;*/
	//std::weak_ptr<PositionComponent> position;



	
};