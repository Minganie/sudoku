#include "square.h"


square::square()
	: done{ false }
{
	possibles = std::set < int > {1, 2, 3, 4, 5, 6, 7, 8, 9};
}

square::square(int val)
	: done{ true }
{
	possibles.insert(val);
}

square::square(std::set<int> vals)
	: possibles{ vals }, done{ false }
{
}

void square::add(int val)
{
	possibles.insert(val);
}

void square::rem(int val)
{
	possibles.erase(val);
}

std::string square::to_string() const
{
	if (done)
		return std::to_string(*possibles.begin());
	else
		return " ";
}

square::~square()
{
}

bool square::operator==(const square& other) const
{
	return possibles == other.possibles;
}

int square::val() const
{
	if (possibles.size() == 1)
		return *(possibles.begin());
	else
		throw 42;
}
