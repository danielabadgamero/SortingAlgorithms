#include <vector>
#include <iostream>

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
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
	screen = glfwGetVideoMode(glfwGetPrimaryMonitor());
	window = glfwCreateWindow(screen->width, screen->height, title, NULL, NULL);
	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glViewport(0, 0, screen->width, screen->height);

	glfwSetKeyCallback(window, keyCallback);
	shader.init("vertex.glsl", "fragment.glsl");
	shader.use();

	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (void*)(0 * sizeof(GLfloat)));
	glEnableVertexAttribArray(0);
}

void Core::loop()
{
	Algorithm algorithm1
	{
		[](Algorithm& a)
		{
			if (a.B == a.nums.size())
				if (!a.swapDone)
					a.isSorted() = true;
				else
				{
					a.A = 0;
					a.B = 1;
					a.swapDone = false;
					return;
				}
			else if (a.nums[a.A] > a.nums[a.B])
			{
				swap(a.nums, a.A, a.B);
				a.swapDone = true;
			}
			a.A++;
			a.B++;
		}, 20
	};

	Algorithm algorithm2
	{
		[](Algorithm& a)
		{
			if (a.B == a.nums.size())
			{
				a.isSorted() = true;
				return;
			}
			if (a.B > 0)
				if (a.nums[a.B] < a.nums[a.B - 1])
				{
					swap(a.nums, a.B, a.B - 1);
					a.B--;
				}
				else
				{
					a.B = a.A;
					a.A++;
				}
			else
				a.B = 1;
		}, 20
	};

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		if (!algorithm1.isSorted())
			algorithm1.sort();
		else if (!algorithm2.isSorted())
			algorithm2.sort();

		if (!algorithm1.isSorted())
			algorithm1.drawState();
		else
			algorithm2.drawState();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

void Core::quit()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	glfwDestroyWindow(window);
	glfwTerminate();
}

void Core::keyCallback(GLFWwindow*, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}