#include "pop_col.h"

template <typename T>T** pop_col_back(T** arr, const int rows, int& cols)
{
	T** buffer = new T * [rows];
	Allocate(buffer, rows, --cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	Clear(arr, rows);
	return buffer;
}

template <typename T>T** pop_col_front(T** arr, const int rows, int& cols)
{
	T** buffer = new T * [rows];
	Allocate(buffer, rows, --cols);
	for (int i = 0; i < rows;i++)
	{
		for (int j = 0; j < cols;j++)
		{
			buffer[i][j] = arr[i][j + 1];
		}
	}
	Clear(arr, rows);
	return buffer;
}

template <typename T>T** erase_col(T** arr, const int rows, int& cols, const int index)
{
	T** buffer = new T * [rows];
	Allocate(buffer, rows, --cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < index; j++)
			buffer[i][j] = arr[i][j];
		for (int j = index; j < cols; j++)
			buffer[i][j] = arr[i][j+1];
	}
	Clear(arr, rows);
	return buffer;
}