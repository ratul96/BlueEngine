#include "Screen.h"

void Screen::ScreenInit()
{
	window = SDL_CreateWindow("Lab 4 - Architecture",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	if (!SDL_GL_CreateContext(window))
	{
		throw std::exception();
	}

	if (glewInit() != GLEW_OK)
	{
		throw std::exception();
	}
}
void Screen::ScreenContext()
{

	 glContext = SDL_GL_CreateContext(window);

	if (!glContext)
	{
		std::cout << "Failed to create OpenGL context" << std::endl;
	}

}
std::shared_ptr<Core>Screen::getCore()
{
	return core.lock();
}
