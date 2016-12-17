// computer.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Computer {
protected:
	string _name;
	int _ddr;
	string _video;
public:
	Computer(string name, int ddr, string video) :
		_name(name), _ddr(ddr), _video(video)
	{
	}
	virtual void info()
	{
		cout << "�������� ����������: " << _name << endl;
		cout << "����������� ������: " << _ddr << endl;
		cout << "��� ���������: " << _video << endl;
	}
};

class Server {
protected:
	int _core;
	int _channel;
	string _info;
public:
	Server(int core, int channel, string info) : _core(core), _channel(channel), _info(info)
	{
	}
	virtual void info()
	{
		cout << "���������� ����: " << _core << endl;
		cout << "���������� ������� �����: " << _channel << endl;
		cout << "�����������: " << _info << endl;
	}
};
class PC: public Computer {
protected:
	bool _sound;
	bool _sound_card;
public:
	PC(string name, int ddr, string video, bool sound, bool sound_card) : Computer(name, ddr, video), _sound(sound), _sound_card(sound_card)
	{
	}
};
class Laptop : public Computer {
protected:
	int _size;
	int _battery;
	double _weight;
public:
	Laptop(string name, int ddr, string video, int size, int battery, double weight) :
		Computer(name, ddr, video), _size(size), _battery(battery), _weight(weight)
	{
	}

};

class Mobile_server : public Server, public Laptop {
protected:
	bool _net;
	string _os;
public:
	Mobile_server(string name, int ddr, string video, int size, int battery, double weight, int core, int channel, string info, bool net, string os) :
		Laptop(name, ddr, video, size, battery, weight), Server(core, net, info), _net(net), _os(os)
	{
	}
	void info()
	{
		cout << "�������� ����������: " << _name << endl;
		cout << "����������� ������: " << _ddr << "��" << endl;
		cout << "��� ���������: " << _video << endl;
		cout << "���������� ����: " << _core << endl;
		cout << "���������� ������� �����: " << _channel << endl;
		cout << "�����������: " << _info << endl;
		cout << "��������� �� ��������: "; _net ? cout << "��" : cout << "���"; cout << endl;
		cout << "������������ �������: " << _os << endl;

	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	Mobile_server ms = Mobile_server("Artem_server", 16, "Nvidea", 14, 10500, 5.5, 4, 3, "���������� Nginx", 1, "Linux");
	ms.info();
	return 0;
}
