#ifndef GRID_H
#define GRID_H

#include <map>
#include <vector>
#include "square.h"
#include "row.h"
#include "col.h"
#include "nonadrant.h"

class grid
{
	std::vector<square> squares;
	std::vector<row> rows;
	std::vector<col> cols;
	std::vector<nonadrant> nonadrants;

	std::multimap<int, std::pair<int, int>> degree;
	square& at(int i, int j);
	const square& at(int i, int j) const;
	void backtrack();
public:
	grid();
	grid(std::string);
	~grid();
	void print() const;
	void backtracking_search();
	std::string to_string() const;
	bool is_done() const;
	bool is_compatible() const;
	bool is_compatible(int, int) const;
};

#endif