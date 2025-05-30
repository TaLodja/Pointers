#include "pop.h"
using std::cout;
using std::endl;

template <typename T>T* pop_back(T arr[], int& n)
{
	return erase(arr, n, n - 1);
}

template <typename T>T* pop_front(T arr[], int& n)
{
	return erase(arr, n, 0);
}

template <typename T>T* erase(T arr[], int& n, const int index)
{
	T* buffer = new T[--n];
	if (buffer == nullptr)
	{
		cout << "Ошибка! Память не выделена!";
		return nullptr;
	}
	if (index < 0 || index > n)
	{
		cout << "Индекс указан не верно, выходит за размер массива." << endl;
		return nullptr;
	}
	fori(0, index) buffer[i] = arr[i];
	fori(index, n) buffer[i] = arr[i + 1];
	delete[] arr;
	arr = nullptr;
	return buffer;
}