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
	std::shared_ptr<Entity> addEntity();
	std::vector<std::shared_ptr<Entity>>entities;
	static std::shared_ptr<Core> initialize();
	std::weak_ptr<Core> self;
	void run();
};
