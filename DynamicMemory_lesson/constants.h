#pragma once
#define tab				"\t"
#define delimiter		"\n--------------------------------------------\n"
#define allocate_p(x)	T* buffer = new T[x]
#define allocate_pp(x)	T** buffer = new T*[x]
#define fillrand		rand() % 100
#define fori(x, y)		for (int i=x; i<y; i++)
#define forj(x, y)		for (int j=x; j<y; j++)
#define according		buffer[i] = arr[i]
#define according_2		buffer[i][j] = arr[i][j]
#define shift_pop		buffer[i] = arr[i+1]
#define shift_pop_2		buffer[i][j] = arr[i][j + 1]
#define shift_push		buffer[i+1] = arr[i]
#define shift_push_2	buffer[i][j + 1] = arr[i][j]
#define push_val(x)		buffer[x] = value
#define del				delete[] arr
#define ret				return buffer