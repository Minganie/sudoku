#include "stdafx.h"
#include "CppUnitTest.h"
#include "../SudokuPlayer/grid.h"
#include "../SudokuPlayer/square.h"

namespace Microsoft{
	namespace VisualStudio {
		namespace CppUnitTestFramework {

			template<>
			static std::wstring ToString<square>(const square  & sq) {
				return L"a";
				//return sq.to_string();
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
			grid sudoku = grid("123456789234567891345678912456789123567891234678912345789123456891234567912345678");
			Assert::IsTrue(sudoku.is_done());

			grid sudoku2 = grid("12345678923456789134567891245678912 567891234678912345789123456891234567912345678");
			Assert::IsFalse(sudoku2.is_done());
		}

		TEST_METHOD(TestToString)
		{
			grid sudoku = grid("123456789234567891345678912456789123567891234678912345789123456891234567912345678");
			Assert::AreEqual(sudoku.to_string(), std::string{ "123456789234567891345678912456789123567891234678912345789123456891234567912345678" });

			grid sudoku2 = grid("123456789 34567891345678912456789123567891234678912345789123456891234567912345678");
			Assert::AreEqual(sudoku2.to_string(), std::string{ "123456789 34567891345678912456789123567891234678912345789123456891234567912345678" });
		}

		TEST_METHOD(TestAdd)
		{
			square s = square{ std::set < int > {1, 2} };
			s.add(3);
			Assert::AreEqual(s, square{ std::set < int > {1, 2, 3} });
		}

		TEST_METHOD(TestRemove)
		{
			square s = square{ std::set < int > {1, 2, 8} };
			s.rem(8);
			Assert::AreEqual(s, square{ std::set < int > {1, 2} });
		}
	};
}