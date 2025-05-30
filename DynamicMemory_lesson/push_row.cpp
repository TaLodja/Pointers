#include "push_row.h"
using std::cout;
using std::endl;

template <typename T>T** push_row_back(T** arr, int& rows, const int cols)
{
	return insert_row(arr, rows, cols, rows);
}

template <typename T>T** push_row_front(T** arr, int& rows, const int cols)
{
	return insert_row(arr,rows,cols,0);
}

template <typename T>T** insert_row(T** arr, int& rows, const int cols, const int index)
{
	if (index<0 || index>rows)
	{
		cout << "Индекс введен не верно: выходит за размер массива." << endl;
		return nullptr;
	}
	return insert(arr, rows, new T[cols]{}, index);
}