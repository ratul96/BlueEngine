#pragma once
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "source/Component.h"
#include "source/Entity.h"

class Shader:public Component
{
public:
	Shader();
	~Shader();
	const GLchar* vertexShaderSrc =
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

	const GLchar* fragmentShaderSrc =
		"varying vec4 ex_Color;" \
		"void main()" \
		"{" \
		"  gl_FragColor = ex_Color;" \
		"}" \
		"";
	GLuint vertexShaderId;

};