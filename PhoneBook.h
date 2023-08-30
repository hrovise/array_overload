
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <limits>
#include <cstdio>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <conio.h>
#include <istream>




using namespace std;



class PhoneBook
{

	char name[15];
	char surname[20];
	char patronymic[20];
	long long homenumber;
	long long worknumber;
	long long mobilenumber;
	char moreinfo[1000];


public: PhoneBook();

		friend ostream& operator<< (ostream& out, const PhoneBook&book);
		friend	void operator>>(istream&is, PhoneBook&book);
public: PhoneBook(char *_name, char *_surname, char *_patronymic, long long  _homenumber, long long _mobilenumber, long long _worknumber, char *_moreinfo);

public: ~PhoneBook(); //я ще не розібрався з деструктором, але на скільки зрозумів він видаляє ті об"єкти класу, до яких звернення вже не відбуватиметься?Ото ж працює тільки в функціїї del

public: char *Getname();

public: char *Getsurname();

public: char *Getpatronymic();

public: char *Getmoreinfo();

public: long long Gethomenumber();

public: long long Getworknumber();

public: long long Getmobilenumber();

public: void Setname(char *_name);

public: void Setsurname(char *_surname);

public: void Setpatronymic(char *_patronymic);

public: void Setmoreinfo(char *_moreinfo);

public: void Sethomenumber(long long _homenumber);

public: void Setworknumber(long long _worknumber);


public: void Setmobilenumber(long long _mobilenumber);

		
public: void ConsoleInput();


public: void ConsoleOutput(int b);//показує занулені елементи як Doesn't exist(це можна міняти, для зручності зробив тільки щоб перевірка йшла по іменам)

public: void ConsoleOutput();
public:void PhoneBook::del();
public:



public:	 char* lltoa(long long val, int base);//функція перетворення лонг лонг в чар     (знайшов на англомовному форумі, сам я таку функцію ще не зміг би написати)
public:	 bool FileExists(char* filename);//перевірка чи існує файл з таким іменем чи ні     (цю функцію теж знайшов на англомовному форумі)
public: char* file(char *fil);//створює новий текстовий файл
public: void Show(PhoneBook **blist, int bcounter); //показує всіх абонентів
public:	void Search(PhoneBook **blist, int bcounter);//пошук за ФІО
public:	void save(PhoneBook **blist, int i, char *filename);//Зберігає файл
public:	void read(char *filename);//Читає файл
		
public:PhoneBook& operator=( PhoneBook&obj);
};