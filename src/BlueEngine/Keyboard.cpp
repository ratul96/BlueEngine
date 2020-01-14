#include "Keyboard.h"

Keyboard::Keyboard()
{
	key = SDL_GetKeyboardState(NULL);
}
Keyboard::~Keyboard()
{

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