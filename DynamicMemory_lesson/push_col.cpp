#include "push_col.h"
using std::cout;
using std::endl;

template <typename T>void push_col_back(T** arr, const int rows, int& cols)
{
	insert_col(arr, rows, cols, cols);
}

template <typename T>void push_col_front(T** arr, const int rows, int& cols)
{
	insert_col(arr, rows, cols, 0);
}

template <typename T>void insert_col(T** arr, const int rows, int& cols, const int index)
{
	if (index<0 || index>cols)
	{
		cout << "Индекс введен не верно: выходит за размер массива." << endl;
		return;
	}
	for (int i = 0; i < rows; i++)
	{
		arr[i] = insert(arr[i], cols, T(), index);
		cols--;
	}
	cols++;
}