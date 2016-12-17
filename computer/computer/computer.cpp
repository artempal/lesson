// computer.cpp: определяет точку входа для консольного приложения.
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
		cout << "Название компьютера: " << _name << endl;
		cout << "Оперативная память: " << _ddr << endl;
		cout << "Тип видеокрты: " << _video << endl;
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
		cout << "Количество ядер: " << _core << endl;
		cout << "Количество каналов связи: " << _channel << endl;
		cout << "Особенности: " << _info << endl;
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
	void info()
	{
		cout << "Название компьютера: " << _name << endl;
		cout << "Оперативная память: " << _ddr << endl;
		cout << "Тип видеокрты: " << _video << endl;
		cout << "Звук: "; _sound ? cout << "да" : cout << "нет"; cout << endl;
		cout << "Звуковая карта: "; _sound_card ? cout << "да" : cout << "нет"; cout << endl;
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
	void info()
	{
		cout << "Название компьютера: " << _name << endl;
		cout << "Оперативная память: " << _ddr << "Гб" << endl;
		cout << "Тип видеокрты: " << _video << endl;
		cout << "Дисплей: " << _size << "`" << endl;
		cout << "Емкость аккамулятора:" << _battery << " мАч" << endl;
		cout << "Вес:" << _weight << " кг" << endl;
		
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
		cout << "Название компьютера: " << _name << endl;
		cout << "Оперативная память: " << _ddr << "Гб" << endl;
		cout << "Тип видеокрты: " << _video << endl;
		cout << "Количество ядер: " << _core << endl;
		cout << "Количество каналов связи: " << _channel << endl;
		cout << "Особенности: " << _info << endl;
		cout << "Подключен ли интернет: "; _net ? cout << "да" : cout << "нет"; cout << endl;
		cout << "Операционная система: " << _os << endl;

	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	cout << "---------------------" << endl;
	cout << "Переносной сервер" << endl;
	Mobile_server ms = Mobile_server("Artem_server", 16, "NVIDIA GeForce GTX 950", 14, 10500, 5.5, 4, 3, "Установлен Nginx", 1, "Linux");
	ms.info();
	cout << "---------------------" << endl;
	cout << "Ноутбук" << endl;
	Laptop lt = Laptop("Artem_Laptop", 2, "NVIDIA GeForce GTX 1050 Ti", 15, 6500, 2.8);
	lt.info();
	cout << "---------------------" << endl;
	cout << "Компьютер" << endl;
	Computer cp = Computer("My computer", 8, "AMD Radeon RX 470");
	cp.info();
	cout << "---------------------" << endl;
	return 0;
}
