﻿#include <iostream>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n--------------------------------------------\n"

void Allocate(int** &arr, const int rows, const int cols);
void Clear(int** arr, const int rows);

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);

void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, const int value);
int* push_front(int arr[], int& n, const int value);
int* insert(int arr[], int& n, const int value, const int index);

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, const int index);


int** push_row_back(int** arr, int& rows, const int cols);
int** pop_row_back(int** arr, int& rows, const int cols);

int** push_row_front(int** arr, int& rows, const int cols);
int** pop_row_front(int** arr, int& rows, const int cols);

int** insert_row(int** arr, int& rows, const int cols, const int index);
int** erase_row(int** arr, int& rows, const int cols, const int index);

void push_col_back(int** arr, const int rows, int& cols);
void pop_col_back(int** arr, const int rows, int& cols);

void push_col_front(int** arr, const int rows, int& cols);
void pop_col_front(int** arr, const int rows, int& cols);

void insert_col(int** arr, const int rows, int& cols, const int index);
void erase_col(int** arr, const int rows, int& cols, const int index);


//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите размер исходного массива: "; cin >> n;
	int* arr = new int[n];
	cout << "Исходный массив: ";
	FillRand(arr, n);
	Print(arr, n);

	/*cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;*/

	int value;
	cout << "Введите значение, добавляемое в конце массива: "; cin >> value;

	arr = push_back(arr, n, value);

	//7) Значение добавлено, проверяем результат:
	Print(arr, n);

	cout << "Введите значение, добавляемое в начале массива: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение элемента, добавляемое по указанному индексу: "; cin >> value;
	arr = insert(arr, n, value, index);
	Print(arr, n);

	cout << "Массив после удаления последнего элемента: " << endl;
	Print(arr = pop_back(arr, n), n);

	cout << "Массив после удаления элемента по индексу " << index << ": " << endl;
	arr = erase(arr, n, index);
	Print(arr, n);

	cout << "Массив после удаления нулевого элемента: " << endl;
	Print(arr = pop_front(arr, n), n);

	delete[] arr;
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	int rows;
	int cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;
	cout << delimiter;

	int** arr;
	Allocate(arr, rows, cols);

	FillRand(arr, rows, cols);
	cout << "Вывод массива через оператотр индексирования:" << endl;
	Print(arr, rows, cols);

	cout << "Вывод массива через арифметику указателей и оператор разыменования:" << endl;
	for (int i = 0; i < rows; i++)
	{
		int* ptr = *(arr + i);
		for (int j = 0; j < cols; j++)
		{
			cout << *(ptr + j) << "\t";
		}
		cout << endl;
	}

	cout << delimiter;

	cout << "Массив после добавления строки в его конец: " << endl;
	Print(arr = push_row_back(arr, rows, cols), rows, cols);

	cout << "Массив после добавления строки в его начало: " << endl;
	Print(arr = push_row_front(arr, rows, cols), rows, cols);

	int index_rows, index_cols;
	cout << "Введите индекс добавляемой строки: "; cin >> index_rows;
	cout << "Массив после добавления строки по указанному индексу: " << endl;
	Print(arr = insert_row(arr, rows, cols, index_rows), rows, cols);

	cout << "Массив после добавления столбца в конец: " << endl;
	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Массив после добавления столбца в начало: " << endl;
	push_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Введите индекс добавляемого столбца: "; cin >> index_cols;
	cout << "Массив после добавления столбца по указанному индексу: " << endl;
	insert_col(arr, rows, cols, index_cols);
	Print(arr, rows, cols);

	cout << "Массив после удаления строки из его конца: " << endl;
	Print(arr = pop_row_back(arr, rows, cols), rows, cols);

	cout << "Массив после удаления строки по индексу: " << index_rows << endl;
	Print(arr = erase_row(arr, rows, cols, index_rows), rows, cols);

	cout << "Массив после удаления строки из его начала: " << endl;
	Print(arr = pop_row_front(arr, rows, cols), rows, cols);

	cout << "Массив после удаления столбца из его конца: " << endl;
	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Массив после удаления столбца по индексу: " << index_cols << endl;
	erase_col(arr, rows, cols, index_cols);
	Print(arr, rows, cols);

	cout << "Массив после удаления столбца из его начала: " << endl;
	pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	Clear(arr, rows);
#endif // DYNAMIC_MEMORY_2

}

