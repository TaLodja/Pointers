#include <iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

int* push_back(int arr[], int& n, const int value);
int* push_front(int arr[], int& n, const int value);
int* insert(int arr[], int& n, const int value, const int index);
int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, const int index);

void main()
{
	setlocale(LC_ALL, "");
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
	cout << "Введите значение, добавляемое по указанному индексу: "; cin >> value;
	cout << "Введите индекс: "; cin >> index;
	arr = insert(arr, n, value, index);
	Print(arr, n);

	cout << "Массив после удаления последнего элемента: " << endl;
	arr = pop_back(arr, n);
	Print(arr, n);

	cout << "Массив после удаления нулевого элемента: " << endl;
	arr = pop_front(arr, n);
	Print(arr, n);

	index--;
	cout << "Массив после удаления элемента по индексу " << index << ": " << endl;
	arr = erase(arr, n, index);
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
int* push_front(int arr[], int& n, const int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}

int* insert(int arr[], int& n, const int value, const int index)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		(i < index ? buffer[i] : buffer[i + 1]) = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}

int* pop_back(int arr[], int& n)
{
	n--;
	int* buffer = new int[n];
	for (int i = 0;i < n;i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	return arr;
}

int* pop_front(int arr[], int& n)
{
	n--;
	int* buffer = new int[n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	return arr;
}

int* erase(int arr[], int& n, const int index)
{
	n--;
	int* buffer = new int[n];
	for (int i = 0;i < n;i++)
	{
		buffer[i] = (i < index ? arr[i] : arr[i + 1]);
	}
	delete[] arr;
	arr = buffer;
	return arr;
}