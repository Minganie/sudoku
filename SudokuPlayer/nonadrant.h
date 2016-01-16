#ifndef NONADRANT_H	// it's like a quadrant, except there's 9 instead of 4...
#define NONADRANT_H

#include <vector>
#include "square.h"

class nonadrant
{
	std::vector<square&> squares;
public:
	nonadrant(std::vector<square&>);
	~nonadrant();
};

#endif

