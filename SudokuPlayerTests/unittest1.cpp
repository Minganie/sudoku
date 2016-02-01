#include "stdafx.h"
#include "CppUnitTest.h"
#include <iostream>
#include "../SudokuPlayer/grid.h"
#include "../SudokuPlayer/square.h"
#include "../SudokuPlayer/nonasquare.h"

namespace Microsoft{
	namespace VisualStudio {
		namespace CppUnitTestFramework {
			template<>
			static std::wstring ToString<square>(const square& sq) {
				return std::wstring(begin(sq.to_string()), end(sq.to_string()));
			}
			template<>
			static std::wstring ToString<std::set<std::pair<int, int>>>(const std::set<std::pair<int, int>> & s) {
				std::wstringstream ws{};
				for (std::pair<int, int> p : s)
					ws << L"(" << p.first << L" " << p.second << L") ";
				return ws.str();
			}
		}
	}
}
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SudokuPlayerTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestIsDone)
		{
			grid sudoku{ "123456789234567891345678912456789123567891234678912345789123456891234567912345678" };
			Assert::IsTrue(sudoku.is_done());
		}

		TEST_METHOD(TestIsNotDone)
		{
			grid sudoku{"12345678923456789134567891245678912 567891234678912345789123456891234567912345678" };
			Assert::IsFalse(sudoku.is_done());
		}

		TEST_METHOD(TestFullToString)
		{
			grid sudoku{ "123456789234567891345678912456789123567891234678912345789123456891234567912345678" };
			Assert::AreEqual(sudoku.to_string(), std::string{ "123456789234567891345678912456789123567891234678912345789123456891234567912345678" });
		}

		TEST_METHOD(TestHoleToString)
		{
			grid sudoku{ "123456789 34567891345678912456789123567891234678912345789123456891234567912345678" };
			Assert::AreEqual(sudoku.to_string(), std::string{ "123456789 34567891345678912456789123567891234678912345789123456891234567912345678" });
		}

		TEST_METHOD(TestAtRow0)
		{
			grid sudoku{ "123456789                                                                        " };
			Assert::AreEqual(sudoku.at(0, 0).val(), 1);
		}

		TEST_METHOD(TestAtRow1)
		{
			grid sudoku{ "123      456      789                                                            " };
			Assert::AreEqual(sudoku.at(1, 1).val(), 5);
		}

		TEST_METHOD(TestAtRow2)
		{
			grid sudoku{ "123      456      789                                                            " };
			Assert::AreEqual(sudoku.at(2, 2).val(), 9);
		}

		TEST_METHOD(TestRowIteration)
		{
			grid sudoku{ "123456789                                                                        " };
			nonasquare row = sudoku.rows[0];
			int init = 1;
			for (square* s : row.squares)
			{
				int v = s->val();
				Assert::IsTrue(s->val() == init);
				++init;
			}
		}

		TEST_METHOD(TestAdd)
		{
			square s{ std::set < int > {1, 2} };
			s.add(3);
			square s2{ std::set < int > {1, 2, 3} };
			bool e = s == s2;
			//Assert::AreEqual(s, s2);
			Assert::IsTrue(s == s2);
		}

		TEST_METHOD(TestRemove)
		{
			square s{ std::set < int > {1, 2, 8} };
			s.rem(8);
			square s2{ std::set < int > {1, 2} };
			//Assert::AreEqual(s, s2);
			Assert::IsTrue(s == s2);
		}

		TEST_METHOD(TestFullValid)
		{
			square s1{ 1 };
			square s2{ 2 };
			square s3{ 3 };
			square s4{ 4 };
			square s5{ 5 };
			square s6{ 6 };
			square s7{ 7 };
			square s8{ 8 };
			square s9{ 9 };
			std::vector < square * > v{ &s1, &s2, &s3, &s4, &s5, &s6, &s7, &s8, &s9 };
			nonasquare n{ v };
			Assert::IsTrue(n.is_valid());
		}

		TEST_METHOD(TestEmptyValid)
		{
			square empty{};
			std::vector < square * > v{ &empty, &empty, &empty, &empty, &empty, &empty, &empty, &empty, &empty };
			nonasquare e{ v };
			Assert::IsTrue(e.is_valid());
		}

		TEST_METHOD(TestFullInvalid)
		{
			square s10{ 1 };
			square s1{ 1 };
			square s2{ 2 };
			square s3{ 3 };
			square s4{ 4 };
			square s5{ 5 };
			square s6{ 6 };
			square s7{ 7 };
			square s8{ 8 };
			std::vector < square * > v{ &s1, &s2, &s3, &s4, &s5, &s6, &s7, &s8, &s10 };
			nonasquare not{ v };
			Assert::IsFalse(not.is_valid());
		}

		TEST_METHOD(TestHoleInvalid)
		{
			square s1{  };
			square s2{  };
			square s3{ 3 };
			square s4{ };
			square s5{ };
			square s6{ };
			square s7{ };
			square s8{ };
			square s9{ 3 };
			std::vector < square * > v{ &s1, &s2, &s3, &s4, &s5, &s6, &s7, &s8, &s9 };
			nonasquare not{ v };
			Assert::IsFalse(not.is_valid());
		}

		TEST_METHOD(TestFullCompatible)
		{
			grid valid_full{ "123456789456789123789123456234567891567891234891234567345678912678912345912345678" };
			Assert::IsTrue(valid_full.is_compatible());
		}

		TEST_METHOD(TestHoleCompatible)
		{
			grid valid_hole{ "123456789                                                               912345678" };
			Assert::IsTrue(valid_hole.is_compatible());
		}

		TEST_METHOD(TestRowNotCompatible)
		{
			grid invalid_row{ "12145                                                                            " };
			Assert::IsFalse(invalid_row.is_compatible());
		}

		TEST_METHOD(TestColNotCompatible)
		{
			grid invalid_col{ "1        13                                                                      " };
			Assert::IsFalse(invalid_col.is_compatible());
		}

		TEST_METHOD(TestNonadrantNotCompatible)
		{
			grid invalid_3x3{ "12345678 21456789                                                                " };
			Assert::IsFalse(invalid_3x3.is_compatible());
		}

		TEST_METHOD(TestFindConstraintSquares00)
		{
			// nonadrant 0,0 = the first 3x3 on the top left; meta_i = 0, meta_j = 0
			grid valid_full{ "123456789456789123789123456234567891567891234891234567345678912678912345912345678" };
			std::set<std::pair<int, int>> res = valid_full.find_constraints(1,2);
			std::set<std::pair<int, int>> expected{
				std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(0, 2),
				std::make_pair(1, 0), std::make_pair(1, 1),
				std::make_pair(2, 0), std::make_pair(2, 1), std::make_pair(2, 2),
				std::make_pair(1, 3), std::make_pair(1, 4), std::make_pair(1, 5), 
				std::make_pair(1, 6), std::make_pair(1, 7), std::make_pair(1, 8), 
				std::make_pair(3, 2), std::make_pair(4, 2), std::make_pair(5, 2), 
				std::make_pair(6, 2), std::make_pair(7, 2), std::make_pair(8, 2) };
			Assert::AreEqual(res, expected);
		}
		TEST_METHOD(TestFindConstraintSquares01)
		{
			grid valid_full{ "123456789456789123789123456234567891567891234891234567345678912678912345912345678" };
			std::set<std::pair<int, int>> res = valid_full.find_constraints(2, 4);
			std::set<std::pair<int, int>> expected{
				std::make_pair(0, 3), std::make_pair(0, 4), std::make_pair(0, 5),
				std::make_pair(1, 3), std::make_pair(1, 4), std::make_pair(1, 5),
				std::make_pair(2, 3), std::make_pair(2, 5),
				std::make_pair(2, 0), std::make_pair(2, 1), std::make_pair(2, 2),
				std::make_pair(2, 6), std::make_pair(2, 7), std::make_pair(2, 8),
				std::make_pair(3, 4), std::make_pair(4, 4), std::make_pair(5, 4),
				std::make_pair(6, 4), std::make_pair(7, 4), std::make_pair(8, 4) };
			Assert::AreEqual(res, expected);
		}
		TEST_METHOD(TestFindConstraintSquares02)
		{
			grid valid_full{ "123456789456789123789123456234567891567891234891234567345678912678912345912345678" };
			std::set<std::pair<int, int>> res = valid_full.find_constraints(0, 8);
			std::set<std::pair<int, int>> expected{
				std::make_pair(0, 6), std::make_pair(0, 7),
				std::make_pair(1, 6), std::make_pair(1, 7), std::make_pair(1, 8),
				std::make_pair(2, 6), std::make_pair(2, 7), std::make_pair(2, 8),
				std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(0, 2),
				std::make_pair(0, 3), std::make_pair(0, 4), std::make_pair(0, 5),
				std::make_pair(3, 8), std::make_pair(4, 8), std::make_pair(5, 8),
				std::make_pair(6, 8), std::make_pair(7, 8), std::make_pair(8, 8) };
			Assert::AreEqual(res, expected);
		}
		TEST_METHOD(TestFindConstraintSquares10)
		{
			grid valid_full{ "123456789456789123789123456234567891567891234891234567345678912678912345912345678" };
			std::set<std::pair<int, int>> res = valid_full.find_constraints(3, 1);
			std::set<std::pair<int, int>> expected{
				std::make_pair(3, 0), std::make_pair(3, 2),
				std::make_pair(4, 0), std::make_pair(4, 1), std::make_pair(4, 2),
				std::make_pair(5, 0), std::make_pair(5, 1), std::make_pair(5, 2),
				std::make_pair(3, 3), std::make_pair(3, 4), std::make_pair(3, 5),
				std::make_pair(3, 6), std::make_pair(3, 7), std::make_pair(3, 8),
				std::make_pair(0, 1), std::make_pair(1, 1), std::make_pair(2, 1),
				std::make_pair(6, 1), std::make_pair(7, 1), std::make_pair(8, 1) };
			Assert::AreEqual(res, expected);
		}
		TEST_METHOD(TestFindConstraintSquares11)
		{
			grid valid_full{ "123456789456789123789123456234567891567891234891234567345678912678912345912345678" };
			std::set<std::pair<int, int>> res = valid_full.find_constraints(4, 4);
			std::set<std::pair<int, int>> expected{
				std::make_pair(3, 3), std::make_pair(3, 4), std::make_pair(3, 5),
				std::make_pair(4, 3), std::make_pair(4, 5),
				std::make_pair(5, 3), std::make_pair(5, 4), std::make_pair(5, 5),
				std::make_pair(4, 0), std::make_pair(4, 1), std::make_pair(4, 2),
				std::make_pair(4, 6), std::make_pair(4, 7), std::make_pair(4, 8),
				std::make_pair(0, 4), std::make_pair(1, 4), std::make_pair(2, 4),
				std::make_pair(6, 4), std::make_pair(7, 4), std::make_pair(8, 4) };
			Assert::AreEqual(res, expected);
		}
		TEST_METHOD(TestFindConstraintSquares12)
		{
			grid valid_full{ "123456789456789123789123456234567891567891234891234567345678912678912345912345678" };
			std::set<std::pair<int, int>> res = valid_full.find_constraints(5, 6);
			std::set<std::pair<int, int>> expected{
				std::make_pair(3, 6), std::make_pair(3, 7), std::make_pair(3, 8),
				std::make_pair(4, 6), std::make_pair(4, 7), std::make_pair(4, 8),
				std::make_pair(5, 7), std::make_pair(5, 8),
				std::make_pair(5, 0), std::make_pair(5, 1), std::make_pair(5, 2),
				std::make_pair(5, 3), std::make_pair(5, 4), std::make_pair(5, 5),
				std::make_pair(0, 6), std::make_pair(1, 6), std::make_pair(2, 6),
				std::make_pair(6, 6), std::make_pair(7, 6), std::make_pair(8, 6) };
			Assert::AreEqual(res, expected);
		}
		TEST_METHOD(TestFindConstraintSquares20)
		{
			grid valid_full{ "123456789456789123789123456234567891567891234891234567345678912678912345912345678" };
			std::set<std::pair<int, int>> res = valid_full.find_constraints(6, 0);
			std::set<std::pair<int, int>> expected{
				std::make_pair(6, 1), std::make_pair(6, 2),
				std::make_pair(7, 0), std::make_pair(7, 1), std::make_pair(7, 2),
				std::make_pair(8, 0), std::make_pair(8, 1), std::make_pair(8, 2),
				std::make_pair(6, 3), std::make_pair(6, 4), std::make_pair(6, 5),
				std::make_pair(6, 6), std::make_pair(6, 7), std::make_pair(6, 8),
				std::make_pair(0, 0), std::make_pair(1, 0), std::make_pair(2, 0),
				std::make_pair(3, 0), std::make_pair(4, 0), std::make_pair(5, 0) };
			Assert::AreEqual(res, expected);
		}
		TEST_METHOD(TestFindConstraintSquares21)
		{
			grid valid_full{ "123456789456789123789123456234567891567891234891234567345678912678912345912345678" };
			std::set<std::pair<int, int>> res = valid_full.find_constraints(7, 3);
			std::set<std::pair<int, int>> expected{
				std::make_pair(6, 3), std::make_pair(6, 4), std::make_pair(6, 5),
				std::make_pair(7, 4), std::make_pair(7, 5),
				std::make_pair(8, 3), std::make_pair(8, 4), std::make_pair(8, 5),
				std::make_pair(7, 0), std::make_pair(7, 1), std::make_pair(7, 2),
				std::make_pair(7, 6), std::make_pair(7, 7), std::make_pair(7, 8),
				std::make_pair(0, 3), std::make_pair(1, 3), std::make_pair(2, 3),
				std::make_pair(3, 3), std::make_pair(4, 3), std::make_pair(5, 3) };
			Assert::AreEqual(res, expected);
		}
		TEST_METHOD(TestFindConstraintSquares22)
		{
			grid valid_full{ "123456789456789123789123456234567891567891234891234567345678912678912345912345678" };
			std::set<std::pair<int, int>> res = valid_full.find_constraints(8, 8);
			std::set<std::pair<int, int>> expected{
				std::make_pair(6, 6), std::make_pair(6, 7), std::make_pair(6, 8),
				std::make_pair(7, 6), std::make_pair(7, 7), std::make_pair(7, 8),
				std::make_pair(8, 6), std::make_pair(8, 7),
				std::make_pair(8, 0), std::make_pair(8, 1), std::make_pair(8, 2),
				std::make_pair(8, 3), std::make_pair(8, 4), std::make_pair(8, 5),
				std::make_pair(0, 8), std::make_pair(1, 8), std::make_pair(2, 8),
				std::make_pair(3, 8), std::make_pair(4, 8), std::make_pair(5, 8) };
			Assert::AreEqual(res, expected);
		}
	};
}