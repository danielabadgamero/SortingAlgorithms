#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <vector>

class Algorithm;

typedef void(*SortingFunc)(Algorithm&);

class Algorithm
{
private:
	SortingFunc step{};
	bool sorted{};
	void drawState();
	void shuffle();
public:
	bool swapDone{};
	std::vector<int> nums{};
	size_t A{};
	size_t B{};
	Algorithm(SortingFunc);
	void sort();
	bool& isSorted();
};

#endif