#include "Allocate_Clear.h"
using std::cout;
using std::endl;

template <typename T>T** Allocate(const int rows, const int cols)
{
	T** arr = new T * [rows];
	if (arr == nullptr)
	{
		cout << "Ошибка! Память не выделена." << endl;
		return nullptr;
	}
	fori(0, rows) arr[i] = new T[cols]{};
	return arr;
}

template <typename T>void Clear(T** arr, const int rows)
{
	fori(0, rows) delete[] arr[i];
	delete [] arr;
	arr = nullptr;
}