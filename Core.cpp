#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Core.h"
#include "Algorithm.h"

static void swap(std::vector<int>& vec, size_t A, size_t B)
{
	int temp{ vec[B] };
	vec[B] = vec[A];
	vec[A] = temp;
}

void Core::init(const char* title)
{
	glfwInit();
	screen = glfwGetVideoMode(glfwGetPrimaryMonitor());
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
	window = glfwCreateWindow(screen->width, screen->height, title, NULL, NULL);
	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glViewport(0, 0, screen->width, screen->height);

	glfwSetKeyCallback(window, keyCallback);
	shader.init("vertex.glsl", "fragment.glsl");
}

void Core::loop()
{
	Algorithm algorithm
	{
		[](Algorithm& a)
		{
			if (a.nums[a.A] > a.nums[a.B])
			{
				swap(a.nums, a.A, a.B);
				a.swapDone = true;
			}
			else if (a.B + 1 == a.nums.size())
				if (!a.swapDone)
					a.isSorted() = true;
				else
				{
					a.A = 0;
					a.B = 1;
				}
			a.A++;
			a.B++;
		} 
	};

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		if (!algorithm.isSorted())
			algorithm.sort();
		algorithm.drawState();

		glfwPollEvents();
		glfwSwapBuffers(window);
	}
}

void Core::quit()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

void Core::keyCallback(GLFWwindow*, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}