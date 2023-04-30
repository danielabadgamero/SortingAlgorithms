#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Core.h"

int main()
{
	Core::screen = const_cast<GLFWvidmode*>(glfwGetVideoMode(glfwGetPrimaryMonitor()));
	glfwWindowHint(GLFW_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
	Core::window = glfwCreateWindow(Core::screen->width, Core::screen->height, "Sorting Algorithms", NULL, NULL);
	
	glfwMakeContextCurrent(Core::window);
	gladLoadGLLoader((GLADloadproc));

	Core::running = true;
	while (Core::running)
	{
	}

	return 0;
}