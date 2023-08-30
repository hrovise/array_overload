#ifndef ARRAY_CPP
#define ARRAY_CPP
#include "Array.h"
#pragma once

template <typename D, typename S>
Array<D, S>::Array() :data(nullptr), length(S()) {}

template <typename D, typename S>
Array<D, S>::Array(S _length)
{
	length = _length;
	data = new D[length]();
}

template <typename D, typename S>
Array<D, S>::Array(const D&_data, S size)
{
	length = size;
	delete[]data;
	data = new D[length];
	
		*data =_data;
	

}

template <typename D, typename S>
Array<D, S>::Array( D*_data, S _length)//я забрав константу, щоби можна було скористатись функцією для класу БУк і КАР, звісно, так робити неможна, але щоб не міняти всі константи(бо там випливає купа інших змін), я для зручності забрав тут конст
{
	length = _length; data = new D[length];
	for (S i = S(); i < length; i++)
	{
		data[i] = _data[i];
		
	}
	
}
template <typename D, typename S>
S Array<D, S>:: Getlength()
{
	return length;
}
template <typename D, typename S>
void Array<D, S>::Output()
{
	for (S i = S(); i < length; i++)
	{
		cout << data[i];
		cout <<"\t";
	}
}
template <typename D, typename S>
Array<D, S>& Array<D, S>:: operator= (const Array<D, S> &arrayobj)//& після типу означає, що це посилання(тобто ссилка) і це є конструктор копіювання
{
	if (this != &arrayobj)//адреса об"єкту
	{
		delete[]data;
		this->length = arrayobj.length;// можна без this. Тому що він використовуюється по замовчуванню
		
		data = new D[length];
		for (S i = S(); i < length; i++)
		{
			data[i] = arrayobj.data[i];

		}

	}
	return *this;

}
template <typename D, typename S>
Array<D, S>::Array(const Array<D,S>&klas)
{
	*this = klas;
}
template <typename D, typename S>
Array<D, S>::~Array()
{
	delete[]data;
}
template <typename D, typename S>
S Array<D, S> ::Size()
{
	return length;
}
template <typename D, typename S>
void Array<D, S>::selectSort(Array<D,S>&obj)
{
	int i, j;   // i, j счетчики циклов
	int buf;    //buf буферная переменная
	int min;
	for (i = 0; i < obj.length ; i++) {

		//поиск минимального элемента в части массива от а[1] до a[SIZE]} 
		min = i;
		for (j = i + 1; j < obj.length; j++)
		{
			if (obj.data[j] < obj.data[min])
				min = j;
		}
		//поменяем местами a [min] и a[i]
		buf = obj.data[i];
		obj.data[i] = obj.data[min];
		obj.data[min] = buf;
	}
	/*for (i = 0; i<obj.length; i++)
		cout << obj.data[i] << "\t";*/


	/*long i, j;
	D tmp;
	bool noswap;
	for (i = l-1; i >=0; i--)
	{
	
	
		for (j = 0; j < i; j++)
		{
			if (obj[j] > obj[j+1])
			{
				tmp = obj[j ];
					obj[j ] = obj[j+1];
				obj[j+1]=tmp;
				
				cout << obj[i] << "\t";
			}
			cout << obj[i] << "\t";
		}
		
	
	}*/
}
template <typename D, typename S>
D Array<D, S> :: min(Array<D, S>&obj)
{
	selectSort(obj);
	return obj[0];
}
template <typename D, typename S>
D Array<D, S> ::max(Array<D, S>&obj)
{
	selectSort(obj);
	return obj[obj.length-1];
}
template <typename D, typename S>
D Array<D, S> ::average(Array<D, S>&obj)
{
	D sum = 0;
	/*selectSort(obj);*/
	for (int i = 0; i < obj.length; i++)
	{
		sum += obj.data[i];

	}
	
	return sum/obj.length;
}
template <typename D, typename S>
 D& Array<D, S>::operator[](S idx)
{
	return  data[idx];
}
//template <typename D, typename S>
//void Array<D, S>::push_back(const D& element)
//{
//	D *s;
//
//	s = new D[length + 1];
//		for (S i = S(); i < length; i++)
//		{
//			s[i] = data[i];
//		}
//	s[length] = element;
//	length++;
//	delete[]data;
//	data = s;
//	
//
//	 
//}
template <typename D, typename S>
Array<D, S>& Array<D, S>::push_back(const D& element)
{
	D *s;

	s = new D[length + 1];
	for (S i = S(); i < length; i++)
	{
		s[i] = data[i];
	}
	s[length] = element;
	length++;
	delete[]data;
	data = s;
	
return *this;
}
template <typename D, typename S>
Array<D, S>& Array<D, S>::pop_back()
{
	if (length != 0)
	{
		D *s;

		s = new D[length - 1];
		for (S i = S(); i < length - 1; i++)
		{
			s[i] = data[i];
		}


		if (length == 1)
		{
			delete[]data;
			length--;
		}
		else
		{
			delete[]data;
			length--;
			data = s;
			return *this;
		}
	}
}
template <typename D,typename S>
Array<D, S>& Array<D, S>::push_front(const D&element)
{
	D *s;
	s = new D[length+1];
	s[0] = element;
	for (int k=1, i = 0; i < length;k++, i++)
	{
		s[k] = data[i];
		/*cout << "data [" << i << "]" <<data[i]<< "/t";*/
	}
	
	delete[]data;
	length++;
	data = s;
	return *this;
}
template <typename D, typename S>
Array<D, S>& Array<D, S>::pop_front()

