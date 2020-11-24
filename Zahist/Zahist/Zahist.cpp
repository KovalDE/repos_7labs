
#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>
using namespace std;

void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
void Zadacha1(int** a, const int rowCount, const int colCount,int i,int j,int r)
{
	if (a[i][j] != a[rowCount - j - 1][colCount - i - 1])r = 0;

	if (j < colCount - 1) Zadacha1(a, rowCount, colCount, i, j + 1, r);
}


void Zadacha(int** a, const int rowCount, const int colCount,int i,int j)
{
	int r = 1;
	Zadacha1(a, rowCount, colCount,i, 0,1);
	if (i < rowCount - 1) Zadacha(a,rowCount,colCount,i+1,j);
	else {
if (r == 1)
cout << "Вітаю, матриця симетрична"; 
else cout << "На жаль, матриця не є симетрична"<<endl;
}
}


int main()
{
	SetConsoleOutputCP(1251);

	int rowCount, colCount;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;
	if (rowCount != colCount)
	{
		cout << "Неможливо визначити симетричність";
		return 0;
    }
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	
	Input(a, rowCount, colCount);
	Print(a, rowCount, colCount);
	cout << endl;
	cout << "Відповідь: ";
	Zadacha(a, rowCount, colCount, 0,0);
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
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

