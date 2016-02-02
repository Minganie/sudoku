#ifndef GRID_H
#define GRID_H

#include <map>
#include <set>
#include <vector>
#include "square.h"
#include "nonasquare.h"

class grid
{
public:
	using pos_set_t = std::set<std::pair<int, int >>;
	using pos_t = std::pair < int, int > ;
private:
	std::vector<square> squares;
public:	// FOR TESTS ONLY
	std::vector<nonasquare> rows;
	std::vector<nonasquare> cols;
	std::vector<nonasquare> nonadrants;

	std::multimap<int, pos_t> degree;	// degree => (i, j)
	square& at(int i, int j);
	const square& at(int i, int j) const;
	void backtrack();
	pos_set_t find_constraints(int, int) const;
	int find_degree(int, int) const;
public:
	grid();
	grid(std::string);
	grid(const grid&) = delete;
	grid& operator=(const grid&) = delete;	// the default one does not do the job, I might need it later but for now this is just to keep me from doing stoopid mistakes
	~grid();
	void print() const;
	void backtracking_search();
	std::string to_string() const;
	bool is_done() const;
	bool is_compatible() const;
	bool is_compatible(int, int) const;
};

#endif