#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 7.3/Lab 7.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest3
{
	TEST_CLASS(UnitTest3)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int i1, j1;
			int i2, j2;
			int row = 3;
			int col = 3;
			int n = 3;
			int** mas = new int* [row];
			for (int i = 0;i < row;i++)
				mas[i] = new int[col];
			mas[0][0] = { 0 };
			mas[0][1] = { 2 };
			mas[0][2] = { 12 };
			mas[1][0] = { 3 };
			mas[1][1] = { 4 };
			mas[1][2] = { 9 };
			mas[2][0] = { 5 };
			mas[2][1] = { 6 };
			mas[2][2] = { 0 };
			int t = Part1_Count(mas, row, col, 0);
			for (int i = 0;i < row;i++)
				delete[] mas[i];
			delete[] mas;
			Assert::AreEqual(t, 2);
		}
	};
}
