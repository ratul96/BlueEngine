#pragma once
#include "GL/glew.h"
#include "Entity.h"
#include <rend/rend.h>
#include <SDL2/SDL.h>
#include <vector>
#include <memory>
#include <iostream>
#include <AL/al.h>
#include <AL/alc.h>

class Screen;
class Component;
class Resources;
class Camera;
class Lighting;
class Keyboard;
class Environment;
class Gui;

using namespace rend;
/**
* \brief Represents Engine core.All the functionalities are passed through and implemented here.
*
*/

class Core
{
private:
	friend class Camera;
	friend class Lighting;
/**
*\ brief Initializing camera within Core. declaring vector of cameras.
*
*/

	std::vector<std::weak_ptr<Camera> > cameras;

/**
*\ brief Initializing Light within Core. declaring vector of Lights.
*
*/

	std::vector<std::weak_ptr<Lighting>>lights;

	
	
public:
	ALCdevice* device;   
	ALCcontext* context;
	SDL_Event event;
	unsigned int lastTime;
	std::shared_ptr<Entity> addEntity();
    std::vector<std::shared_ptr<Entity>>entities;
	
	template<typename T>
	void getEntities(std::vector<std::shared_ptr<Entity>>&ce)
	{
		for (auto&c : entities)
		{
			if (c->hasComponent<T>())
			{
				ce.push_back(c);
			}
			
		}
	}
	std::shared_ptr<Screen>screen;
	std::shared_ptr<Keyboard>keyboard;
	std::shared_ptr<Environment>environment;
	std::shared_ptr<Environment>getEnvironment();
	std::shared_ptr<Gui> getGui();
	std::shared_ptr<Gui> gui;
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
	std::shared_ptr<Lighting>getLight();

};
