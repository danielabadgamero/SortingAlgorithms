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
	void shuffle(size_t);
public:
	bool swapDone{};
	std::vector<int> nums{};
	size_t A{};
	size_t B{};
	Algorithm(SortingFunc, size_t);
	void drawState();
	void sort();
	bool& isSorted();
};

#endif