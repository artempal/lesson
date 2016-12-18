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
	T *stackPtr;                      // ��������� �� ����
	int size;                   // ������������ ���������� ��������� � �����
	int top;                          // ����� �������� �������� �����
public:
	Stack(int = 10);                  // �� ��������� ������ ����� ����� 10 ���������
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

	stackPtr[top++] = value; // �������� ������� � ����
}

// ������� �������� �������� �� �����
template <typename T>
inline T Stack<T>::pop()
{
	// ��������� ������ �����
	assert(top > 0); // ����� �������� �������� ������ ���� ������ 0

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
	T *oldPtr = new T[size];
	for (int ix = 0; ix < size; ix++)
		oldPtr[ix] = stackPtr[ix];
	delete stackPtr;
	stackPtr = new T[new_size];
	for (int ix = 0; ix < size; ix++)
		stackPtr[ix] = oldPtr[ix];
	size = new_size;
}

using namespace std;



int main()
{
	setlocale(LC_ALL, "Russian");
	Stack<char> stackSymbol(5);
	int ct = 0;
	char ch;

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

	stackSymbol.resizeStack(10);
	stackSymbol.printStack();
	ct = 0;
	while (ct++ < 6)
	{
		cin >> ch;
		stackSymbol.push(ch); // �������� �������� � ����
	}
	stackSymbol.printStack();


	return 0;
}
