#include "FillRand.h"

void FillRand(int arr[], const int n)
{
	fori(0,n) arr[i] = fillrand;
}

void FillRand(double arr[], const int n)
{
	fori(0, n)
	{
		arr[i] = fillrand;
		arr[i] /= 100;
	}
}

void FillRand(int** arr, const int rows, const int cols)
{
	fori(0, rows) forj(0, cols) arr[i][j] = fillrand;
}

void FillRand(double** arr, const int rows, const int cols)
{
	fori(0, rows) forj(0, cols)
	{
			arr[i][j] = fillrand;
			arr[i][j] /= 100;
	}
}