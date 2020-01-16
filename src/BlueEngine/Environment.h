#pragma once
#include <SDL2/SDL.h>
#include <memory>
#include<Windows.h>

class Core;

/**
* \ brief Environment class.  Calculate the time elapsed between each frame. Used to rotate the Camera every frame over the press of a keyboard
*
*/

class Environment
{
private:
	float deltaTs;
public:
	Environment();
	~Environment();
	float getDeltaTime();
	std::string file;
	std::string root;
	std::shared_ptr<Core>getCore();
	void Update();
	std::weak_ptr<Core>core;
	std::string getRootDirectory();
};