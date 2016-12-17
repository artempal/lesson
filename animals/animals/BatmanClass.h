#pragma once
#include "HumanClass.h"
#include "BatClass.h"
class BatmanClass :
	public HumanClass, public BatClass
{
public:
	BatmanClass();
	~BatmanClass();
	void move();
	void eat();
};

