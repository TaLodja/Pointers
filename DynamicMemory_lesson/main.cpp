#include "stdafx.h"
#include "constants.h"
#include "FillRand.h"
#include "Allocate_Clear.h"
#include "Allocate_Clear.cpp"
#include "Print.h"
#include "Print.cpp"
#include "push.h"
#include "push.cpp"
#include "pop.h"
#include "pop.cpp"
#include "pop_row.h"
#include "pop_row.cpp"
#include "push_row.h"
#include "push_row.cpp"
#include "pop_col.h"
#include "pop_col.cpp"
#include "push_col.h"
#include "push_col.cpp"
using std::cin;
using std::cout;
using std::endl;

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY_1
	int n;
	typedef double DataType;
	DataType value;
	int index;
	cout << "Введите размер исходного массива: "; cin >> n;
	DataType* arr = new DataType[n];
	cout << "Исходный массив: " << endl;
	FillRand(arr, n);
	Print(arr, n);

	/*cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;*/


	cout << "Введите значение, добавляемое в конце массива: "; cin >> value;
	arr = push_back(arr, n, value);
	//7) Значение добавлено, проверяем результат:
	Print(arr, n);

	cout << "Введите значение, добавляемое в начале массива: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);


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

	del;
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	int rows;
	int cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;
	cout << delimiter;

	typedef double DataType;

	DataType** arr = Allocate<DataType>(rows, cols);

	FillRand(arr, rows, cols);
	cout << "Заполнение сделано" << endl;
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