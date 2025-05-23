#include "pop_row.h"

template <typename T>T** pop_row_back(T** arr, int& rows, const int cols)
{
	allocate_pp(--rows);
	fori(0, rows) according;
	del;
	ret;
}

template <typename T>T** pop_row_front(T** arr, int& rows, const int cols)
{
	allocate_pp(--rows);
	fori(0, rows) shift_pop;
	del;
	ret;
}

template <typename T>T** erase_row(T** arr, int& rows, const int cols, const int index)
{
	allocate_pp(--rows);
	fori(0, index) according;
	fori(index, rows) shift_pop;
	del;
	ret;
}