// exam_vector.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
class Vector 
{
protected:
	int _x;
	int _y;
	int _z;
public: 
	Vector() {};
	Vector(int x, int y, int z) : _x(x), _y(y), _z(z) {}
	virtual void print()
	{
		cout << "x = " << _x << " y = " << _y << " z=" << _z << endl;
	}
	Vector operator+(Vector v2)
	{
		_x += v2._x;
		_y += v2._y;
		_z += v2._z;
		return *this;
	}
	Vector operator=(Vector v2)
	{
		_x = v2._x;
		_y = v2._y;
		_z = v2._z;
		return *this;
	}
	int operator*(Vector v2)
	{
		int proizved;
		proizved = _x * v2._x + _y * v2._y + _z * v2._z;
		return proizved;
	}
	friend ostream& operator<< (ostream& os, Vector& obj);
	friend istream& operator>>(istream& os, Vector& obj);
};
class perpendVector: public Vector
{
public:
	perpendVector() {}
	perpendVector(int y, int z) : Vector(0,y,z) {}
	void print()
	{
		cout << " y = " << _y << " z=" << _z << endl;
	}
	perpendVector operator+(perpendVector v2)
	{
		_y += v2._y;
		_z += v2._z;
		return *this;
	}
	perpendVector operator=(perpendVector v2)
	{
		_y = v2._y;
		_z = v2._z;
		return *this;
	}
	friend ostream& operator<< (ostream& os, perpendVector& obj);
	friend istream& operator >> (istream& os, perpendVector& obj);
};
istream& operator >> (istream& os, Vector& obj)
{
	os >> obj._x >> obj._y >> obj._z;
	return os;
}
ostream& operator<< (ostream& os, Vector& obj)
{
	os << "x = " << obj._x << " y = " << obj._y << " z=" << obj._z << endl;
	return os;
}
istream& operator >> (istream& os, perpendVector& obj)
{
	os >> obj._y >> obj._z;
	return os;
}
ostream& operator<< (ostream& os, perpendVector& obj)
{
	os << " y = " << obj._y << " z=" << obj._z << endl;
	return os;
}


int main()
{
	Vector v1(1, 2, 3);
	Vector v2(3, 4, 5);
	Vector v3;
	perpendVector v4(1, 2);
	perpendVector v5;
	cin >> v5;
	cout << v5;
	v4.print();
	v3 = v1 + v2;
	v3.print();
	cin >> v3;
	cout << v3;
	cout << v1 * v2 << endl;
    return 0;
}

