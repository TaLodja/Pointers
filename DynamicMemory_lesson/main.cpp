#include <iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

int* push_back(int arr[], int& n, const int value);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер исходного массива: "; cin >> n;
	int* arr = new int[n];
	cout << "Исходный массив: ";
	FillRand(arr, n);
	Print(arr, n);

	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;

	arr = push_back(arr, n, value);

	//7) Значение добавлено, проверяем результат:
	Print(arr, n);

	delete[] arr;
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