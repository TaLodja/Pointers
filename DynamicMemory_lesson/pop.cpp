#include "pop.h"

template <typename T>T* pop_back(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0;i < n;i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

template <typename T>T* pop_front(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}

template <typename T>T* erase(T arr[], int& n, const int index)
{
	T* buffer = new T[--n];
	for (int i = 0; i < index; i++)
		buffer[i] = arr[i];
	for (int i = index; i < n; i++)
		buffer[i] = arr[i+1];
	delete[] arr;
	return buffer;
}