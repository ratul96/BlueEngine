#pragma once
#include "Keyboard.h"
#include<memory>
#include<iostream>
#include<SDL2/SDL.h>

class Transform;
class Resources;
class Core;

class Entity;

/**
* \ brief Parent Component class from which every component inherits. Mainly acts as an interface between individual Components and Entites adding the individual components.
	      Contatins virtual functions to be overridden by the built in components for Initialise,Update and Display respectively.
*
*/
class Component
{
public:
	friend class Entity;
	
	virtual void onUpdate();
	virtual void onInit();
	virtual void onDisplay();
	virtual void onGui();

	std::shared_ptr<Entity>getEntity();
	std::shared_ptr<Core>getCore();
	std::shared_ptr<Keyboard>getKeyBoard();
	
protected:
	
	std::weak_ptr<Entity>entity;



	
};
