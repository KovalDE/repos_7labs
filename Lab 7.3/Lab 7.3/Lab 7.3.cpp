#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>
using namespace std;

void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
void Sum(int** a, const int rowCount, const int colCount, int** b)
{
	int Sum = 0;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			if (a[i][j] > 0 && a[i][j] % 2 == 0) Sum += a[i][j];
		}
		b[i][0] = Sum;
		b[i][1] = i;
		cout << endl;
		Sum = 0;
	}
	int tmp1;
	int tmp2;
	for (int i = 0; i < rowCount-1; i++)
	for (int j = 0; j < rowCount - i-1; j++)
	{
		if (b[j][0] > b[j + 1][0])
		{
			tmp1 = b[j][0];
			tmp2 = b[j][1];
			b[j][0] = b[j + 1][0];
			b[j][1] = b[j + 1][1];
			b[j + 1][0] = tmp1;
			b[j + 1][1] = tmp2;
		}
	}
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			cout << setw(4) << a[b[i][1]][j];
			
		}
cout << endl;
	}
	}
int Part1_Count(int** a, const int rowCount, const int colCount, int count)
{
	
	
	for (int j = 0; j < colCount; j++)
	{
		
		for (int i = 0; i < rowCount; i++)
			if (a[i][j] == 0)
			{
				count++;
				break;
			}
		
	}

	return count;
}

int main()
{
	SetConsoleOutputCP(1251);
	
	int rowCount, colCount;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	int** b = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		b[i] = new int[2];
	
	Input(a, rowCount, colCount);
	Print(a, rowCount, colCount);
	Sum(a, rowCount, colCount, b);
	cout << endl;
	cout << "Кількість стовпчиків з нульовими елементами: " << Part1_Count(a, rowCount, colCount,0);
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	for (int i = 0; i < rowCount; i++)
		delete[] b[i];
	delete[] b;
	return 0;
}

void Input(int** a, const int rowCount, const int colCount)
{
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
		cout << endl;
	}
}

void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}


