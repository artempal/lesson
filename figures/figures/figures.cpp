// figures.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Figura {
protected:
	int _col_storon;
	int* _dlina;
	static int _col_figur;
public:
	static int col_figur()
	{
		return _col_figur;
	}
	static void replace_col_figur(int col)
	{
		_col_figur = col;
	}
	Figura()
	{
		_col_figur++;
	}
	~Figura()
	{
		delete _dlina;
	}
	virtual int perimetr()
	{
		int sum = 0;
		for (int i = 0; i<_col_storon; i++)
		{
			sum += _dlina[i];
		}
		return sum;
	}
	virtual double ploshad()
	{
		int pl = _dlina[0];
		for (int i = 1; i<_col_storon-2; i++)
		{
			pl *= _dlina[i];
		}
		return pl;
	}
};
int Figura::_col_figur = 0;

class Rectangle : public Figura {
public:
	Rectangle(int a, int b)
	{
		_col_storon = 4;
		_dlina = new int[4];
		_dlina[0] = a;
		_dlina[1] = b;
		_dlina[2] = a;
		_dlina[3] = b;
	}
	double diag()
	{
		return sqrt(pow(_dlina[0], 2) + pow(_dlina[1], 2));
	}
};
class Treug : public Figura {
public:
	Treug() 
	{

	}
	Treug(int a, int b, int c)
	{
		_col_storon = 3;
		_dlina = new int[3];
		_dlina[0] = a;
		_dlina[1] = b;
		_dlina[2] = c;
	}
	double ploshad()
	{
		double p = (double)perimetr() / 2;
		double pl = sqrt(p*(p- _dlina[0])*(p- _dlina[1])*(p- _dlina[2]));
		return pl;
	}
	int perimetr()
	{
		int p;
		p = _dlina[0] + _dlina[1] + _dlina[2];
		return p;
	}
};
class ravnobedrTreug : public Treug {
public:
	ravnobedrTreug(int a, int b)
	{
		_col_storon = 3;
		_dlina = new int[3];
		_dlina[0] = a;
		_dlina[1] = b;
		_dlina[2] = a;
	}
	double h()
	{
		return sqrt(pow(_dlina[0], 2)-pow(_dlina[1], 2) / 4);
	}
};
int main()
{
	setlocale(LC_ALL, "rus");

	cout << "----------------" << endl;
	cout << "Создаем прямоугольник со сторонами 5 и 4" << endl;
	Rectangle *k = new Rectangle(5,4);

	cout << "Периметр прямоугольника = " << k->perimetr() << endl;
	cout << "Площадь прямоугольника = " << k->ploshad() << endl;
	cout << "Диагональ прямоугольника = " << k->diag() << endl;

	cout << "----------------" << endl;
	cout << "Создаем треугольник со строрнами 3, 4, 5" << endl;
	Treug *t = new Treug(3,4,5);

	cout << "Периметр треугольника = " << t->perimetr() << endl;
	cout << "Площадь треугольника = " << t->ploshad() << endl;

	cout << "----------------" << endl;
	cout << "Создаем равнобедренный треугольник со строрнами 4 и 5" << endl;
	ravnobedrTreug *rt = new ravnobedrTreug(4,5);

	cout << "Периметр равнобедренного треугольника = " << rt->perimetr() << endl;
	cout << "Площадь равнобедренного треугольника = " << rt->ploshad() << endl;
	cout << "Высота равнобедренного треугольника = " << rt->h() << endl;

	cout << "----------------" << endl;
	cout << "Количество созданных фигур = " << Figura::col_figur() << endl;
	cout << "----------------" << endl;
	int colvo;
	cout << "Введите новое количество фигур: " << endl;
	cin >> colvo;
	cout << "----------------" << endl;
	Figura::replace_col_figur(colvo);
	cout << "Количество созданных фигур после смены значения = " << Figura::col_figur() << endl;
	cout << "----------------" << endl;


	delete k;
	delete rt;

    return 0;
}

