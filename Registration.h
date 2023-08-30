#include "Auto.h"


class Registration
{

	Auto **Autos;
	Auto**pAutos;
	int bcounter;
public: Registration();
public: ~Registration();
public: void ConsoleInput();
public:void ConsoleOutput();
public: void Show(Registration **Autos, int size);
public: void Delete(Registration **Auto, int b, int size);
		//public: void Search(int size);
public:char *Get_model(int i);
public:  char *Get_colour(int i);
public:	 char *Get_s_number(int i);

public: void ConsoleOutput1(int i);
		friend ostream& operator<<(ostream&out, const  Registration &obj);
		friend	void operator >>(istream&is, Registration &obj);
public:Registration& operator=(const Registration &obj);
};