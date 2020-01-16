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
void Keyboard::isKey(int key)
{
	SDL_Event event = { 0 };

	while (SDL_PollEvent(&event))
	{
		
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == key)
			{
				pressedKeys.push_back(key);

			}
			
		}
		else if (event.type == SDL_KEYUP)
		{
			if (event.key.keysym.sym == key)
			{
				releasedKeys.push_back(key);
				
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