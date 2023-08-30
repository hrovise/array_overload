
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

public: ~PhoneBook(); //� �� �� ��������� � ������������, ��� �� ������ ������� �� ������� � ��"���� �����, �� ���� ��������� ��� �� ��������������?��� � ������ ����� � �������� del

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


public: void ConsoleOutput(int b);//������ ������� �������� �� Doesn't exist(�� ����� �����, ��� �������� ������ ����� ��� �������� ���� �� ������)

public: void ConsoleOutput();
public:void PhoneBook::del();
public:



public:	 char* lltoa(long long val, int base);//������� ������������ ���� ���� � ���     (������� �� ������������ �����, ��� � ���� ������� �� �� ��� �� ��������)
public:	 bool FileExists(char* filename);//�������� �� ���� ���� � ����� ������ �� �     (�� ������� ��� ������� �� ������������ �����)
public: char* file(char *fil);//������� ����� ��������� ����
public: void Show(PhoneBook **blist, int bcounter); //������ ��� ��������
public:	void Search(PhoneBook **blist, int bcounter);//����� �� Բ�
public:	void save(PhoneBook **blist, int i, char *filename);//������ ����
public:	void read(char *filename);//���� ����
		
public:PhoneBook& operator=( PhoneBook&obj);
};