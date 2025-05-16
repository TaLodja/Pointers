#include "push_col.h"

template <typename T>T** push_col_back(T** arr, const int rows, int& cols)
{
	T** buffer = new T * [rows];
	Allocate(buffer, rows, cols + 1);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j];
		}
		buffer[i][cols] = 0;
	}
	Clear(arr, rows);
	cols++;
	return buffer;
}

template <typename T>T** push_col_front(T** arr, const int rows, int& cols)
{
	T** buffer = new T * [rows];
	Allocate(buffer, rows, cols + 1);
	for (int i = 0; i < rows; i++)
	{
		buffer[i][0] = 0;
		for (int j = 0; j < cols;j++)
		{
			buffer[i][j + 1] = arr[i][j];
		}
	}
	Clear(arr, rows);
	cols++;
	return buffer;
}

template <typename T>T** insert_col(T** arr, const int rows, int& cols, const int index)
{
	T** buffer = new T * [rows];
	Allocate(buffer, rows, cols + 1);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < index; j++)
			buffer[i][j] = arr[i][j];
		for (int j = index; j < cols; j++)
			buffer[i][j + 1] = arr[i][j];
		buffer[i][index] = 0;
	}
	Clear(arr, rows);
	cols++;
	return buffer;
}