#ifndef GRID_H
#define GRID_H

#include <map>
#include <set>
#include <vector>
#include "square.h"
#include "nonasquare.h"

class grid
{
	std::vector<square> squares;
public:	// FOR TESTS ONLY
	std::vector<nonasquare> rows;
	std::vector<nonasquare> cols;
	std::vector<nonasquare> nonadrants;

	std::multimap<int, std::pair<int, int>> degree;
	square& at(int i, int j);
	const square& at(int i, int j) const;
	void backtrack();
	std::set<std::pair<int, int>> find_constraints(int, int) const;
public:
	grid();
	grid(std::string);
	grid(const grid&) = delete;
	grid& operator=(const grid&) = delete;
	~grid();
	void print() const;
	void backtracking_search();
	std::string to_string() const;
	bool is_done() const;
	bool is_compatible() const;
	bool is_compatible(int, int) const;
};

#endif