#include <algorithm>
#include <random>

#include "Algorithm.h"
#include "Column.h"

Algorithm::Algorithm(SortingFunc function) : step{ function }
{
	shuffle();
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
	for (size_t i{}; i != nums.size(); i++)
	{
		Column col{ i, nums[i], nums.size(), i == A || i == B };
		col.draw();
	}
}

bool& Algorithm::isSorted() { return sorted; }