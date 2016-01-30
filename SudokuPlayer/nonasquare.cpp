#include "nonasquare.h"

nonasquare::nonasquare(std::vector<square*> squares)
	: squares{ squares }
{
}

nonasquare::~nonasquare()
{
}


bool nonasquare::is_valid() const
{
	std::vector<int> counts(9, 0);
	for (square* s : squares)
	{
		try
		{
			counts[s->val()-1] += 1;
			if (counts[s->val()-1] > 1)
				return false;
		}
		catch (int)
		{
			//square is unassigned
		}
		
	}
	return true;
}
