#ifndef GRID_H
#define GRID_H

#include <map>
#include <vector>
#include "square.h"

class grid
{
	std::vector<square> squares;
	std::multimap<int, std::pair<int, int>> degree;
	square& at(int i, int j);
	void backtrack();
public:
	grid();
	grid(std::string);
	~grid();
	void print();
	void backtracking_search();
	std::string to_string();
	bool is_done();
};

#endif