{
	if (length != 0)
	{
		D *s;

		s = new D[length - 1];
		for (S i = 1, k = 0; i < length; k++, i++)
		{
			s[k] = data[i];

		}

		if (length == 1)
		{
			delete[]data;
			length--;
		}
		else
		{
			delete[]data;
			length--;
			data = s;
			return *this;
		}
	}
}
template <typename D, typename S>
Array<D, S>& Array<D, S>::resize(S &size)
{
	
	/*D *s;
	s = new D[size]();*/
	///*for (int i = 0; i < size; i++)
	//{
	//	cout << s[i] << "\n";
	//}*/
	//
	///*for (S i = size-1; i < length; i++)
	//{
	//	delete[i]data;
	//}*/
	//for (S i = 0; i < length; i++)
	//{
	//	s[i] = data[i];
	//}
	/*for (S i = size; i < length; i++)
	{
	delete[]data[i];
	}
	*/
	if (length != 0)
	{
		delete[]data;
	}
	length = size;
	data = new D[length];
	/*data = s;*/
	
	return *this;

}
template <typename D, typename S>
Array<D, S>&Array<D, S>::insert(const D&element, S idx)
{
	D *s;
	s = new D[length + 1];
	if (idx > length)
	{
		for (int i = 0; i < length; i++)
		{
			s[i] = data[i];
		}
		s[length] = element;
		length++;
	}
	else
	{
		if (idx <= length && idx != 0)
		{
			if (length > idx)
			{
				for (S i = 0; i < idx; i++)
				{
					s[i] = data[i];
				}
				for (int i = idx+1, k = 0; i < length + 1; k++, i++)
				{
					s[i] = data[k];
				}
				s[idx] = element;
				length++;
			}
			else
			{
				if (length == idx)
					for (int i = 0; i < length; i++)
					{
						s[i] = data[i];
					}
				s[length] = element;
				length++;
			}
		}
		else
			if (idx <= 0)
			{
				for (int i = 1, k = 0; i < length + 1; k++, i++)
				{
					s[i] = data[k];
				}
				idx = 0;
				s[idx] = element;
				length++;
			}

	}
		

	
	/*s[idx] = element;*/
	delete[]data;
	
	data = s;
	return *this;
}
template <typename D,typename S>
D& Array <D, S>::back()
{
	return data[length-1];
}
template <typename D, typename S>
D& Array <D, S>::front()
{
	return data[0];
}
template <typename D, typename S>
void Array<D, S>:: clear()
{
	
	/*S s = length;*/

	delete[]data;
	/*length = s;
	*/
	data = new D[0];
	
	delete[]data;
	data = new D[length];
}
template <typename D, typename S>
Array<D,S> Array<D, S>::operator+(const Array<D, S> & obj)const
{
	
	D *s;
	S sd = length + obj.length;
	s = new D[length + obj.length];
	for (int i = 0; i < length; i++)
	{
		s[i] = data[i];
		
	}
	for (int i = length, k = 0; i <sd; k++, i++)
	{
		s[i] = obj.data[k];
		
	}
	
	
	return Array<D, S>(s, sd );
	
	/*S sd = length + obj.length;
	Array <D, S> tmp();
	tmp.Output();
	cout <<"T"<< endl;
	for (int i = 0; i < length; i++)
	{
		tmp.data[i] = data[i];
	}
	for (int i = length, k=0; i < sd;k++, i++)
	{
		tmp.data[i] = obj.data[k];
		
	}
	tmp.Output();
	cout << "T" << endl;
	return tmp;*/
}
template <typename D, typename S>
bool Array<D, S>:: operator==(const Array<D, S>&obj)const
{
	if (length != obj.length)
		return false;
	int counter=0;
	for (int i = 0; i < length; i++)
	{
		if (data[i] == obj.data[i])
			counter++;
	}
	if (counter == length)
		return true;
	else
		return false;
}
template <typename D, typename S>
bool Array<D, S>:: operator!=(const Array<D, S>&obj)const
{
	if (length != obj.length)
		return true;
	int counter = 0;
	for (int i = 0; i < length; i++)
	{
		if (data[i] == obj.data[i])
			counter++;
	}
	if (counter == length)
		return false;
	else
		return true;
}

template <typename D, typename S>
const D Array<D, S>::GetData()
{
	return Data;
}
//template <typename D, typename S>
//void  operator<<(ostream& out, const Array<D,S> *obj)
//{
//	for (int i = 0; i < obj->length; i++)
//	{
//		cout << "We ar her";
//		out << (*obj).GetData()[i]<<endl;
//	}
//}
#endif