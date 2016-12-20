

#include "stdafx.h"
#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;
class Card {
private:
	string _name;
	string _auth;
	unsigned int _id;
public:
	Card(string name, string auth) : _name(name), _auth(auth)
	{
		_id = (unsigned int) this;
	}
	void print()
	{
		cout << _id << " " << _name << " " << _auth << " " << endl;
	}
	string get_name()
	{
		return _name;
	}
	string get_auth()
	{
		return _auth;
	}
	unsigned int get_id()
	{
		return _id;
	}
};
list<Card>::iterator search(list<Card> L, string name)
{
	list <Card>::iterator i = L.begin();
	while (i != L.end())
	{
		if (i->get_name() == name) return i;
		*i++;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	int n;
	int value;
	cout << "�������� ������" << endl;
	vector <int> Myvector;
	cout << "������� ����� � ��� �����?" << endl;
	cin >> n;
	Myvector.reserve(n);
	for (int i = 0; i < n; i++)
	{
		cout << "������� ����� # " << i+1 << endl;
		cin >> value;
		Myvector.push_back(value);
	}
	cout << "------------------------" << endl;
	cout << "������ ��������� �������" << endl;
	Myvector.pop_back();
	cout << "------------------------" << endl;
	cout << "����������:" << endl;
	for (int i = 0; i < Myvector.size(); i++)
		cout << Myvector[i] << endl;


	cout << "------------------------" << endl;
	cout << "�������� ������� �������� � ������� � ������" << endl;

	Card book1("book1", "auth1");
	Card book2("book2", "auth2");
	Card book3("book3", "auth3");
	list <Card> L;

	L.push_back(book1);
	L.push_back(book2);
	L.push_back(book3);
	cout << "������� � ������� ���������" << endl;
	list <Card>::iterator i = L.begin();
	while (i != L.end())
	{
		i->print();
		i++;
	}
	cout << "������� id �����, ������� ����� �����" << endl;
	long int key;
	cin >> key;
	i = L.begin();
	while (i != L.end())
	{
		if (i->get_id() == key)
		{
			cout << "������ �������:" << endl;
			i->print();
			break;
		}
		i++;
	}
	return 0;
}