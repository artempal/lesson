// steck.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"


#include <cassert> // ��� assert
#include <iostream>

#include <iomanip> // ��� setw

template <typename T>
class Stack
{
private:
	const int std_size = 5; //����������� ������ �����
	T *stackPtr;                      // ��������� �� ����
	int size;                   // ������������ ���������� ��������� � �����
	int top;                          // ����� �������� �������� �����
	int empty = std_size; //���������� ������ ���������
public:
	Stack(int = std_size);                  // �� ��������� ������ ����� ����� 10 ���������
	Stack(const Stack<T> &);          // ����������� �����������
	~Stack();                         // ����������

	inline void push(const T &);     // ��������� ������� � ������� �����
	inline T pop();                   // ������� ������� �� ������� ����� � ������� ���
	inline void printStack();         // ����� ����� �� �����
	inline const T &Peek(int) const; // n-� ������� �� ������� �����
	inline int getStackSize() const;  // �������� ������ �����
	inline T *getPtr() const;         // �������� ��������� �� ����
	inline int getTop() const;        // �������� ����� �������� �������� � �����
	inline void resizeStack(int size);
	inline void debugging();
};

// ���������� ������� ������� ������ STack

// ����������� �����


template <typename T>
Stack<T>::Stack(int maxSize) :
	size(maxSize) // ������������� ���������
{
	stackPtr = new T[size]; // �������� ������ ��� ����
	top = 0; // �������������� ������� ������� �����;
}

// ����������� �����������
template <typename T>
Stack<T>::Stack(const Stack<T> & otherStack) :
	size(otherStack.getStackSize()) // ������������� ���������
{
	stackPtr = new T[size]; // �������� ������ ��� ����� ����
	top = otherStack.getTop();

	for (int ix = 0; ix < top; ix++)
		stackPtr[ix] = otherStack.getPtr()[ix];
}

// ������� ����������� �����
template <typename T>
Stack<T>::~Stack()
{
	delete[] stackPtr; // ������� ����
}

// ������� ���������� �������� � ����
template <typename T>
inline void Stack<T>::push(const T &value)
{
	// ��������� ������ �����
	assert(top < size); // ����� �������� �������� ������ ���� ������ ������� �����
	empty--;
	if ((size - empty) == size)
		resizeStack((int)size*1.5);
	stackPtr[top++] = value; // �������� ������� � ����
}

// ������� �������� �������� �� �����
template <typename T>
inline T Stack<T>::pop()
{
	// ��������� ������ �����
	assert(top > 0); // ����� �������� �������� ������ ���� ������ 0
	empty++;
	if((size/empty)<1.5)
		resizeStack((int)size/1.5);
	return stackPtr[--top]; // ������� ������� �� �����
}

// ������� ���������� n-� ������� �� ������� �����
template <class T>
inline const T &Stack<T>::Peek(int nom) const
{
	//
	assert(nom <= top);

	return stackPtr[top - nom]; // ������� n-� ������� �����
}

// ����� ����� �� �����
template <typename T>
inline void Stack<T>::printStack()
{
	for (int ix = top - 1; ix >= 0; ix--)
		cout << "|" << setw(4) << stackPtr[ix] << endl;
}

// ������� ������ �����
template <typename T>
inline int Stack<T>::getStackSize() const
{
	return size;
}

// ������� ��������� �� ���� (��� ������������ �����������)
template <typename T>
inline T *Stack<T>::getPtr() const
{
	return stackPtr;
}

// ������� ������ �����
template <typename T>
inline int Stack<T>::getTop() const
{
	return top;
}

//��������� �������� �����
template <typename T>
inline void Stack<T>::resizeStack(int new_size)
{
	int delta;
	delta = new_size - size;
	empty += delta;
	if (delta > 0) 
	{
		T *oldPtr = new T[size];
		for (int ix = 0; ix < size; ix++)
			oldPtr[ix] = stackPtr[ix];
		delete stackPtr;
		stackPtr = new T[new_size];
		for (int ix = 0; ix < size; ix++)
			stackPtr[ix] = oldPtr[ix];
	}
	else
	{
		T *oldPtr = new T[size];
		for (int ix = 0; ix < size; ix++)
			oldPtr[ix] = stackPtr[ix];
		delete stackPtr;
		stackPtr = new T[new_size];
		for (int ix = 0; ix < new_size; ix++)
			stackPtr[ix] = oldPtr[ix];
	}
	size = new_size;
}
template <typename T>
inline void Stack<T>::debugging()
{
	cout << "-------------------------" << endl << endl;
	cout << "������ ����� " << size << endl;
	cout << "���������� ��������� " << size - empty << endl;
	cout << "-------------------------" << endl << endl;
}
using namespace std;



int main()
{
	setlocale(LC_ALL, "Russian");
	Stack<char> stackSymbol(5);
	int ct = 0;
	char ch;

	cout << "������� 5 ������ ��������" << endl;

	while (ct++ < 5)
	{
		cin >> ch;
		stackSymbol.push(ch); // �������� �������� � ����
	}

	cout << endl;

	stackSymbol.printStack(); // ������ �����

	cout << "\n\n������ ������� �� �����\n";
	stackSymbol.pop();

	stackSymbol.printStack(); // ������ �����

	Stack<char> newStack(stackSymbol);

	cout << "\n\n�������� ����������� �����������!\n";
	newStack.printStack();

	cout << "������ � ������� �������: " << newStack.Peek(2) << endl;
	stackSymbol.printStack();

	//stackSymbol.resizeStack(10);
	int colvo;
	cout << "������� ��� ��������� ������?" << endl;
	cin >> colvo;
	
	ct = 0;
	while (ct++ < colvo)
	{
		cin >> ch;
		stackSymbol.push(ch); // �������� �������� � ����
		stackSymbol.debugging();
	}
	stackSymbol.printStack();

	cout << "������� ��������� ������?" << endl;
	cin >> colvo;

	ct = 0;
	while (ct++ < colvo)
	{
		stackSymbol.pop(); 
	}
	stackSymbol.printStack();
	stackSymbol.debugging();

	return 0;
}
