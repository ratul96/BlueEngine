#include "Keyboard.h"

Keyboard::Keyboard()
{
	
}
/**
*return type shared pointer of type keyboard to initialise Keyboard
*
*/
std::shared_ptr<Keyboard> Keyboard::Initialise()
{
	std::shared_ptr<Keyboard>rtn = std::make_shared<Keyboard>();
	return rtn;
}
Keyboard::~Keyboard()
{

}
/**
*return type void detecting keypress and key release and pushing them inside respective vectors
*
*/
void Keyboard::isKey()
{

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
			if (event.key.keysym.sym == SDLK_UP)
			{
				pressedKeys.push_back(SDLK_UP);

			}
			if (event.key.keysym.sym == SDLK_DOWN)
			{
				pressedKeys.push_back(SDLK_DOWN);

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
			if (event.key.keysym.sym == SDLK_UP)
			{
				releasedKeys.push_back(SDLK_UP);

			}
			if (event.key.keysym.sym == SDLK_DOWN)
			{
				releasedKeys.push_back(SDLK_DOWN);

			}
		}
		


	}
}
/**
*return type void function to clear keys every frame
*
*/
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
/**
*return type Boolean to detect key pressed by user thus triggering whichever instruction to be processed
*
*/
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