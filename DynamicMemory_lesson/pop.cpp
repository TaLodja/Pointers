#include "pop.h"

template <typename T>T* pop_back(T arr[], int& n)
{
	allocate_p(--n);
	fori(0, n) according;
	del;
	ret;
}

template <typename T>T* pop_front(T arr[], int& n)
{
	allocate_p(--n);
	fori(0, n) shift_pop;
	del;
	ret;
}

template <typename T>T* erase(T arr[], int& n, const int index)
{
	allocate_p(--n);
	fori(0, index) according;
	fori(index, n) shift_pop;
	del;
	ret;
}