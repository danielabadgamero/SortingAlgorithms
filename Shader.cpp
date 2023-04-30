#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <glad/glad.h>

#include "Shader.h"

static std::string loadFile(const char* name)
{
	std::ifstream input{ name };
	std::stringstream buffer{};
	buffer << input.rdbuf();
	return buffer.str();
}

static void printStatus(void(*ivFunc)(GLuint, GLenum, GLint*), GLenum type, GLuint object)
{
	int success{};
	ivFunc(object, type, &success);
	if (!success)
	{
		char infoLog[512]{};
		if (ivFunc == glGetShaderiv)
			glGetShaderInfoLog(object, 512, NULL, infoLog);
		else if (ivFunc == glGetProgramiv)
			glGetProgramInfoLog(object, 512, NULL, infoLog);
		std::cout << infoLog << '\n';
	}
}

Shader::Shader() {}

void Shader::init(const char* vertexPath, const char* fragmentPath)
{
	std::string vSourceStr{ loadFile(vertexPath) };
	std::string fSourceStr{ loadFile(fragmentPath) };
	const char* vertexSource{ vSourceStr.c_str() };
	const char* fragmentSource{ fSourceStr.c_str() };

	GLuint vertex{ glCreateShader(GL_VERTEX_SHADER) };
	GLuint fragment{ glCreateShader(GL_FRAGMENT_SHADER) };

	glShaderSource(vertex, 1, &vertexSource, NULL);
	glShaderSource(fragment, 1, &fragmentSource, NULL);
	glCompileShader(vertex);
	glCompileShader(fragment);
	printStatus(glGetShaderiv, GL_COMPILE_STATUS, vertex);
	printStatus(glGetShaderiv, GL_COMPILE_STATUS, fragment);

	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);
	printStatus(glGetProgramiv, GL_LINK_STATUS, ID);

	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

void Shader::use() const
{
	glUseProgram(ID);
}