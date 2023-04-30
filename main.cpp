#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Core.h"

int main()
{
	Core::init("Sorting Algorithms");
	Core::loop();
	Core::quit();

	return 0;
}