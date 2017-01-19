// exam_date.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>


using namespace std;

class Date 
{
private:
	int D1[3]; //формат даты ГГГГ-ММ-ДД
	int D2[3];
	int days; //сколько дней между датами
public:
	void dist()
	{

	}
	void arr_to_day(int *date)
	{
		unsigned int days = date[0] * (bissextile(date[0])?366:365) + date[1] * days_in_month(date[1], date[0]) + date[2];
	}
	int bissextile(int y) //проверка високосного года
	{
		return ((y % 100 != 0) && (y % 4 == 0)) || (y % 400 == 0);
	}
	int days_in_month(int m, int y) //сколько дней в месяце в этом году?
	{
		int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		if (bissextile(y))days[1] = 29;
		return days[m-1];
	}
};
int main()
{
    return 0;
}

