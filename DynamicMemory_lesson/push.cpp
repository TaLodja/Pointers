#include "push.h"
using std::cout;
using std::endl;

template <typename T>T* push_back(T arr[], int& n, const T value)
{
	return insert(arr, n, value, n);
}
template <typename T>T* push_front(T arr[], int& n, const T value)
{
	return insert(arr, n, value, 0);
}

template <typename T>T* insert(T arr[], int& n, const T value, const int index)
{
	T* buffer = new T[n + 1];
	if (buffer == nullptr)
	{
		cout << "Ощибка! Память не выделена." << endl;
		return nullptr;
	}
	if (index<0 || index>n)
	{
		cout << "Индекс введен не верно: выходит за размер массива." << endl;
		return nullptr;
	}
	fori(0, index) buffer[i] = arr[i];
	fori(index, n) buffer[i + 1] = arr[i];
	delete[] arr;
	arr = nullptr;
	buffer[index] = value;
	n++;
	return buffer;
}
