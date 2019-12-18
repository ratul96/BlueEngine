#pragma once
#include"GL/glew.h"
#include "Screen.h"
#include "Keyboard.h"
#include<rend/rend.h>
#include<SDL2/SDL.h>
#include<vector>
#include<memory>
#include<iostream>
#include <AL/al.h>
#include <AL/alc.h>


class Entity;
class Component;
class Resources;
class Camera;

using namespace rend;

class Core
{
private:
	friend class Camera;

	//Core();
	//~Core();
	std::vector<std::weak_ptr<Camera> > cameras;
	
public:
	ALCdevice* device;
	ALCcontext* context;
	std::shared_ptr<Entity> addEntity();
	std::vector<std::shared_ptr<Entity>>entities;
	std::shared_ptr<Screen>screen;
	std::shared_ptr<Keyboard>keyboard;
	std::shared_ptr<Keyboard>getKeyboard();
	static std::shared_ptr<Core> initialize();
	void createScreen();
	void audioInit();
	std::weak_ptr<Core> self;
	std::shared_ptr<Resources>resources;
	std::shared_ptr<Resources>getResources();
	std::shared_ptr<rend::Context>graphicsContext;
	std::shared_ptr<rend::Context>getContext();
	void run();
	std::shared_ptr<Camera> getCurrentCamera();

};
