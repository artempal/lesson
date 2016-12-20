#include "stdafx.h";
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <conio.h>
using namespace std;

class BookCard
{
public:
	unsigned int id;
	char *title;
	char *author;
	BookCard()
	{
		id = (unsigned int) this;
		title = new char[255];
		author = new char[255];
	}
	~BookCard()
	{
		delete title;
		delete author;
	}
	void Input(BookCard&card);//Функция ввода данных в класс
	BookCard *Next;//Адрес на следующий элемент
};

class List//Класс Список
{
	BookCard *Head;//Указатель на начало списка

	int size;
public:
	List()//Конструктор с инициализацией указателя пустым значением
	{
		Head = NULL;
		size = 0;
	}
	~List()//деструктор
	{
		while (Head != NULL)//Пока по адресу не пусто 
		{
			BookCard *temp = Head->Next;//Временная переменная для хранения адреса следующего элемента
			delete Head;//Освобождаем адрес обозначающий начало
			Head = temp;//Меняем адрес на следующий
		}
	}
	void Add(const BookCard&card);//Функция для добавления значений в список
	void Show();//Функция для отображения списка на экране
	void Pop(const int N); //функция извлечения элемента
	void Search(string key);
	int Cout()//функция-счетчик
	{
		return size;
	};
};

void BookCard::Input(BookCard&card)
{
	cout << "Название книги: "; cin.getline(title, 255);
	cout << "Автор книги: "; cin.getline(author, 255);
	cout << endl;
}


void List::Add(const BookCard&card)//Функция добавления элементов в список
{
	size++; // При каждом вызове функции добавления увеличивается счетчик элементов
	BookCard *temp = new BookCard;//При каждом вызове выделяется память
	temp->Next = Head;//Указываем, что адрес следующего элемента это начало списка
	Head = temp;//Указываем, что адрес следующего элемента это начало списка

				//Копирование содержимого параметра card в только что созданную переменную

	strcpy_s(temp->title, 255, card.title);
	strcpy_s(temp->author, 255, card.author);

	Head = temp; //Смена адреса начала списка
}

void List::Search(string key1)
{
	BookCard *temp = Head;
	while (temp != NULL)
	{
		if ((key1 == temp->author) || (key1 == temp->title))
		{
			cout << "Библиотечная карта найдена" <<endl;
			cout << temp->id << ": ";
			cout << temp->title << " ";
			cout << temp->author << endl;
			break;
		}
		if (temp->Next == NULL)
		{
			cout << "Библиотечная карта не найдена" << endl;
			break;
		}
		temp = temp->Next;
	}

}

void List::Show() 
{
	BookCard *temp = Head;
	while (temp != NULL)
	{
		cout << temp->title << " ";
		cout << temp->author << endl;
		temp = temp->Next; 
	}
	cout << endl;
}

void List::Pop(int N) //параметр номер изменяемого элемента
{
	BookCard *temp = Head; //Обращаемся к началу списка
	int t;
	char *newtitle = new char[255];
	char *newauthor = new char[255];
	if ((Head != NULL) && ((N - 1)<size)) //Делаем проверку на то что список не пуст и N не превышает число его элементов
	{
		for (int i = 0; i < (N - 1); i++) temp = temp->Next;//Меняем адрес N раз
		cout << temp->title << " ";
		cout << temp->author << endl;
		//Выводим N элемент списка на экран

		cout << "Изменить эту карту? \n"; cin >> t;
		if (t = 1)
		{
		cout << "Новое название: "; cin >> newtitle;
		cout << "Новый автор: "; cin >> newauthor;

		strcpy_s(temp->title , 255, newtitle);
		strcpy_s(temp->author , 255, newauthor);
		}
		
	}
	delete newauthor;
	delete newtitle;
	cout << endl;
}
void main()
{
	setlocale(LC_ALL, "rus");
	BookCard card;
	int N; 
	List list;
	cout << "Введите количество библиотечных карточек" << endl;
	cin >> N;
	string key;
	cin.ignore();//массив типа char всегда содержит символ NULL, который нужно проигнорировать
	for (int i = 0; i < N; i++)
	{
		card.Input(card);
		list.Add(card);
	}
	cout << endl;
	list.Show();

	cout << "Введите название книги или автора\n";
	cin >> key; //поиск по ключу
	list.Search(key);

	cout << "Введите номер карты\n";
	cin >> N; //поиск по номеру
	list.Pop(N);
	list.Show();
}