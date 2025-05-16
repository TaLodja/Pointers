#include "push_row.h"

template <typename T>T** push_row_back(T** arr, int& rows, const int cols)
{
	T** buffer = new T * [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	buffer[rows] = new T[cols]{};
	rows++;
	return buffer;
}

template <typename T>T** push_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T * [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[0] = new T[cols]{};
	rows++;
	return buffer;
}

template <typename T>T** insert_row(T** arr, int& rows, const int cols, const int index)
{
	T** buffer = new T * [rows + 1];
	for (int i = 0; i < index; i++)
		buffer[i] = arr[i];
	for (int i = index; i < rows; i++)
		buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[index] = new T[cols]{};
	rows++;
	return buffer;
}