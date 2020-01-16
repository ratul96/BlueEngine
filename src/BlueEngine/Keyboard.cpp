#include "Keyboard.h"

Keyboard::Keyboard()
{
	
}
std::shared_ptr<Keyboard> Keyboard::Initialise()
{
	std::shared_ptr<Keyboard>rtn = std::make_shared<Keyboard>();
	return rtn;
}
Keyboard::~Keyboard()
{

}
void Keyboard::isKey()
{
	//SDL_Event event = { 0 };

	while (SDL_PollEvent(&event))
	{
		
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_LEFT)
			{
				pressedKeys.push_back(SDLK_LEFT);

			}
			if (event.key.keysym.sym == SDLK_RIGHT)
			{
				pressedKeys.push_back(SDLK_RIGHT);

			}
		}
		else if (event.type == SDL_KEYUP)
		{
			if (event.key.keysym.sym == SDLK_LEFT)
			{
				releasedKeys.push_back(SDLK_LEFT);

			}
			if (event.key.keysym.sym == SDLK_RIGHT)
			{
				releasedKeys.push_back(SDLK_RIGHT);

			}
		}
		


	}
}
void Keyboard::clearKeys()
{
	if (pressedKeys.size() > 0)
	{
		pressedKeys.clear();
	}
	
	if (releasedKeys.size() > 0)
	{
		releasedKeys.clear();
	}
	
}
bool Keyboard::getKey(int _key)
{
	for (size_t i = 0; i < pressedKeys.size(); i++)
	{
		if (pressedKeys.at(i) == _key)
		{
			
			return true;
			
		}
		return false;
	}
}