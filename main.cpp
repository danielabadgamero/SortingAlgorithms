#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Core.h"

int main()
{
	Core::init("");
	Core::loop();
	Core::quit();

	return 0;
}