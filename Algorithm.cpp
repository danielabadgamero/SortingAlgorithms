#include <algorithm>
#include <random>
#include <iostream>
#include <windows.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Shader.h"
#include "Algorithm.h"
#include "Core.h"

Algorithm::Algorithm(SortingFunc function, size_t size) : step{ function }
{
	shuffle(size);
	A = 0;
	B = 1;
}

void Algorithm::shuffle(size_t size)
{
	for (int i{}; i != size; i++)
		nums.push_back(i);
	std::shuffle(nums.begin(), nums.end(), std::default_random_engine{});
}

void Algorithm::sort()
{
	step(*this);
}

void Algorithm::drawState()
{
	for (size_t i{}; i != nums.size(); i++)
	{
		Core::shader.setUniform(glUniform1f, "x", static_cast<float>(i) / nums.size() * 2 - 1);
		Core::shader.setUniform(glUniform1f, "w", 2.0f / nums.size());
		Core::shader.setUniform(glUniform1f, "h", static_cast<float>(nums[i] + 0.5) / nums.size() * 2);
		Core::shader.setUniform(glUniform1i, "selected", static_cast<int>(i == A || i == B));
		glDrawArrays(GL_TRIANGLES, 0, 6);
	}
}

bool& Algorithm::isSorted() { return sorted; }