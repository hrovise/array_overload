#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <ctime>

using namespace std;

class Auto
{
public:
	char *model;
	int year_i; //year of issue
	char *colour;
	char *s_number;
	char buffer[80];


public: Auto();
public:~Auto();
public: void Settime_r();
public: void Setmodel(char *_model);

public:void Setyear_i(int _year_i);

public:  void Setcolour(char *_colour);
public: void Sets_number(char *_s_number);

public:char* Gettime_r();
public:char *Getmodel();
public:int Getyear_i();
public:char *Getcolour();
public:char *Gets_number();

public:Auto& operator=( Auto &obj);

	   friend ostream& operator<<(ostream&out, const Auto &obj);
	   friend  void operator >>(istream&is, Auto &obj);
};