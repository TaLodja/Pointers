#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	cout << "Hello Pointers" << endl;

	int a = 2;
	int* pa = &a;
	cout << a << endl;	//вывод переменной 'a' на экран
	cout << &a << endl;	//взятие адреса переменной 'a' прямо при выводе
	cout << pa << endl;	//вывод адреча переменной 'a', хранящегося в указателе 'pa'
	cout << *pa << endl; //
}