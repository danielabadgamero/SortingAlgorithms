#include <algorithm>
#include <random>

#include <GLFW/glfw3.h>

#include "Shader.h"
#include "Algorithm.h"
#include "Core.h"

Algorithm::Algorithm(SortingFunc function) : step{ function }
{
	shuffle();
	A = 0;
	B = 1;
}

void Algorithm::shuffle()
{
	for (int i{}; i != 1000; i++)
		nums.push_back(i);
	std::shuffle(nums.begin(), nums.end(), std::default_random_engine{});
}

void Algorithm::sort()
{
	step(*this);
	drawState();
}

void Algorithm::drawState()
{
	Core::shader.use();
	for (size_t i{}; i != nums.size(); i++)
	{
		Core::shader.setUniform(glUniform1i, "index", i);
	}
}

bool& Algorithm::isSorted() { return sorted; }