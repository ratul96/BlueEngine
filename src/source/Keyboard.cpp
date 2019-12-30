#include "Keyboard.h"
#include "Entity.h"

bool Keyboard::getKeyLeft()
{
	if (SDLK_LEFT)
	{
		RotateLeft = true;
		std::cout << "Left pressed" << std::endl;
		//get keyboard and camera angle here
		return true;
	}
	return false;
}
bool Keyboard::getKeyRight()
{
	if (SDLK_RIGHT)
	{
		RotateRight = true;
		std::cout << "Right pressed" << std::endl;
		//get keyboard and camera angle here

	}
	return false;
}