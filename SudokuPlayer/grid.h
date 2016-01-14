#ifndef GRID_H
#define GRID_H

#include <vector>

class grid
{
	std::vector<std::vector<int>> numbers;
public:
	grid();
	~grid();
	void print();
};

#endif