#ifndef NONASQUARES_H
#define NONASQUARES_H

#include <vector>
#include "square.h"

class nonasquare
{
public:	// FOR TESTS ONLY
	std::vector<square*> squares;
public:
	nonasquare(std::vector<square*>);
	~nonasquare();
	bool is_valid() const;
};

#endif
