#include "pop_row.h"

template <typename T>T** pop_row_back(T** arr, int& rows, const int cols)
{
	T** buffer = new T * [--rows];
	for (int i = 0; i < rows;i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	return buffer;
}

template <typename T>T** pop_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T * [--rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	return buffer;
}

template <typename T>T** erase_row(T** arr, int& rows, const int cols, const int index)
{
	T** buffer = new T * [--rows];
	for (int i = 0; i < index; i++)
		buffer[i] = arr[i];
	for (int i = index; i < rows; i++)
		buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}