void Allocate(int** &arr, const int rows, const int cols)
{
	//1) Создаем массив указателей:
	arr = new int* [rows];
	//2) Выделяем память под строки двумерного динамического массива:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
}

void Clear(int** arr, const int rows)
{
	//1) Сначала удаляем строки:
	for (int i = 0; i < rows;i++)
	{
		delete[] arr[i];
	}
	//2) Удаляем массив указателей:
	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}

void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows;i++)
	{
		for (int j = 0; j < cols;j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

void Print(int arr[], const int n)
{
	cout << arr << ":\n";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows;i++)
	{
		for (int j = 0; j < cols;j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << delimiter << endl;
}

int* push_back(int arr[], int& n, const int value)
{
	//1) Создаем буферный массив нужного размера:
	int* buffer = new int[n + 1];

	//2) Копируем все содержимое исходного массива в буферный
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	//3) Удаляем исходный массив:
	delete[] arr;

	//4) Подменяем адрес в указателе 'arr' адресом нового массива
	arr = buffer;

	//5) Только после всего этого в конце массива появляется элемент,
	// в который можно сохранить добавляемое значение
	arr[n] = value;

	//6) После того, как в массив добавился элемент,
	// количество его элементов увеличивается на 1
	n++;

	return arr;
}
int* push_front(int arr[], int& n, const int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}

int* insert(int arr[], int& n, const int value, const int index)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		(i < index ? buffer[i] : buffer[i + 1]) = arr[i];
	}
	/*for (int i = 0; i < index; i++)
		buffer[i] = arr[i];
	for (int i = index; i < n; i++)
		buffer[i + 1] = arr[i];*/
	delete[] arr;
	buffer[index] = value;
	n++;
	return buffer;
}

int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0;i < n;i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}

int* erase(int arr[], int& n, const int index)
{
	int* buffer = new int[--n];
	for (int i = 0;i < n;i++)
	{
		buffer[i] = (i < index ? arr[i] : arr[i + 1]);
	}
	delete[] arr;
	return buffer;
}

int** push_row_back(int** arr, int& rows, const int cols)
{
	//1) Создаем буферный массив указателей нужного размера
	int** buffer = new int* [rows + 1];

	//2) Копируем адреса строк в буферный массив указателей
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}

	//3) Удаляем исходный массив указателей
	delete[] arr;

	//4) Создаем добавляемую строку и записываем ее адрес в массив указателей
	buffer[rows] = new int[cols] {};

	//5) При добавлении в массив строки, количество его строк увеличивается на один
	rows++;

	//6) Возвращаем новый массив на место вызова
	return buffer;
}

int** pop_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows;i++) buffer[i] = arr[i];
	delete[] arr[rows];
	delete[] arr;
	return buffer;
}

int** push_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++) buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = new int[cols] {};
	rows++;
	return buffer;
}

int** pop_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++) buffer[i] = arr[i + 1];
	delete[] arr[0];
	delete[] arr;
	return buffer;
}

int** insert_row(int** arr, int& rows, const int cols, const int index)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)
		(i < index ? buffer[i] : buffer[i + 1]) = arr[i];
	delete[] arr;
	buffer[index] = new int[cols] {};
	rows++;
	return buffer;
}

int** erase_row(int** arr, int& rows, const int cols, const int index)
{
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)
		buffer[i] = (i < index ? arr[i] : arr[i + 1]);
	delete[] arr[index];
	delete[] arr;
	return buffer;
}

void push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

void pop_col_back(int** arr, const int rows, int& cols)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols];
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
}

void push_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		buffer[0] = 0;
		for (int j = 0; j < cols;j++) buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

void pop_col_front(int** arr, const int rows, int& cols)
{
	cols--;
	for (int i = 0; i < rows;i++)
	{
		int* buffer = new int[cols];
		for (int j = 0; j < cols;j++) buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
}

void insert_col(int** arr, const int rows, int& cols, const int index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)
			(j < index ? buffer[j] : buffer[j + 1]) = arr[i][j];
		buffer[index] = 0;
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

void erase_col(int** arr, const int rows, int& cols, const int index)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols];
		for (int j = 0; j < cols;j++)
			buffer[j] = (j < index ? arr[i][j] : arr[i][j + 1]);
		delete[] arr[i];
		arr[i] = buffer;
	}
}