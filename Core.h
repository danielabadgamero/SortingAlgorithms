#ifndef CORE_H
#define CORE_H

#include <GLFW/glfw3.h>

#include "Shader.h"

namespace Core
{
	inline GLFWwindow* window{};
	inline const GLFWvidmode* screen{};
	constexpr GLuint indeces[]{ 0, 1, 2, 2, 3, 0 };
	constexpr GLfloat vertices[]
	{
		-1.0f, -1.0f,
		 1.0f, -1.0f,
		 1.0f,  1.0f,
		-1.0f,  1.0f,
	};
	inline Shader shader{};
	
	inline double prevTime{};
	inline double currTime{};
	inline double deltaTime{};

	void keyCallback(GLFWwindow*, int, int, int, int);

	void init(const char*);
	void loop();
	void quit();
}

#endif