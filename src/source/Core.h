#pragma once
#include "Entity.h"
#include"GL/glew.h"
#include<SDL2/SDL.h>
#include<memory>
#include<iostream>


class Core
{
private:
	//Core();
	//~Core();
public:
	void addEntity();
	void runEntityComponents();
	std::vector<std::shared_ptr<Entity>>entities;
	
	static std::shared_ptr<Core> initialize();
};