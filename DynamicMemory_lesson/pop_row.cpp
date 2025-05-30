#include "pop_row.h"
using std::cout;
using std::endl;

template <typename T>T** pop_row_back(T** arr, int& rows, const int cols)
{
	return erase_row(arr, rows, cols, rows-1);
}

template <typename T>T** pop_row_front(T** arr, int& rows, const int cols)
{
	return erase_row(arr, rows, cols, 0);
}

template <typename T>T** erase_row(T** arr, int& rows, const int cols, const int index)
{
	if (index<0 || index>(rows-1))
	{
		cout << "Индекс введен не верно: выходит за размер массива." << endl;
		return nullptr;
	}
	delete[] arr[index];
	arr[index] = nullptr;
	return erase(arr,rows,index);
}