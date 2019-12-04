#pragma once

#include<memory>
#include<iostream>
#include<SDL2/SDL.h>

class Transform;
class Resources;

//class Entity;

class Component
{
public:
	friend class Entity;
	Component();
	~Component();

	//void updateComponents(); //get the components here
	//void onInit(); //Initialize window
	//void onBegin();
	//void ontick();

	virtual void onUpdate();
	virtual void onInit();
	virtual void onDisplay();
	virtual void onaudioInit();

	//virtual void createVBO();
	//std::shared_ptr<PositionComponent>getTransform();

	std::shared_ptr<Entity>getEntity();
	//std::shared_ptr<Resources>getResources();
	
protected:
	

	std::weak_ptr<Entity>entity;

	/*std::weak_ptr<MaterialComponent> material;
	std::weak_ptr<MeshComponent> mesh;*/
	//std::weak_ptr<PositionComponent> position;



	
};
