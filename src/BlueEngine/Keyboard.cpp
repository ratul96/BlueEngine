#include "Keyboard.h"

Keyboard::Keyboard()
{
	
}
void Keyboard::Initialise()
{
	const Uint8 *key = SDL_GetKeyboardState(NULL);
}
Keyboard::~Keyboard()
{

}
void Keyboard::isKey(int key)
{
	SDL_Event event = { 0 };

	while (SDL_PollEvent(&event))
	{
		
		if (event.type = SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == key)
			{
				for (int i = 0; i < pressedKeys.size(); i++)
				{
					pressedKeys.push_back(key);

				}
			}

		}


	}
}
bool Keyboard::getKey(int _key)
{
	for (size_t i = 0; i < pressedKeys.size(); i++)
	{
		if (pressedKeys.at(i) == _key)
		{
			return true;
			std::cout << "Pressed" << std::endl;
		}
		return false;
	}
}