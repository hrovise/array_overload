#ifndef ARRAY_H //if not def чи не визначено ім"я ARRAY_H, якщо ні, то починається тіло
#define ARRAY_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#pragma once




using namespace std;


template <typename D, typename S=int>
class Array
{

	D *data;
	S length;
public:Array();//:data(nullptr), length(S()) //стартова ініціалізація через двокрапку
			   //{}
	   Array(S _length);

	  Array(const D&_data, S size);
	  
	   Array( D*_data, S _length);
	   Array(const Array<D, S>&klas);
	   
	   void Output();

	   S Getlength();
	   Array<D, S>& operator= (const Array<D, S> &arrayobj);//& після типу означає, що це посилання(тобто ссилка)

	   ~Array();
public:const D GetData();
public:   S Size();
public:void selectSort(Array<D, S>&obj);
D min(Array<D, S>&obj);
D max(Array<D, S>&obj);
D average(Array<D, S>&obj);
public:  D &operator[](S idx);
		//public: void push_back(const D& element);
public:  Array<D, S>& push_back(const D& element);
public: Array<D, S>& pop_back();
public: Array<D, S>&push_front(const D&element);
public: Array<D, S>& pop_front();
public: Array<D, S>& resize(S& size);
public:Array<D, S>&insert(const D&element, S idx);
public:D&back();
public:D&front();
public:void clear();
public:Array<D,S>operator+(const Array<D, S> & obj)const;
public:bool operator==(const Array<D, S>&obj)const;
public: bool operator!=(const Array<D, S>&obj)const;
	  /* friend void operator<< (ostream& out, const Array<D,S>&obj);*/

};
#include "Array.cpp"

#endif
