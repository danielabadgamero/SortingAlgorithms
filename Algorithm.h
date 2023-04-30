#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <vector>
#include <random>

class Algorithm;

typedef void(*SortingFunc)(Algorithm&);

class Algorithm
{
private:
	SortingFunc step{};
	bool sorted{};
	std::mt19937 engine{};
public:
	bool swapDone{};
	std::vector<int> nums{};
	size_t A{};
	size_t B{};
	Algorithm(SortingFunc, size_t);
	Algorithm();
	void shuffle();
	void drawState();
	void sort();
	bool& isSorted();
};

#endif