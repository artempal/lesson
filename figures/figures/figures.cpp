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
	
public:
	static int _col_figur;
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
		for (int i = 0; i<_col_storon; i++)
		{
			_dlina[i] = _dlina[i];
		}
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
		for (int i = 1; i<_col_storon; i++)
		{
			pl *= _dlina[i];
		}
		return pl;
	}
};

class Kvadrat : public Figura {
public:
	Kvadrat()
	{
		_col_storon = 4;
		_dlina = new int[4];
		for (int i = 0; i<4; i++)
		{
			_dlina[i] = 2;
		}
	}
};
class Treug : public Figura {
protected:
	int _h;
public:
	Treug();
	Treug(int h)
	{
		_col_storon = 3;
		_dlina = new int[3];
		_h = h;
		for (int i = 0; i<3; i++)
		{
			_dlina[i] = 2;
		}
	}
	double ploshad()
	{
		double pl;
		pl = (1 / 2)*_dlina[1] * _h;
		return pl;
	}
};
class ravnobedrTreug : public Treug {
public:
	ravnobedrTreug(int h)
	{
		_col_storon = 2;
		_dlina = new int[2];
		_h = h;
		for (int i = 0; i<2; i++)
		{
			_dlina[i] = 2;
		}
	}
};
int main()
{
	Figura *f = new Figura;
	Kvadrat *k = new Kvadrat();
	int perim = k->perimetr();
	double pl = k->ploshad();
	cout << "Perimetr = " << perim << endl;
	cout << "Ploshad = " << pl << endl;


	Figura *ptr;
	int h = 5;
	Treug *t = new Treug(h);

	ptr = t;
	cout << "Ploshad virtual = " << ptr->ploshad() << endl;
	cout << "Col-vo figur: =" << Figura::col_figur() << endl;
	int col = 125;
	Figura::replace_col_figur(col);
	cout << "Col-vo figur: =" << Figura::col_figur() << endl;
    return 0;
}

