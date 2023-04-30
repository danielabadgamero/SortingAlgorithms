#ifndef CORE_H
#define CORE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Shader.h"

namespace Core
{
	inline GLFWwindow* window{};
	inline const GLFWvidmode* screen{};
	constexpr GLfloat vertices[]
	{
		 0.0f,  0.0f,
		 1.0f,  0.0f,
		 1.0f,  1.0f,
		 1.0f,  1.0f,
		 0.0f,  1.0f,
		 0.0f,  0.0f,
	};
	inline Shader shader{};
	inline GLuint VBO{};
	inline GLuint VAO{};
	
	inline double prevTime{};
	inline double currTime{};
	inline double deltaTime{};

	void keyCallback(GLFWwindow*, int, int, int, int);

	void init(const char*);
	void loop();
	void quit();
}

#endif