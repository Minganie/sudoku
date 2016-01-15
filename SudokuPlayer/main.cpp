#include <iostream>
#include "grid.h"

using namespace std;

int main()
{
	cout << "Initializing full sudoku grid" << endl;
	grid sudoku = grid("123456789234567891345678912456789123567891234678912345789123456891234567912345678");
	sudoku.print();
	cout << "Grid is detected done? " << sudoku.is_done() << endl << endl;
	cout << "Initializing not full sudoku grid" << endl;
	grid sudoku2 = grid("12345678923456789134567891245678912356789123467891234578912345689123456791234 678");
	sudoku2.print();
	cout << "Grid is detected done? " << sudoku2.is_done() << endl << endl;
}