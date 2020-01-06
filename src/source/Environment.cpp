#include "Environment.h"
#include "Core.h"

std::shared_ptr<Core>Environment::getCore()
{
	return core.lock();
}

/*
  void Environment::update()
  {
	unsigned int current = SDL_GetTicks();
	deltaTs = (float)(current -(getCore()->lastTime)) / 1000.0f;    /**Calculating change in time between previous frame and current frame
	getCore()->lastTime = current;
  }
*/
float Environment::getDeltaTime()
{
	
	
	unsigned int current = SDL_GetTicks();
	deltaTs = (float)(current -(getCore()->lastTime)) / 1000.0f;    /**Calculating change in time between previous frame and current frame
	getCore()->lastTime = current;
																	*/
	return deltaTs;

	// return this->deltaTs;
}
