#include "Print.h"
using std::cout;
using std::endl;

template <typename T>void Print(T arr[], const int n)
{
	//cout << arr << ":\n";
	fori(0,n) cout << arr[i] << tab;
	cout << endl;
}

template <typename T>void Print(T** arr, const int rows, const int cols)
{
	fori(0, rows)
	{
		forj(0, cols) cout << arr[i][j] << tab;
		cout << endl;
	}
	cout << delimiter << endl;
}

/*cout << "Вывод массива через арифметику указателей и оператор разыменования:" << endl;
	for (int i = 0; i < rows; i++)
	{
		int* ptr = *(arr + i);
		for (int j = 0; j < cols; j++)
		{
			cout << *(ptr + j) << tab;
		}
		cout << endl;
	}*/