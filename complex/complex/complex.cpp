// complex.cpp: ���������� ����� ����� ��� ����������� ����������.
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
	Complex() //����������� �� ���������
	{
		_R = 0;
		_Im = 0;
	}
	Complex(T R, T Im): _R(R), _Im(Im) //�����������, ����������� ���������
	{
	}
	Complex(const Complex &obj) //����������� �����������
	{
		_R = obj._R;
		_Im = obj._Im;
	}
	~Complex() //����������
	{

	}
	void set(T R, T Im)
	{
		_R = R;
		_Im = Im;
	}
	void print() //������� ����� ������������ �����
	{
		cout << _R << "+-" << _Im << "i" << endl;
	}
	/* ���������� ���������� */
	Complex operator+(Complex n2)
	{
		Complex temp;
		temp._R = _R + n2._R;
		temp._Im = _Im + n2._Im;
		return temp;
	}
	Complex operator-(Complex n2)
	{
		Complex temp;
		temp._R = _R - n2._R;
		temp._Im = _Im - n2._Im;
		return temp;
	}
	Complex operator*(Complex n2)
	{
		Complex temp;
		temp._R = _R*n2._R - _Im*n2._Im;
		temp._Im = _R*n2._Im + n2._Im*_R;
		return temp;
	}
	Complex operator=(Complex n2)
	{
		_R = n2._R;
		_Im = n2._Im;
		return *this;
	}
	bool operator==(Complex n2)
	{
		if (_R == n2._R && _Im == n2._Im) return 1;
		return 0;
	}
	bool operator!=(Complex n2)
	{
		if (_R != n2._R || _Im != n2._Im) return 1;
		return 0;
	}
	/* ����� - ���������� ���������� */

	//friend ostream& operator<<(ostream&, T Complex&);
	static int comp(Complex n1, Complex n2) //��������� ����������� ����� �� ������
	{
		double M1; //������ ������� �����
		double M2; //������ ������� �����
		M1 = sqrt(n1._R + n1._Im);
		M2 = sqrt(n2._R + n2._Im);
		if (M1 == M2) 
		{
			return 0;
		}
		else if (M1 > M2)
		{
			return 1;
		}
		else
		{
			return 2;
		}
		return 0;
	}
	
};
/*ostream& operator<<(ostream& a, T Complex *b)
{
	
} 
*/
int main()
{
	setlocale(LC_ALL, "rus");
	int min;
	Complex <int> num1(20,3);
	Complex <int> num2(15,2);
	Complex <int> num3;
	cout << "����� 1" << endl;
	num1.print();
	cout << "����� 2" << endl;
	num2.print();
	cout << "����� 2 � �������� ��������" << endl;
	num2.set(16, 2);
	num2.print();
	cout << "�������� �����" << endl;
	num3 = num1 + num2;
	num3.print();
	cout << "��������� �����" << endl;
	num3 = num1 * num2;
	num3.print();
	cout << "���������" << endl;
	num3 = num1 - num2;
	num3.print();
	if (num1 == num2) cout << "����� 1 ����� ����� 2" << endl;
	if (num1 != num2) cout << "����� 1 �� ����� ����� 2" << endl;
	//cout << num1;
	min = Complex<int>::comp(num1,num2);
	cout << "����� " << min << " ������ �� ������" << endl;
    return 0;
}
