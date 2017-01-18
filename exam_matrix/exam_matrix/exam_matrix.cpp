// exam_matrix.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Matrix {
	int i1, j1, i2, j2 ,i3,j3;
	int **mtr1;
	int **mtr2;
	int **mtr3;
public:
	~Matrix()
	{
		for (int i = 0; i < i1; i++)
			delete[] mtr1[i];
		delete[] mtr1;
		for (int i = 0; i < i2; i++)
			delete[] mtr2[i];
		delete[] mtr2;
		for (int i = 0; i < i3; i++)
			delete[] mtr3[i];
		delete[] mtr3;
	}
	void get_mtr()
	{
		cout << "¬ведите размерность матрицы 1" << endl;
		cin >> i1 >> j1;
		cout << "¬ведите размерность матрицы 2" << endl;
		cin >> i2 >> j2;
		mtr1 = new int*[i1];
		mtr2 = new int*[i2];
		int i = 0, j = 0;
		for (i = 0; i < i1; i++)
			mtr1[i] = new int[j1];
		for (i = 0; i < i2; i++)
			mtr2[i] = new int[j2];
		for (i = 0; i < i1; i++)
			for (j = 0; j < j1; j++)
			{
				cout << "mtr1[" << i + 1 << "][" << j + 1 << "] =";
				cin >> mtr1[i][j];
				cout << endl;
			}	
		for (i = 0; i < i2; i++)
			for (j = 0; j < j2; j++)
			{
				cout << "mtr2[" << i + 1 << "][" << j + 1 << "] =";
				cin >> mtr2[i][j];
				cout << endl;
			}
	}
	void print_mtr(int number)
	{
		int ii, jj, **mtr;
		switch (number)
		{
		case 1:
			ii = i1;
			jj = j1;
			mtr = mtr1;
			break;
		case 2:
			ii = i2;
			jj = j2;
			mtr = mtr2;
			break;
		case 3:
			ii = i3;
			jj = j3;
			mtr = mtr3;
			break;
		default:
			ii = i1;
			jj = j1;
			mtr = mtr1;
		}
		int i = 0, j = 0;
		for (i = 0; i < ii; i++)
		{
			for (j = 0; j < jj; j++)
			{
				cout  << "|" << mtr[i][j] << "|";
			}
			cout << endl;
		}	
	}
	int multiplication()
	{
		if (j1 != i2) return -1;
		i3 = i1;
		j3 = j2;
		mtr3 = new int*[i3];
		for (int i = 0; i < i3; i++)
			mtr3[i] = new int[j3];

		for (int i = 0; i < i3; i++)
			for (int j = 0; j < j3; j++)
			{
				mtr3[i][j] = 0;
				for (int k = 0; k<j1; k++)
					mtr3[i][j] += (mtr1[i][k])*(mtr2[k][j]);
			}	
	}
	void transposition(int number)
	{
		int ii, jj, **mtr;
		switch (number)
		{
		case 1:
			ii = i1;
			jj = j1;
			mtr = mtr1;
			break;
		case 2:
			ii = i2;
			jj = j2;
			mtr = mtr2;
			break;
		case 3:
			ii = i3;
			jj = j3;
			mtr = mtr3;
			break;
		default:
			ii = i1;
			jj = j1;
			mtr = mtr1;
		}
		for (int i = 0; i < i3; i++)
			delete[] mtr3[i];
		delete[] mtr3;
		i3 = jj;
		j3 = ii;
		mtr3 = new int*[i3];
		for (int i = 0; i < i3; i++)
			mtr3[i] = new int[j3];

		for (int i = 0; i < i3; i++)
			for (int j = 0; j < j3; j++)
				mtr3[i][j] = mtr[j][i];
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	Matrix obj;
	obj.get_mtr();
	obj.multiplication();
	obj.print_mtr(3);
	obj.print_mtr(2);
	obj.transposition(2);
	obj.print_mtr(3);
    return 0;
}

