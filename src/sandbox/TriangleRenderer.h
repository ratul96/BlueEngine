#include "source/Component.h"
#include <SDL2/SDL.h>
#include <GL/glew.h>

#include <exception>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

class TriangleRenderer : public Component
{
public:
	TriangleRenderer();
	~TriangleRenderer();
	virtual void onInit();
	
	void CreateVBO();
	void CreateVAO();
	void Draw();

	SDL_Window *window;

	const GLfloat positions[1] = { 0.0f };

	const GLfloat colors[1] = { 0.0f };

	const GLchar *vertexShaderSrc;
	const GLchar *fragmentShaderSrc;


};