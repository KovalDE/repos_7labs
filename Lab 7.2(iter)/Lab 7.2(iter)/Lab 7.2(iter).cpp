// Lab_7_2_1.cpp
// < Коваль,  Дмитро >
// Лабораторна робота № 7.2.1)
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 14

#include <iostream>
#include <iomanip>
#include <time.h>
#include<windows.h>
using namespace std;
void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);


int Max(int** a, const int n, int& i1, int& j1)
{
	int max = a[0][1];
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i][j] > max)
			{
				max = a[i][j];
				i1 = i;
				j1 = j;

			}
	return max;
}
int Min(int** a, const int n, int& i2, int& j2)
{
	int min = a[1][0];
	for (int i = 0; i < n; i++)
		for (int j = i - 1; j >= 0; j--)
			if (a[i][j] < min)
			{
				min = a[i][j];
				i2 = i;
				j2 = j;

			}
	return min;

}
void Swap(int** a, const int n, int& i1, int& j1, int& i2, int& j2)
{
	int tmp = a[i1][j1];
	a[i1][j1] = a[i2][j2];
	a[i2][j2] = tmp;

}
void Sum(int** a, const int n, int& i1, int& j1, int& i2, int& j2)
{
	cout << "Сума найбільшого і найменшого елементів: " << Min(a, n, i1, j1) + Max(a, n, i2, j2);
}

int main()
{
	SetConsoleOutputCP(1251);
	int i1, j1;
	int i2, j2;

	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 65;
	int n;
	cout << "n = "; cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	Create(a, n, Low, High);
	Print(a, n);
	cout << "Максимальне значення елемента над головною діагоналлю: " << ' ' << Max(a, n, i1, j1);
	cout << endl;
	cout << "Мінімальне значення елемента під головною діагоналлю: " << ' ' << Min(a, n, i2, j2);
	cout << endl;
	Sum(a, n, i1, j1, i2, j2);
	cout << endl;
	cout << "Матриця зі зміненими місцями максимальним і мінімальним елементами: " << endl;
	Swap(a, n, i1, j1, i2, j2);
	Print(a, n);

	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
void Create(int** a, const int n, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
