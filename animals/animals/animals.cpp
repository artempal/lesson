// animals.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h";
#include "AnimalsClass.h";
#include "SheepClass.h";
#include "WolfClass.h";
#include "BatmanClass.h";

using namespace std;

int main()
{
	setlocale(LC_ALL,"Russian");
	AnimalsClass obj1;
	obj1.move();
	SheepClass obj2;
	obj2.move();
	AnimalsClass* zoo[] = {new AnimalsClass, new MammalClass};
	for(int i = 0; i<2; i++)
	{
		zoo[i]->eat();
		zoo[i]->move();
	}
	BatmanClass batman;
	batman.eat();
	batman.move();
	return 0;
}

