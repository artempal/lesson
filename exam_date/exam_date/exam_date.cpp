// exam_date.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>


using namespace std;

class Date 
{
private:
	int D1[3]; //формат даты ГГГГ-ММ-ДД
	int D2[3];
public:
	Date(int y1, int m1, int d1, int y2, int m2, int d2)
	{
		D1[0] = y1;
		D1[1] = m1;
		D1[2] = d1;
		D2[0] = y2;
		D2[1] = m2;
		D2[2] = d2;
	}
	int dist() //разница между двумя датами
	{
		return arr_to_day(D2) - arr_to_day(D1);
	}
	void minus(int day) //вычитание дней из даты
	{
		int days = arr_to_day(D1) - day;
		int *D;
		D = days_to_arr(days);
		cout << D[0] << "." << D[1] << "." << D[2] << endl;
	}
	int* days_to_arr(int days) //перевод дней в массив
	{
		int D[3];
		int y = 1;
		int m = 1;
		int d = 1;
		while ((bissextile(y - 1) ? 366 : 365) <= days)
		{
			days -= bissextile(y) ? 366 : 365;
			y++;
		}
		while (days_in_month(m - 1, y) <= days) 
		{
			days -= days_in_month(m, y);
			m++;
		}
		d += days;
		D[0] = y;
		D[1] = m;
		D[2] = d - 1; //вычтем текущий день
		return D;
	}
	int arr_to_day(int *date) //перевод массива в дни
	{
		int sum_day_y = 0;
		int sum_day_m = 0;
		for (int i = 1; i < date[0]; i++)
			sum_day_y += bissextile(i) ? 366 : 365;
		for (int i = 1; i < date[1]; i++)
			sum_day_m += days_in_month(i, date[0]);
		int days = sum_day_y + sum_day_m + date[2];
		 return days;
	}
	int bissextile(int y) //проверка високосного года
	{
		return ((y % 100 != 0) && (y % 4 == 0)) || (y % 400 == 0);
	}
	int days_in_month(int m, int y) //сколько дней в месяце в этом году?
	{
		int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		if (bissextile(y))days[1] = 29;
		return days[m - 1];
	}
};
int main()
{
	Date date(2017, 1, 19, 2018, 10, 19);
	cout << date.dist() << endl;
	date.minus(5000);
    return 0;
}

