#include "Keyboard.h"

Keyboard::Keyboard()
{
	key = SDL_GetKeyboardState(NULL);
}
Keyboard::~Keyboard()
{

}
void Keyboard::isKey()
{
	SDL_Event event = { 0 };

	while (SDL_PollEvent(&event))
	{
		
		if (event.type = SDL_KEYDOWN)
		{
			for (auto&i : ListOfKeys)
			{
				if (event.key.keysym.sym == i)
				{

				}
			}
			
			{
			case SDLK_LEFT:
			{
				//keyboard->getKey(SDLK_LEFT);
				break;
			}

			}
		}


	}
}
bool Keyboard::getKey(int key)
{
	for (size_t i = 0; pressedKeys.size(); i++)
	{
		pressedKeys.push_back(key);
		if (pressedKeys.at(i) == key)
		{
			return true;
		}
	}
	return false;
}