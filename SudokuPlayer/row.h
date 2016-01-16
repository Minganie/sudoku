#ifndef ROW_H
#define ROW_H

#include <vector>
#include "square.h"

class row
{
	std::vector<square&> squares;
public:
	row(std::vector<square&>);
	~row();
};

#endif
