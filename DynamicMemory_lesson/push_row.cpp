#include "push_row.h"

template <typename T>T** push_row_back(T** arr, int& rows, const int cols)
{
	allocate_pp(rows + 1);
	fori(0, rows) according;
	del;
	buffer[rows] = new T[cols]{};
	rows++;
	ret;
}

template <typename T>T** push_row_front(T** arr, int& rows, const int cols)
{
	allocate_pp(rows + 1);
	fori(0, rows) shift_push;
	del;
	buffer[0] = new T[cols]{};
	rows++;
	ret;
}

template <typename T>T** insert_row(T** arr, int& rows, const int cols, const int index)
{
	allocate_pp(rows + 1);
	fori(0, index) according;
	fori(index, rows) shift_push;
	del;
	buffer[index] = new T[cols]{};
	rows++;
	ret;
}