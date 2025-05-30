#include "pop_col.h"
using std::cout;
using std::endl;

template <typename T>void pop_col_back(T** arr, const int rows, int& cols)
{
	erase_col(arr, rows, cols, cols-1);
}

template <typename T>void pop_col_front(T** arr, const int rows, int& cols)
{
	erase_col(arr, rows, cols, 0);
}

template <typename T>void erase_col(T** arr, const int rows, int& cols, const int index)
{
	if (index<0 || index>(cols-1))
	{
		cout << "Индекс введен не верно: выходит за размер массива." << endl;
		return;
	}
	for (int i = 0; i < rows; i++)
	{
		arr[i] = erase(arr[i], cols, index);
		cols++;
	}
	cols--;
}