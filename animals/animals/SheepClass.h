#pragma once
#include "animalsclass.h"
class SheepClass :
	public AnimalsClass
{
public:
	SheepClass(void);
	~SheepClass(void);
	void move();
	void eat();
};

