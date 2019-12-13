#include "Core.h"
#include "Transform.h"
#include "Mesh.h"
#include "Entity.h"
#include "Resources.h"

std::shared_ptr<Core> Core::initialize()
{
	std::shared_ptr<Core> c = std::make_shared<Core>();
	c->self = c;

	c->createScreen();
	c->audioInit();

	c->graphicsContext = Context::initialize();
	

	c->resources = std::make_shared<Resources>();
	c->resources->core = c;

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

std::shared_ptr<Resources>Core::getResources()
{
	return resources;
}
std::shared_ptr<Context>Core::getContext()
{
	return graphicsContext;
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
void Core::run()
{
	bool quit = false;
	while (!quit)
	{
		SDL_Event event = { 0 };
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
		}


		for (int i = 0; i < entities.size(); i++)
		{
			entities.at(i)->onUpdate();
		}

		for (int i = 0; i < entities.size(); i++)
		{
			entities.at(i)->onInit();
		}

		glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		for (int i = 0; i < entities.size(); i++)
		{
			entities.at(i)->onDisplay();
		}


		SDL_GL_SwapWindow(screen->window);
	}
}
