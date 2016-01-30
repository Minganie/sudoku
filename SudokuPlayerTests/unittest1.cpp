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
			static std::wstring ToString<square>(const square  & sq) {
				return std::wstring(begin(sq.to_string()), end(sq.to_string()));
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
	};
}