#pragma once
#include "Entity.h"
#include"GL/glew.h"
#include<SDL2/SDL.h>
#include<memory>
#include<iostream>


class Core
{
private:
	Core();
	~Core();
public:
	std::shared_ptr<Entity>addEntities();
	void runEntityComponents();
	std::vector<std::shared_ptr<Entity>>entities;
	
};