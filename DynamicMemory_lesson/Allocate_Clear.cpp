#include "Allocate_Clear.h"

template <typename T>void Allocate(T** &arr, const int rows, const int cols)
{
	arr = new T * [rows];
	fori(0, rows) arr[i] = new T[cols]{};
}

template <typename T>void Clear(T** arr, const int rows)
{
	fori(0, rows) delete[] arr[i];
	del;
}