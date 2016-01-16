#ifndef SQUARE_H
#define SQUARE_H

#include <set>
#include <string>

class square
{
	std::set<int> possibles;
	bool done;
public:
	square();
	square(int val);
	square(std::set<int> vals);
	~square();
	void add(int val);
	void rem(int val);
	int val() const;
	std::string to_string() const;
	bool operator==(const square&) const;
};

#endif
