#pragma once
#include "animalsclass.h"
class MammalClass :
	public AnimalsClass
{
public:
	MammalClass(void);
	~MammalClass(void);
	virtual void move();
	virtual void eat();
};
