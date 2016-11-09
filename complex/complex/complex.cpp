// complex.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

template <typename T>
class Complex {
private:
	T _R;
	T _Im;
public:
	Complex(T R, T Im): _R(R), _Im(Im)
	{}
	void print()
	{
		cout << _R << "+-" << _Im << "i" << endl;
	}
	Complex operator+(Complex n2)
	{
		_R = _R+ n2._R;
		_Im = _Im + n2._Im;
		return *this;
	}
	Complex operator=(Complex n2)
	{
		_R = n2._R;
		_Im = n2._Im;
		return *this;
	}
	
};
int main()
{
	Complex <int> num1(12,15);
	Complex <int> num2(15,10);
	Complex <int> num3(0,0);
	num1.print();
	num2.print();
	num3 = num1 + num2;
	num3.print();
    return 0;
}

