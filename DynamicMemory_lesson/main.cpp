#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n--------------------------------------------\n"

template<typename T>void Allocate(T** &arr, const int rows, const int cols);
template<typename T>void Clear(T** arr, const int rows);

void FillRand(int arr[], const int n);
void FillRand(double arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);
void FillRand(double** arr, const int rows, const int cols);

template<typename T>void Print(T arr[], const int n);
template<typename T>void Print(T** arr, const int rows, const int cols);

template<typename T>T* push_back(T arr[], int& n, const T value);
template<typename T>T* push_front(T arr[], int& n, const T value);
template<typename T>T* insert(T arr[], int& n, const T value, const int index);

template<typename T>T* pop_back(T arr[], int& n);
template<typename T>T* pop_front(T arr[], int& n);
template<typename T>T* erase(T arr[], int& n, const int index);

template<typename T>T** push_row_back(T** arr, int& rows, const int cols);
template<typename T>T** pop_row_back(T** arr, int& rows, const int cols);

template<typename T>T** push_row_front(T** arr, int& rows, const int cols);
template<typename T>T** pop_row_front(T** arr, int& rows, const int cols);

template<typename T>T** insert_row(T** arr, int& rows, const int cols, const int index);
template<typename T>T** erase_row(T** arr, int& rows, const int cols, const int index);

template<typename T>void push_col_back(T** arr, const int rows, int& cols);
template<typename T>void pop_col_back(T** arr, const int rows, int& cols);

template<typename T>void push_col_front(T** arr, const int rows, int& cols);
template<typename T>void pop_col_front(T** arr, const int rows, int& cols);

template<typename T>void insert_col(T** arr, const int rows, int& cols, const int index);
template<typename T>void erase_col(T** arr, const int rows, int& cols, const int index);


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

	double** arr;
	Allocate(arr, rows, cols);

	FillRand(arr, rows, cols);
	cout << "Вывод массива через оператотр индексирования:" << endl;
	Print(arr, rows, cols);

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

template<typename T>void Allocate(T** &arr, const int rows, const int cols)
{
	arr = new T * [rows];
	for (int i = 0; i < rows; i++) arr[i] = new T[cols] {};
}

template<typename T>void Clear(T** arr, const int rows)
{
	for (int i = 0; i < rows;i++) delete[] arr[i];
	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++) arr[i] = rand() % 100;
}

void FillRand(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
		arr[i] /= 100;
	}
}

void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows;i++)
	{
		for (int j = 0; j < cols;j++) arr[i][j] = rand() % 100;
	}
}

void FillRand(double** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows;i++)
	{
		for (int j = 0; j < cols;j++)
		{
			arr[i][j] = rand() % 100;
			arr[i][j] /= 100;
		}
	}
}

template<typename T>void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++) cout << arr[i] << tab;
	cout << endl;
}

template<typename T>void Print(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows;i++)
	{
		for (int j = 0; j < cols;j++) cout << arr[i][j] << tab;
		cout << endl;
	}
	cout << delimiter << endl;
}

template<typename T>T* push_back(T arr[], int& n, const T value)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
	return arr;
}
template<typename T>T* push_front(T arr[], int& n, const T value)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++) buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}

template<typename T>T* insert(T arr[], int& n, const T value, const int index)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < index; i++) buffer[i] = arr[i];
	for (int i = index; i < n; i++) buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[index] = value;
	n++;
	return buffer;
}

template<typename T>T* pop_back(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0;i < n;i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

template<typename T>T* pop_front(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}

template<typename T>T* erase(T arr[], int& n, const int index)
{
	T* buffer = new T[--n];
	for (int i = 0;i < index;i++) buffer[i] = arr[i];
	for (int i = index;i < n;i++) buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}

template<typename T>T** push_row_back(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];
	delete[] arr;
	buffer[rows] = new T[cols] {};
	rows++;
	return buffer;
}

template<typename T>T** pop_row_back(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [--rows];
	for (int i = 0; i < rows;i++) buffer[i] = arr[i];
	delete[] arr[rows];
	delete[] arr;
	return buffer;
}

template<typename T>T** push_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < rows; i++) buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = new T[cols] {};
	rows++;
	return buffer;
}

template<typename T>T** pop_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [--rows];
	for (int i = 0; i < rows; i++) buffer[i] = arr[i + 1];
	delete[] arr[0];
	delete[] arr;
	return buffer;
}

template<typename T>T** insert_row(T** arr, int& rows, const int cols, const int index)
{
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < index; i++) buffer[i] = arr[i];
	for (int i = index; i < rows; i++) buffer[i+1] = arr[i];
	delete[] arr;
	buffer[index] = new T[cols]{};
	rows++;
	return buffer;
}

template<typename T>T** erase_row(T** arr, int& rows, const int cols, const int index)
{
	T** buffer = new T* [--rows];
	for (int i = 0; i < index; i++) buffer[i] = arr[i];
	for (int i = index; i < rows; i++) buffer[i] = arr[i+1];
	delete[] arr[index];
	delete[] arr;
	return buffer;
}

template<typename T>void push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

template<typename T>void pop_col_back(T** arr, const int rows, int& cols)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols];
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
}

template<typename T>void push_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
		buffer[0] = 0;
		for (int j = 0; j < cols;j++) buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

template<typename T>void pop_col_front(T** arr, const int rows, int& cols)
{
	cols--;
	for (int i = 0; i < rows;i++)
	{
		T* buffer = new T[cols];
		for (int j = 0; j < cols;j++) buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
}

template<typename T>void insert_col(T** arr, const int rows, int& cols, const int index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1];
		for (int j = 0; j < index; j++) buffer[j] = arr[i][j];
		for (int j = index; j < cols; j++) buffer[j+1] = arr[i][j];
		buffer[index] = 0;
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

template<typename T>void erase_col(T** arr, const int rows, int& cols, const int index)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols];
		for (int j = 0; j < index;j++) buffer[j] = arr[i][j];
		for (int j = index; j < cols;j++) buffer[j] = arr[i][j+1];
		delete[] arr[i];
		arr[i] = buffer;
	}
}