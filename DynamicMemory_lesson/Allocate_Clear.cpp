#include "Allocate_Clear.h"

template <typename T>void Allocate(T** arr, const int rows, const int cols)
{
	//2) Выделяем память под строки двумерного динамического массива:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols];
	}
}

template <typename T>void Clear(T** arr, const int rows)
{
	//1) Сначала удаляем строки:
	for (int i = 0; i < rows;i++)
	{
		delete[] arr[i];
	}
	//2) Удаляем массив указателей:
	delete[] arr;
}