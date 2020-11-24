#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 7.1/Lab 7.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int q = 0;
			int w = 0;
			int row = 3;
			int col = 2;
			int** mas = new int* [row];
			for (int i = 0;i < row;i++)
				mas[i] = new int[col];
			mas[0][0] = { 1 };
			mas[0][1] = { 2 };
			mas[1][0] = { 3 };
			mas[1][1] = { 4 };
			mas[2][0] = { 5 };
			mas[2][1] = { 6 };
			int t = Calc(mas, row, col, q, w);
			for (int i = 0;i < row;i++)
				delete[] mas[i];
			delete[] mas;
			Assert::AreEqual(t, 9);

		}
	};
}
