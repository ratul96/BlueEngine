#pragma once
#include"GL/glew.h"
#include<SDL2/SDL.h>
#include<rend/rend.h>
#include<vector>
#include<memory>
#include<iostream>

class Entity;
class Component;
class Resources;

using namespace rend;

class Core
{
private:
	//Core();
	//~Core();
public:
	std::shared_ptr<Entity> addEntity();
	std::vector<std::shared_ptr<Entity>>entities;
	static std::shared_ptr<Core> initialize();
	void initContext();
	std::weak_ptr<Core> self;
	std::shared_ptr<Resources>resources;
	std::shared_ptr<Resources>getResources();
	std::shared_ptr<rend::Context>graphicsContext;
	std::shared_ptr<rend::Context>getContext();
	void run();

};
