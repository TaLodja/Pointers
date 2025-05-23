#include "push.h"

template <typename T>T* push_back(T arr[], int& n, const T value)
{
	allocate_p(n + 1);
	fori(0, n) according;
	del;
	push_val(n);
	n++;
	ret;
}
template <typename T>T* push_front(T arr[], int& n, const T value)
{
	allocate_p(n + 1);
	fori(0, n) shift_push;
	del;
	push_val(0);
	n++;
	ret;
}

template <typename T>T* insert(T arr[], int& n, const T value, const int index)
{
	allocate_p(n + 1);
	fori(0, index) according;
	fori(index, n) shift_push;
	del;
	push_val(index);
	n++;
	ret;
}
