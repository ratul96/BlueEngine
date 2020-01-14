#include "Core.h"
#include "Transform.h"
#include "Mesh.h"
#include "Entity.h"
#include "Resources.h"
#include "Camera.h"
#include "Environment.h"
#include "Screen.h"
#include "Gui.h"

std::shared_ptr<Core> Core::initialize()
{
	std::shared_ptr<Core> c = std::make_shared<Core>();
	c->self = c;

	c->createScreen();
	c->audioInit();
	
	

	c->graphicsContext = Context::initialize();
	

	c->resources = std::make_shared<Resources>();
	c->resources->core = c;

	//need to get environment reference here
	c->environment = std::make_shared<Environment>();
	c->environment->core = c;

	c->gui = std::make_shared<Gui>(c);

	return c;
}

std::shared_ptr<Entity> Core::addEntity()
{
	std::shared_ptr<Entity> rtn = std::make_shared<Entity>();

	rtn->self = rtn;
	rtn->core = self;

	entities.push_back(rtn);

	rtn->addComponent<Transform>();
	
	

	return rtn;
}
//Getting the entity with collision type

std::shared_ptr<Resources>Core::getResources()
{
	return resources;
}
std::shared_ptr<Environment>Core::getEnvironment()
{
	return environment;
}
std::shared_ptr<Context>Core::getContext()
{
	return graphicsContext;
}
std::shared_ptr<Gui>Core::getGui()
{
	return gui;
}
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

std::shared_ptr<Camera> Core::getCurrentCamera()
{
	return cameras.at(0).lock();
}
std::shared_ptr<Lighting>Core::getLight()
{
	return lights.at(0).lock();
}
void Core::run()
{
	keyboard = std::make_shared<Keyboard>();
	bool quit = false; 
	while (!quit)
	{
		event = { 0 };
		while (SDL_PollEvent(&event))
		{

			if (event.type == SDL_QUIT)
			{
				quit = true;
				
			}
			if(event.type=SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
					case SDLK_LEFT:
					{
					keyboard->getKey(SDLK_LEFT);
					break;
					}
					
				}
			}
			
			
		}

		environment->Update();

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

		//Add onGui() here as well
		for (int i = 0; i < entities.size(); i++)
		{
			entities.at(i)->onGui();
		}

		SDL_GL_SwapWindow(screen->window);
	}
}
