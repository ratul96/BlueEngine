#include "Keyboard.h"

bool Keyboard::getKeyLeft()
{
	if (SDLK_LEFT)
	{
		RotateLeft = true;
		std::cout << "Left pressed" << std::endl;
	}
	return false;
}
