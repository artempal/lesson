// app1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

template <typename T>
void my_swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}
template <typename T>
class Templ {
private:
	T pnop;
};
int main()
{
	int a = 2;
	int b = 3;
	my_swap(a, b);
	my_swap<int>(a, b);
	cout << a << b << endl;
	Templ<int> obj;
    return 0;
}