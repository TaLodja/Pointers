#include "FillRand.h"

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	fori(0, n) arr[i] = rand() %(maxRand - minRand) + minRand;
}

void FillRand(double arr[], const int n)
{
	fori(0, n) arr[i] = double(rand() %10000)/100;
}

void FillRand(char arr[], const int n, int minRand, int maxRand)
{
	fori(0, n) arr[i] = rand() % (maxRand - minRand) + minRand;
}

void FillRand(int** arr, const int rows, const int cols, int minRand, int maxRand)
{
	fori(0, rows) forj(0, cols) arr[i][j] = rand() % (maxRand - minRand) + minRand;
}

void FillRand(double** arr, const int rows, const int cols)
{
	fori(0, rows) forj(0, cols) arr[i][j] = double(rand() % 10000) / 100;
}

void FillRand(char** arr, const int rows, const int cols, int minRand, int maxRand)
{
	fori(0, rows) forj(0, cols) arr[i][j] = rand() % (maxRand - minRand) + minRand;
}