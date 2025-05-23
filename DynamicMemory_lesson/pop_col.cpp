#include "pop_col.h"

template <typename T>T** pop_col_back(T** arr, const int rows, int& cols)
{
	allocate_pp(rows);
	Allocate(buffer, rows, --cols);
	fori(0, rows) forj(0, cols) according_2;
	Clear(arr, rows);
	ret;
}

template <typename T>T** pop_col_front(T** arr, const int rows, int& cols)
{
	allocate_pp(rows);
	Allocate(buffer, rows, --cols);
	fori(0, rows) forj(0, cols) shift_pop_2;
	Clear(arr, rows);
	ret;
}

template <typename T>T** erase_col(T** arr, const int rows, int& cols, const int index)
{
	allocate_pp(rows);
	Allocate(buffer, rows, --cols);
	fori(0, rows)
	{
		forj(0, index) according_2;
		forj(index, cols) shift_pop_2;
	}
	Clear(arr, rows);
	ret;
}