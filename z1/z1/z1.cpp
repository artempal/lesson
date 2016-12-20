#include "stdafx.h";
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <conio.h>
#include <fstream>
using namespace std;

class BookCard
{
public:
	char *title;
	char *author;
	BookCard()
	{
		title = new char[255];
		author = new char[255];
	}
	~BookCard()
	{
		delete title;
		delete author;
	}
	void Input(BookCard&card);
	void BookCard::InputFromFile(BookCard &card, char * mytitle, char * myauthor);
	BookCard *Next;
};

class List
{
	BookCard *Head;

	int size;
public:
	List()
	{
		Head = NULL;
		size = 0;
	}
	~List()
	{
		while (Head != NULL)
		{
			BookCard *temp = Head->Next;
			delete Head;
			Head = temp;
		}
	}
	void Add(const BookCard&card);
	void Show();
	void Edit(const int N); 
	void Search(string key);
	void OutputToFile();
	int Cout()
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

void BookCard::InputFromFile(BookCard &card, char * mytitle, char * myauthor)
{
	strcpy_s(title , 255,  mytitle);
	strcpy_s(author, 255, myauthor);
}


void List::Add(const BookCard&card)
{
	size++; 
	BookCard *temp = new BookCard;
	temp->Next = Head;
	Head = temp;
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

void List::OutputToFile()
{
	ofstream fout("file.txt");
	if (fout)
	{
		BookCard *temp = Head; 

		while (temp != NULL) 
		{
			fout << temp->title << endl;
			fout << temp->author << endl;
			temp = temp->Next;
		}
		fout.close();
		cout << "Успешно" << endl;
	}
	else
		cout << "Не могу создать файл" << endl;
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

void List::Edit(int N) 
{
	BookCard *temp = Head; 
	int t;
	char *newtitle = new char[255];
	char *newauthor = new char[255];
	if ((Head != NULL) && ((N - 1)<size)) 
	{
		for (int i = 0; i < (N - 1); i++) temp = temp->Next;
		cout << temp->title << " ";
		cout << temp->author << endl;

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
class mainClass {
public:
	BookCard card;
	List list;
	void CreateList()
	{
		int N;
		cout << "Введите количество библиотечных карточек" << endl;
		cin >> N;
		cin.ignore();
		for (int i = 0; i < N; i++)
		{
			card.Input(card);
			list.Add(card);
		}
		cout << endl;
		list.Show();
	}
	void Open()
	{
		char* titel = new char[255];
		char* author = new char [255];
		ifstream fin("file.txt");
		while (!fin.eof())
		{
			fin >> titel;
			fin >> author;
			card.InputFromFile(card, titel, author);
			list.Add(card);
		}
		delete titel;
		delete author;
	}
	void Search()
	{
		string key;
		cout << "Введите название книги или автора\n";
		cin >> key;
		list.Search(key);
	}
	void Edit()
	{
		int N;
		cout << "Введите номер карты\n";
		cin >> N; 
		list.Edit(N);
		list.Show();
	}
	void Save()
	{
		list.OutputToFile();
		cout << "Библиотека открыта!" << endl;
		list.Show();
	}
	void Print()
	{
		list.Show();
	}
};
void main()
{
	setlocale(LC_ALL, "rus");
	mainClass mclass;
	int act;
	while (1)
	{
		cout << "Что сделаем?" << endl;
		cout << "------------" << endl;
		cout << "1.Создать новую библиотеку" << endl;
		cout << "2.Открыть библиотеку из файла" << endl;
		cout << "3.Сохранить библиотеку в файл" << endl;
		cout << "4.Найти в библиотеке по автору или названию" << endl;
		cout << "5.Изменить карточку" << endl;
		cout << "6.Вывести все книги библиотеки" << endl;
		cout << "0.Выход" << endl;
		cout << "------------" << endl << endl;
		cin >> act;
		switch (act)
		{
		case 0:
			return;
		case 1:
			mclass.CreateList();
			break;
		case 2:
			mclass.Open();
			break;
		case 3:
			mclass.Save();
			break;
		case 4:
			mclass.Search();
			break;
		case 5:
			mclass.Edit();
			break;
		case 6:
			mclass.Print();
			break;
		default:
			return;
		}
	}
	
}