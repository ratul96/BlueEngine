#pragma once
#include <SDL2/SDL.h>
#include <memory>

class Core;

class Environment
{
private:
	float deltaTs;
public:
	float getDeltaTime();
	std::shared_ptr<Core>getCore();
	void Update();
	std::weak_ptr<Core>core;
};