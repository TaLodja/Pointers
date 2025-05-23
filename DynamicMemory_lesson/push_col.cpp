#include "push_col.h"

template <typename T>T** push_col_back(T** arr, const int rows, int& cols)
{
	allocate_pp(rows);
	Allocate(buffer, rows, cols + 1);
	fori(0, rows)
	{
		forj(0, cols) according_2;
		buffer[i][cols] = 0;
	}
	Clear(arr, rows);
	cols++;
	ret;
}

template <typename T>T** push_col_front(T** arr, const int rows, int& cols)
{
	allocate_pp(rows);
	Allocate(buffer, rows, cols + 1);
	fori(0, rows)
	{
		buffer[i][0] = 0;
		forj(0, cols) shift_push_2;
	}
	Clear(arr, rows);
	cols++;
	ret;
}

template <typename T>T** insert_col(T** arr, const int rows, int& cols, const int index)
{
	allocate_pp(rows);
	Allocate(buffer, rows, cols + 1);
	fori(0, rows)
	{
		forj(0, index) according_2;
		forj(index, cols) shift_push_2;
		buffer[i][index] = 0;
	}
	Clear(arr, rows);
	cols++;
	ret;
}