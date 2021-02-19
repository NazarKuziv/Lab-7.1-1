// Lab_7_1-1.cpp
// < Кузів Назар >
// Лабораторна робота № 7.1-1
// Пошук заданих елементів матриці.
// Варіант 7

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;
void Create(int** R, const int rowCount, const int colCount, 
	const int Low, const int High, int i, int j)
{
	R[i][j] = Low + rand() % (High - Low + 1);

	if (j < colCount - 1)
		Create(R, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
			Create(R, rowCount, colCount, Low, High, i + 1, 0);
}

void Print(int** R, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << R[i][j];
	if (j < colCount - 1)
		Print(R, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(R, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}
int Sum(int** R, const int rowCount, const int colCount, int i, int j, int S)
{
	if (R[i][j] % 7 == 0 || i % 2 != 0 || j % 2 != 0)
		S += R[i][j];

	if (j < colCount - 1)
		Sum(R, rowCount, colCount, i, j + 1, S);
	else
		if (i < rowCount - 1)
			Sum(R, rowCount, colCount, i + 1, 0, S);
		else
			return S;
}
int NumberIndex(int** R, const int rowCount, const int colCount, int i, int j, int k)
{
	if (R[i][j] % 7 == 0 || i % 2 != 0 || j % 2 != 0)
		k++;

	if (j < colCount - 1)
		NumberIndex(R, rowCount, colCount, i, j + 1, k);
	else
		if (i < rowCount - 1)
			NumberIndex(R, rowCount, colCount, i + 1, 0, k);
		else
			return k;
}
void MakeZero(int** R, const int rowCount, const int colCount, int i, int j)
{
	if (R[i][j] % 7 == 0 || i % 2 != 0 || j % 2 != 0)
		R[i][j] = 0;

	if (j < colCount - 1)
		MakeZero(R, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
			MakeZero(R, rowCount, colCount, i + 1, 0);
			
}
int main()
{
	srand((unsigned)time(NULL));

	//Діапазон значень елементів матриці
	int Low = 16;
	int High = 97;

	int rowCount = 8; // Кількість рядків
	int colCount = 6; // Кількість стовпців

	int** R = new int* [rowCount];

	for (int i = 0; i < rowCount; i++)
		R[i] = new int[colCount];

	Create(R, rowCount, colCount, Low, High,0,0);
	cout << endl;
	Print(R, rowCount, colCount, 0, 0);

	int S = 0; // Сума елементів, які задовольняють вказаному критерію;
	int k = 0; // Кількість елементів, які задовольняють вказаному критерію;

	S = Sum(R, rowCount, colCount, 0, 0, S);
	k = NumberIndex(R, rowCount, colCount, 0, 0, k);

	cout << setw(6) << "S = " << S << endl;
	cout << setw(6) << "k = " << k << endl;

	MakeZero(R, rowCount, colCount, 0, 0);
	
	cout << endl;
	Print(R, rowCount, colCount, 0, 0);

	for (int i = 0; i < rowCount; i++)
		delete[] R[i];
	delete[] R;

	return 0;
}