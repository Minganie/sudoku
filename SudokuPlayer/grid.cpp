#include "grid.h"
#include <iostream>

grid::grid()
{
	for (int i = 0; i < 9*9; i++)
	{
		squares.push_back(square{});
		degree.insert(std::make_pair(20, std::make_pair(i / 9, i % 9)));
	}
	// rows
	for (int i = 0; i < 9; i++)
	{
		std::vector<square*> row_i{};
		for (int j = 0; j < 9; j++)
			row_i.push_back(&at(i, j));
		rows.push_back(nonasquare{ row_i });
	}
	// cols (could do this in the row loop, but this is clearer, will see later with metrics if it's a performance problem
	for (int j = 0; j < 9; j++)
	{
		std::vector<square*> col_j{};
		for (int i = 0; i < 9; i++)
			col_j.push_back(&at(i, j));
		cols.push_back(nonasquare{ col_j });
	}
	// nonadrants (I'd have called them 3x3's but that wasn't a valid variable name)
	for (int k = 0; k < 9; k++)
	{
		std::vector<square*> nonadrant_k{};
		int r = k / 3;
		int c = k % 3;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				nonadrant_k.push_back(&at(i+3*r, j+3*c));
			}
		}
		nonadrants.push_back(nonasquare{ nonadrant_k });
	}
}

grid::grid(std::string vals)
{
	for (auto it = vals.begin(); it != vals.end(); ++it)
	{
		if (*it != ' ')
			squares.push_back(square{ (*it) - 48 });
		else
			squares.push_back(square{});
	}
	// rows
	for (int i = 0; i < 9; i++)
	{
		std::vector<square*> row_i{};
		for (int j = 0; j < 9; j++)
			row_i.push_back(&at(i, j));
		rows.push_back(nonasquare{ row_i });
	}
	// cols (could do this in the row loop, but this is clearer, will see later with metrics if it's a performance problem
	for (int j = 0; j < 9; j++)
	{
		std::vector<square*> col_j{};
		for (int i = 0; i < 9; i++)
			col_j.push_back(&at(i, j));
		cols.push_back(nonasquare{ col_j });
	}
	// nonadrants (I'd have called them 3x3's but that wasn't a valid variable name)
	for (int k = 0; k < 9; k++)
	{
		std::vector<square*> nonadrant_k{};
		int r = k / 3;
		int c = k % 3;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				nonadrant_k.push_back(&at(i + 3 * r, j + 3 * c));
			}
		}
		nonadrants.push_back(nonasquare{ nonadrant_k });
	}

	// Compute the degree heuristic of each square
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			degree.insert(std::make_pair(find_degree(i, j), std::make_pair(i, j)));
		}
	}
}


grid::~grid()
{
}

