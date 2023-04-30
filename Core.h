#ifndef CORE_H
#define CORE_H

#include <GLFW/glfw3.h>

namespace Core
{
	inline GLFWwindow* window{};
	inline const GLFWvidmode* screen{};
	
	inline double prevTime{};
	inline double currTime{};
	inline double deltaTime{};

	void keyCallback(GLFWwindow*, int, int, int, int);

	void init(const char*);
	void loop();
	void quit();
}

#endif