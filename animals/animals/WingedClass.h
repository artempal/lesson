#pragma once
#include "AnimalsClass.h"
class WingedClass :
	public AnimalsClass
{
public:
	WingedClass();
	~WingedClass();
	virtual void move();
	virtual void eat();
};

