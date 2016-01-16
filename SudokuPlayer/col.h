#ifndef COL_H
#define COL_H

#include <vector>
#include "square.h"

class col
{
	std::vector<square&> squares;
public:
	col(std::vector<square&>);
	~col();
};

#endif
