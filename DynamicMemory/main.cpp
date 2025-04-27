#include <iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
void push_front(const int n, int* pa, int* pa2, int N); //добавляет значение в начало
void insert(const int n, int* pa, int* pa2, int N, int index); // добавляет значение по указанному индексу
void pop_back(const int n, int* pa, int* pa3); //удаляет последний элемент массива
void pop_front(const int n, int* pa, int* pa3); //удаляет нулевой элемент массива
void erase(const int n, int* pa, int* pa3, int index); //удаляет элемент массива по указанному адресу

void main()
{
	setlocale(LC_ALL, "");
	int n;
	int N;
	int index;

	cout << "Введите размер исходного массива: "; cin >> n;
	int* arr = new int[n];
	int* pa = &arr[0];
	cout << "Исходный массив: ";
	FillRand(arr, n);
	Print(arr, n);

	int* arr_add = new int[n + 1];
	int* pa2 = &arr_add[0];

	cout << "Введите значение, которое следует добавить в начале массива: "; cin >> N;
	cout << "Массив после добавления значения: ";
	push_front(n, pa, pa2, N);
	Print(arr_add, n + 1);
	
	cout << "Введите значение, которое следует добавить в массив по указанному индексу: "; cin >> N;
	cout << "Введите индекс места вставки значения: "; cin >> index;
	insert(n, pa, arr_add, N, index);
	((index >= 0) && (index < n)) ? Print(arr_add, n + 1) : Print(arr, n);

	int* arr_del = new int[n - 1];
	int* pa3 = &arr_del[0];

	cout << "Массив после удаления последнего элемента: ";
	pop_back(n, pa, pa3);
	Print(arr_del, n - 1);

	cout << "Массив после удаления нулевого элемента: ";
	pop_front(n, pa, pa3);
	Print(arr_del, n - 1);

	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	cout << "Массив после удаления элемента по указанному индексу:\t";
	erase(n, pa, pa3, index);
	((index >= 0) && (index < n)) ? Print(arr_del, n - 1) : Print(arr, n);
	

	cout << endl;
	delete[] arr;
	delete[] arr_add;
	delete[] arr_del;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void push_front(const int n, int* pa, int* pa2, int N)
{
	for (int i = 0; i < n; i++)
	{
		*(pa2+i+1) = *(pa + i);
	}
	*(pa2) = N;
}
void insert(const int n, int* pa, int* pa2, int N, int index)
{
	if ((index >= 0) && (index < n))
	{
		for (int i = 0; i < index; i++, pa2++, pa++)
		{
			*(pa2) = *(pa);
		}
		push_front(n - index, pa, pa2, N);		
	}
	else
	{
		cout << "Индекс указан неверно!" << endl << endl;
		return;
	}
}
void pop_back(const int n, int* pa, int* pa3)
{
	for (int i = 0; i < n - 1; i++, pa3++, pa++)
	{
		*(pa3) = *(pa);
	}
}
void pop_front(const int n, int* pa, int* pa3)
{
	for (int i = 0; i < n - 1; i++, pa3++, pa++)
	{
		*(pa3) = *(pa + 1);
	}
}
void erase(const int n, int* pa, int* pa3, int index)
{
	if ((index >= 0) && (index < n))
	{
		pop_back(index+1, pa, pa3);
		pa += index;
		pa3 += index;
		pop_front(n - index, pa, pa3);
	}
	else
	{
		cout << "Индекс указан неверно!" << endl << endl;
		return;
	}
}