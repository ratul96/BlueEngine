#include "Shader.h"

Shader::Shader()
{
	vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
	fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
	programId = glCreateProgram();
}
Shader::~Shader()
{
	glDetachShader(programId, vertexShaderId);
	glDeleteShader(vertexShaderId);
	glDetachShader(programId, fragmentShaderId);
	glDeleteShader(fragmentShaderId);
}
bool Shader::loadShaders()
{
	
	glAttachShader(programId, vertexShaderId);
	glAttachShader(programId, fragmentShaderId);
	glBindAttribLocation(programId, 0, "in_Position");
	glBindAttribLocation(programId, 1, "in_Color");

	if (glGetError() != GL_NO_ERROR)
	{
		throw std::exception();

		return false;
	}

	glLinkProgram(programId);
	glGetProgramiv(programId, GL_LINK_STATUS, &success);

	if (!success)
	{
		throw std::exception();

		return false;
	}

	return true;
}
bool Shader::CheckShaderCompiled()
{
	glShaderSource(vertexShaderId, 1, &vertexShaderSrc, NULL);
	glCompileShader(vertexShaderId);
	
	glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		throw std::exception();

		return false;
	}


	glShaderSource(fragmentShaderId, 1, &fragmentShaderSrc, NULL);
	glCompileShader(fragmentShaderId);
	glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		throw std::exception();

		return false;
	}

	return true;
}
