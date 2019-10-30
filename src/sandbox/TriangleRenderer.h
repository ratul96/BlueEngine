#pragma once
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "source/Component.h"

#include <exception>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480



class TriangleRenderer:public Component
{
public:
	TriangleRenderer();
	~TriangleRenderer();
	
	
	void DrawTriangle();

	SDL_Window *window;

	const GLfloat positions[25] = {
  0.0f, 0.5f, 0.0f,
  -0.5f, -0.5f, 0.0f,
  0.5f, -0.5f, 0.0f
	};

	const GLfloat colors[25] = {
	  1.0f, 0.0f, 0.0f, 1.0f,
	  0.0f, 1.0f, 0.0f, 1.0f,
	  0.0f, 0.0f, 1.0f, 1.0f
	};
	const GLchar *vertexShaderSrc =
		"attribute vec3 in_Position;" \
		"attribute vec4 in_Color;" \
		"" \
		"varying vec4 ex_Color;" \
		"" \
		"void main()" \
		"{" \
		"  gl_Position = vec4(in_Position, 1.0);" \
		"  ex_Color = in_Color;" \
		"}" \
		"";

	const GLchar *fragmentShaderSrc =
		"varying vec4 ex_Color;" \
		"void main()" \
		"{" \
		"  gl_FragColor = ex_Color;" \
		"}" \
		"";



	
	friend class Component;


};