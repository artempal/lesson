#pragma once
#include "animalsclass.h"
class WolfClass :
	public AnimalsClass
{
public:
	WolfClass(void);
	~WolfClass(void);
	void move();
	void eat();
};