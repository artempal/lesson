#pragma once
#include "MammalClass.h"
#include "WingedClass.h"
class BatClass :
	public MammalClass, public WingedClass
{
public:
	BatClass();
	~BatClass();
	virtual void move();
	virtual void eat();
};

