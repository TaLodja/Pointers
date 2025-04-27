#include <iostream>
using namespace std;

void FillRand(int arr[], const int n, int minRand = 50, int maxRand = 200);
void Print(int arr[], const int n);
int Even_Odd_Numbers(int arr[], const int n, int d);
void Fill_Even_Odd(int arr[], const int n, int even[], int odd[]);
void DelArr(int arr[]);


void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int arr[n];
	FillRand(arr, n);
	cout << "Исходный массиы: ";
	Print(arr, n);
	int N_ev, N_odd;
	N_ev = Even_Odd_Numbers(arr, n, 2);
	N_odd = Even_Odd_Numbers(arr, n, 1);
	int* even = new int[N_ev];
	int* odd = new int[N_odd];
	Fill_Even_Odd(arr, n, even, odd);
	cout << "Массив четных чичел: " << endl;
	Print(even, N_ev);
	cout << "Массив нечетных чисел: " << endl;
	Print(odd, N_odd);
	DelArr(even);
	DelArr(odd);
}

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
	}
}
void Fill_Even_Odd(int arr[], const int n, int even[], int odd[])
{
	int even_i = 0;
	int odd_i = 0;
	for (int i = 0;i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			even[even_i] = arr[i];
			even_i++;
		}
		else
		{
			odd[odd_i] = arr[i];
			odd_i++;
		}
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
int Even_Odd_Numbers(int arr[], const int n, int d) //d=2 - четные числаб d=(не 2) - нечетные числа
{
	int even = 0;
	int odd = 0;
	for (int i = 0; i < n; i++)
	{
		(arr[i] % 2 == 0) ? (even++) : (odd++);
	}
	return (d == 2) ? even : odd;
}
void DelArr(int arr[])
{
	delete[] arr;
}