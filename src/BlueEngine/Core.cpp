#include "Core.h"
#include "Transform.h"
#include "Mesh.h"
#include "Entity.h"
#include "Resources.h"
#include "Camera.h"
#include "Environment.h"
#include "Screen.h"
#include "Gui.h"
#include "Keyboard.h"

/**
* \ return shared pointer of type Core. Initialising the game engine here and creating references for all the utilities the Game Engine provides.
*
*/

std::shared_ptr<Core> Core::initialize()
{
	std::shared_ptr<Core> c = std::make_shared<Core>();
	c->self = c;

	c->createScreen();
	c->audioInit();
	
	c->keyboard=Keyboard::Initialise();

	c->graphicsContext = Context::initialize();
	

	c->resources = std::make_shared<Resources>();
	c->resources->core = c;

	c->environment = std::make_shared<Environment>();
	c->environment->core = c;

	

	c->gui = std::make_shared<Gui>(c);

	return c;
}
/**
* \ return shared pointer of type Core. Adding each Entities within Core.
*
*/
std::shared_ptr<Entity> Core::addEntity()
{
	std::shared_ptr<Entity> rtn = std::make_shared<Entity>();

	rtn->self = rtn;
	rtn->core = self;

	entities.push_back(rtn);

	rtn->addComponent<Transform>();
	
	

	return rtn;
}
/**
* \ return shared pointer of type Core. Getting reference to resources within core.
*
*/
std::shared_ptr<Resources>Core::getResources()
{
	return resources;
}
/**
* \ return shared pointer of type Core. Getting references to Environment which calculates DeltatTime.
*
*/
std::shared_ptr<Environment>Core::getEnvironment()
{
	return environment;
}
/**
* \ return shared pointer of type Core. Getting references to Context(context for Rend an OpenGL wrapper provided by Karsten Pedersen).
*
*/
std::shared_ptr<Context>Core::getContext()
{
	return graphicsContext;
}
/**
* \ return shared pointer of type Core. Getting reference to the GUI.
*
*/
std::shared_ptr<Gui>Core::getGui()
{
	return gui;
}
/**
* \ return shared pointer of type Core. Getting reference to the Keyboard.
*
*/
std::shared_ptr<Keyboard>Core::getKeyboard()
{
	return keyboard;
}
void Core::createScreen()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw std::exception();
	}

	screen = std::make_shared<Screen>();
	screen->window = SDL_CreateWindow("Lab 4 - Architecture",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	screen->glContext = SDL_GL_CreateContext(screen->window);

	lastTime = SDL_GetTicks();

	if (!screen->glContext)
	{
		throw std::exception();
	}


}
/**
* \ return type NULL. Initializing Audio
*
*/
void Core::audioInit()
{
	device = alcOpenDevice(NULL);

	if (device == NULL)
	{
		throw std::exception();
	}

	context = alcCreateContext(device, NULL);

	if (context == NULL)
	{
		alcCloseDevice(device);
		throw std::exception();
	}

	if (!alcMakeContextCurrent(context))
	{
		alcDestroyContext(context);
		alcCloseDevice(device);
		throw std::exception();
	}

}
/**
* \ return shared pointer of type Core. Getting reference to individual Cameras within Core.
*
*/
std::shared_ptr<Camera> Core::getCurrentCamera()
{
	return cameras.at(0).lock();
}
/**
* \ return shared pointer of type Core. Getting reference to each Light.
*
*/
std::shared_ptr<Lighting>Core::getLight()
{
	return lights.at(0).lock();
}
/**
* \ return type NULL. Finally function to run Engine core to Update and Display Entities.  
*
*/
void Core::run()
{
	keyboard = std::make_shared<Keyboard>();
	bool quit = false; 
	while (!quit)
	{
		
		environment->Update();

		
		keyboard->isKey();
		
		for (int i = 0; i < entities.size(); i++)
		{
			entities.at(i)->onUpdate();
		}
		
		glClearColor(0.1f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		for (int i = 0; i < entities.size(); i++)
		{
			entities.at(i)->onDisplay();
		}

		glClear(GL_DEPTH_BUFFER_BIT);

		
		for (int i = 0; i < entities.size(); i++)
		{
			entities.at(i)->onGui();
		}

		SDL_GL_SwapWindow(screen->window);
	}
}