void grid::print() const
{
	std::cout << "+-------+-------+-------+" << std::endl;
	std::cout << "| " << at(0, 0).to_string() << ' ' << at(0, 1).to_string() << ' ' << at(0, 2).to_string() << " | "
		<< at(0, 3).to_string() << ' ' << at(0, 4).to_string() << ' ' << at(0, 5).to_string() << " | "
		<< at(0, 6).to_string() << ' ' << at(0, 7).to_string() << ' ' << at(0, 8).to_string() << " |" << std::endl;
	std::cout << "| " << at(1, 0).to_string() << ' ' << at(1, 1).to_string() << ' ' << at(1, 2).to_string() << " | "
		<< at(1, 3).to_string() << ' ' << at(1, 4).to_string() << ' ' << at(1, 5).to_string() << " | "
		<< at(1, 6).to_string() << ' ' << at(1, 7).to_string() << ' ' << at(1, 8).to_string() << " |" << std::endl;
	std::cout << "| " << at(2, 0).to_string() << ' ' << at(2, 1).to_string() << ' ' << at(2, 2).to_string() << " | "
		<< at(2, 3).to_string() << ' ' << at(2, 4).to_string() << ' ' << at(2, 5).to_string() << " | "
		<< at(2, 6).to_string() << ' ' << at(2, 7).to_string() << ' ' << at(2, 8).to_string() << " |" << std::endl;
	std::cout << "+-------+-------+-------+" << std::endl;
	std::cout << "| " << at(3, 0).to_string() << ' ' << at(3, 1).to_string() << ' ' << at(3, 2).to_string() << " | "
		<< at(3, 3).to_string() << ' ' << at(3, 4).to_string() << ' ' << at(3, 5).to_string() << " | "
		<< at(3, 6).to_string() << ' ' << at(3, 7).to_string() << ' ' << at(3, 8).to_string() << " |" << std::endl;
	std::cout << "| " << at(4, 0).to_string() << ' ' << at(4, 1).to_string() << ' ' << at(4, 2).to_string() << " | "
		<< at(4, 3).to_string() << ' ' << at(4, 4).to_string() << ' ' << at(4, 5).to_string() << " | "
		<< at(4, 6).to_string() << ' ' << at(4, 7).to_string() << ' ' << at(4, 8).to_string() << " |" << std::endl;
	std::cout << "| " << at(5, 0).to_string() << ' ' << at(5, 1).to_string() << ' ' << at(5, 2).to_string() << " | "
		<< at(5, 3).to_string() << ' ' << at(5, 4).to_string() << ' ' << at(5, 5).to_string() << " | "
		<< at(5, 6).to_string() << ' ' << at(5, 7).to_string() << ' ' << at(5, 8).to_string() << " |" << std::endl;
	std::cout << "+-------+-------+-------+" << std::endl;
	std::cout << "| " << at(6, 0).to_string() << ' ' << at(6, 1).to_string() << ' ' << at(6, 2).to_string() << " | "
		<< at(6, 3).to_string() << ' ' << at(6, 4).to_string() << ' ' << at(6, 5).to_string() << " | "
		<< at(6, 6).to_string() << ' ' << at(6, 7).to_string() << ' ' << at(6, 8).to_string() << " |" << std::endl;
	std::cout << "| " << at(7, 0).to_string() << ' ' << at(7, 1).to_string() << ' ' << at(7, 2).to_string() << " | "
		<< at(7, 3).to_string() << ' ' << at(7, 4).to_string() << ' ' << at(7, 5).to_string() << " | "
		<< at(7, 6).to_string() << ' ' << at(7, 7).to_string() << ' ' << at(7, 8).to_string() << " |" << std::endl;
	std::cout << "| " << at(8, 0).to_string() << ' ' << at(8, 1).to_string() << ' ' << at(8, 2).to_string() << " | "
		<< at(8, 3).to_string() << ' ' << at(8, 4).to_string() << ' ' << at(8, 5).to_string() << " | "
		<< at(8, 6).to_string() << ' ' << at(8, 7).to_string() << ' ' << at(8, 8).to_string() << " |" << std::endl;
	std::cout << "+-------+-------+-------+" << std::endl;
}

square& grid::at(int i, int j)
{
	return squares.at(i * 9 + j);
}

const square& grid::at(int i, int j) const
{
	return squares.at(i * 9 + j);
}

std::string grid::to_string() const
{
	std::string s;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			s += at(i, j).to_string();
		}
	}

	return s;
}

bool grid::is_done() const
{
	std::string s = to_string();
	return s.find(' ') == std::string::npos;
}

bool grid::is_compatible() const
{
	for (nonasquare r : rows)
	{
		if (!r.is_compatible())
			return false;
	}
	for (nonasquare c : cols)
	{
		if (!c.is_compatible())
			return false;
	}
	for (nonasquare n : nonadrants)
	{
		if (!n.is_compatible())
			return false;
	}
	return true;
}


grid::pos_set_t grid::find_constraints(int i, int j) const
{
	int meta_i = i / 3;	// nonadrant coordinates
	int meta_j = j / 3;

	// What are the positions of the other squares in the nonadrant?
	pos_set_t pos{};
	for (int a = 0; a < 3; a++)
	{
		for (int b = 0; b < 3; b++)
		{
			if (meta_i * 3 + a != i || meta_j * 3 + b != j)
				pos.insert(std::make_pair(meta_i*3 + a, meta_j*3 + b));
		}
	}
	
	// What's the rest of the line?
	std::set<int> metas_j{ 0, 1, 2 };
	metas_j.erase(meta_j);
	for (int b : metas_j)
	{
		for (int x = 0; x < 3; x++)
			pos.insert(std::make_pair(i, b * 3 + x));
	}
	// What's the rest of the column?
	std::set<int> metas_i{ 0, 1, 2 };
	metas_i.erase(meta_i);
	for (int a : metas_i)
	{
		for (int y = 0; y < 3; y++)
			pos.insert(std::make_pair(a*3 + y, j));
	}

	// Return the complete set of (i,j) positions
	return pos;
}

int grid::find_degree(int i, int j) const
{
	int degree{};

	for (pos_t p : find_constraints(i, j))
	{
		try {
			int a = at(p.first, p.second).val();	// check if this gets deleted in release because I don't do anything with it
		} catch (int) {	// square was unassigned
			degree++;
		}
	}
	return degree;
}
