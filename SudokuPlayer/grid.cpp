#include "grid.h"
#include <iostream>

grid::grid()
{
	for (int i = 0; i < 9; i++)
	{
		numbers.push_back(std::vector < int > {});
		for (int j = 0; j < 9; j++)
			numbers.at(i).push_back(0);
	}
}


grid::~grid()
{
}

void grid::print()
{
	std::cout << "+-------+-------+-------+" << std::endl;
	std::cout << "| " << numbers.at(0).at(0) << ' ' << numbers.at(0).at(1) << ' ' << numbers.at(0).at(2) << " | "
		<< numbers.at(0).at(3) << ' ' << numbers.at(0).at(4) << ' ' << numbers.at(0).at(5) << " | "
		<< numbers.at(0).at(6) << ' ' << numbers.at(0).at(7) << ' ' << numbers.at(0).at(8) << " |" << std::endl;
	std::cout << "| " << numbers.at(1).at(0) << ' ' << numbers.at(1).at(1) << ' ' << numbers.at(1).at(2) << " | "
		<< numbers.at(1).at(3) << ' ' << numbers.at(1).at(4) << ' ' << numbers.at(1).at(5) << " | "
		<< numbers.at(1).at(6) << ' ' << numbers.at(1).at(7) << ' ' << numbers.at(1).at(8) << " |" << std::endl;
	std::cout << "| " << numbers.at(2).at(0) << ' ' << numbers.at(2).at(1) << ' ' << numbers.at(2).at(2) << " | "
		<< numbers.at(2).at(3) << ' ' << numbers.at(2).at(4) << ' ' << numbers.at(2).at(5) << " | "
		<< numbers.at(2).at(6) << ' ' << numbers.at(2).at(7) << ' ' << numbers.at(2).at(8) << " |" << std::endl;
	std::cout << "+-------+-------+-------+" << std::endl;
	std::cout << "| " << numbers.at(3).at(0) << ' ' << numbers.at(3).at(1) << ' ' << numbers.at(3).at(2) << " | "
		<< numbers.at(3).at(3) << ' ' << numbers.at(3).at(4) << ' ' << numbers.at(3).at(5) << " | "
		<< numbers.at(3).at(6) << ' ' << numbers.at(3).at(7) << ' ' << numbers.at(3).at(8) << " |" << std::endl;
	std::cout << "| " << numbers.at(4).at(0) << ' ' << numbers.at(4).at(1) << ' ' << numbers.at(4).at(2) << " | "
		<< numbers.at(4).at(3) << ' ' << numbers.at(4).at(4) << ' ' << numbers.at(4).at(5) << " | "
		<< numbers.at(4).at(6) << ' ' << numbers.at(4).at(7) << ' ' << numbers.at(4).at(8) << " |" << std::endl;
	std::cout << "| " << numbers.at(6).at(0) << ' ' << numbers.at(6).at(1) << ' ' << numbers.at(6).at(2) << " | "
		<< numbers.at(6).at(3) << ' ' << numbers.at(6).at(4) << ' ' << numbers.at(6).at(5) << " | "
		<< numbers.at(6).at(6) << ' ' << numbers.at(6).at(7) << ' ' << numbers.at(6).at(8) << " |" << std::endl;
	std::cout << "+-------+-------+-------+" << std::endl;
	std::cout << "| " << numbers.at(6).at(0) << ' ' << numbers.at(6).at(1) << ' ' << numbers.at(6).at(2) << " | "
		<< numbers.at(6).at(3) << ' ' << numbers.at(6).at(4) << ' ' << numbers.at(6).at(5) << " | "
		<< numbers.at(6).at(6) << ' ' << numbers.at(6).at(7) << ' ' << numbers.at(6).at(8) << " |" << std::endl;
	std::cout << "| " << numbers.at(7).at(0) << ' ' << numbers.at(7).at(1) << ' ' << numbers.at(7).at(2) << " | "
		<< numbers.at(7).at(3) << ' ' << numbers.at(7).at(4) << ' ' << numbers.at(7).at(5) << " | "
		<< numbers.at(7).at(6) << ' ' << numbers.at(7).at(7) << ' ' << numbers.at(7).at(8) << " |" << std::endl;
	std::cout << "| " << numbers.at(8).at(0) << ' ' << numbers.at(8).at(1) << ' ' << numbers.at(8).at(2) << " | "
		<< numbers.at(8).at(3) << ' ' << numbers.at(8).at(4) << ' ' << numbers.at(8).at(5) << " | "
		<< numbers.at(8).at(6) << ' ' << numbers.at(8).at(7) << ' ' << numbers.at(8).at(8) << " |" << std::endl;
	std::cout << "+-------+-------+-------+" << std::endl;
}
