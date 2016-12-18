// z1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

class BookCard {
	int id;
	string author;
	char *title;
public:
	BookCard(int size)
	{
		title = new char[size];
	}
	~BookCard()
	{
		delete title;
	}
};

class List {
	struct {
		List *head = NULL;
		List *end = NULL;
	};
	List *next;
	static int size;
public:
	List()
	{
		next = NULL;
		size = 0;
	}
	void add(BookCard &card)
	{

	}
};
int main()
{
    return 0;
}

