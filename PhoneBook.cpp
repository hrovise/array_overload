#include "PhoneBook.h"

PhoneBook::PhoneBook()
{

	name[0] = '\0';
	surname[0] = '\0';
	patronymic[0] = '\0';
	homenumber = 0;
	worknumber = 0;
	mobilenumber = 0;
	moreinfo[0] = '\0';
	/*cout << "Ctor without params\n";*/

} //стартова ініціалізація нулями

PhoneBook::PhoneBook(char *_name, char *_surname, char *_patronymic, long long  _homenumber, long long _mobilenumber, long long _worknumber, char *_moreinfo)
{

	if (_homenumber < 0)

		homenumber = 0;
	else
		homenumber = _homenumber;


	if (_worknumber < 0)
		worknumber = 0;
	else
		worknumber = _worknumber;


	if (_mobilenumber < 0)

		mobilenumber = 0;
	else
		mobilenumber = _mobilenumber;

	strcpy(name, _name);
	strcpy(surname, _surname);
	strcpy(patronymic, _patronymic);
	strcpy(moreinfo, _moreinfo);

	cout << "ctor with params" << endl;



}

PhoneBook:: ~PhoneBook()
{

}

char *PhoneBook::Getname()
{
	return name;
}
char *PhoneBook::Getsurname()
{
	return surname;
}
char *PhoneBook::Getpatronymic()
{
	return patronymic;
}
char *PhoneBook::Getmoreinfo()
{
	return moreinfo;
}
long long PhoneBook::Gethomenumber()
{
	return homenumber;
}
long long PhoneBook::Getworknumber()
{
	return worknumber;
}
long long PhoneBook::Getmobilenumber()
{
	return mobilenumber;
}
void PhoneBook::Setname(char *_name)
{
	strcpy(name, _name);
}
void PhoneBook::Setsurname(char *_surname)
{
	strcpy(surname, _surname);
}
void PhoneBook::Setpatronymic(char *_patronymic)
{
	strcpy(patronymic, _patronymic);
}
void PhoneBook::Setmoreinfo(char *_moreinfo)
{
	strcpy(moreinfo, _moreinfo);
}
void PhoneBook::Sethomenumber(long long _homenumber)
{
	if (_homenumber < 0)
		homenumber = 0;
	else
		homenumber = _homenumber;
}
void PhoneBook::Setworknumber(long long _worknumber)
{
	if (_worknumber < 0)
		worknumber = 0;
	else
		worknumber = _worknumber;
}
void PhoneBook::Setmobilenumber(long long _mobilenumber)
{
	if (_mobilenumber < 0)
		mobilenumber = 0;
	else
		mobilenumber = _mobilenumber;
}



void PhoneBook::ConsoleInput()
{

	char currentname[15];
	char currentsurname[20];
	char currentpatronymic[20];
	long long  currenthomenumber;
	long long  currentworknumber;
	long long  currentmobilenumber;
	char currentmoreinfo[1000];



	cout << "Enter mobilenumber\n";
	while (!(cin >> currentmobilenumber)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input.  Try again: ";
	}

	Setmobilenumber(currentmobilenumber);



	cout << "Enter worknumber\n";
	while (!(cin >> currentworknumber)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input.  Try again: ";
	}
	Setworknumber(currentworknumber);

	cout << "Enter homenumber\n";
	while (!(cin >> currenthomenumber)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input.  Try again: ";
	}
	Sethomenumber(currenthomenumber);

	/*cin.ignore();*/


	cout << "Enter name\n";
	cin >> currentname;
	cin.clear();
	/*cout << endl;*/
	Setname(currentname);

	cout << "Enter surname\n";
	cin >> currentsurname;
	/*cout << endl;*/
	Setsurname(currentsurname);

	cout << "Enter patronymic\n";
	cin >> currentpatronymic;
	/*cout << endl;*/
	Setpatronymic(currentpatronymic);

	cout << "Enter more info\n";

	cin.ignore();
	cin.get(currentmoreinfo, 1000);
	/*cout << endl ;*/

	Setmoreinfo(currentmoreinfo);
	/*cin.clear('\n');
	cin.ignore();*/
	cout << "The subscriber was created successfully!\n";
}

void PhoneBook::ConsoleOutput(int b)//показує занулені елементи як Doesn't exist(це можна міняти, для зручності зробив тільки щоб перевірка йшла по іменам)
{


	cout << "Subscriber #" << b + 1 << ":\n";
	cout << "name:\t\t" << name << endl;
	cout << "surname:\t" << surname << endl;
	cout << "patronymic:\t" << patronymic << endl;
	cout << "homenumber:\t" << homenumber << endl;
	cout << "mobilenumber:\t" << mobilenumber << endl;
	cout << "worknumber:\t" << worknumber << endl;
	cout << "moreinfo:\t" << moreinfo << endl;



}

void PhoneBook::ConsoleOutput()//показує занулені елементи як Doesn't exist(це можна міняти, для зручності зробив тільки щоб перевірка йшла по іменам)
{


	
	cout << "name:\t\t" << name << endl;
	cout << "surname:\t" << surname << endl;
	cout << "patronymic:\t" << patronymic << endl;
	cout << "homenumber:\t" << homenumber << endl;
	cout << "mobilenumber:\t" << mobilenumber << endl;
	cout << "worknumber:\t" << worknumber << endl;
	cout << "moreinfo:\t" << moreinfo << endl;



}

void PhoneBook::Show(PhoneBook **blist, int bcounter)
{

	/*cout << size << "t";*/
	for (int i = 0; i < bcounter; i++)
	{
		/*cout << i << "i";
		cout << size << "size";*/
		/*cout << "Subscriber #" << i + 1 << ":\n";*/
		blist[i]->ConsoleOutput(i);


	}
	cout << "ALL Participents had been shown\n";

}

void PhoneBook::Search(PhoneBook **blist, int bcounter)
{
	cout << "Enter name/surname/patronymic\n";
	char str[15], str1[20], str2[20];
	int p = 0;
	cin.ignore();
	cout << "Enter Name:\t";
	cin.get(str, 15);
	cout << endl;
	cin.ignore();
	cout << "Enter Surname:\t";
	cin.get(str1, 20);
	cout << endl;
	cin.ignore();
	cout << "Enter Patronymic:\t";
	cin.get(str2, 20);
	cout << endl;


	for (int i = 0; i < bcounter; i++)
	{

		int rez = strcmp(blist[i]->Getname(), str);
		if (rez == 0)
		{
			int rez1 = strcmp(blist[i]->Getsurname(), str1);

			if (rez1 == 0)
			{
				int rez2 = strcmp(blist[i]->Getpatronymic(), str2);

				if (rez2 == 0)
				{
					blist[i]->ConsoleOutput(i);
					p++;
				}
			}
		}

	}
	if (p == 0)
		cout << "No matches\n";
}


char *PhoneBook::file(char *fil)
{



	int i = 0;
	while (true)
	{
		i = 0;
		std::cout << "Create name of file\n";

		while (true)
		{
			cin.ignore();
			cin.clear();
			std::cin.get(fil, 80);

			if (strchr(fil, '.'))
			{
				cout << "You entered name file with extenstion\nType name without extension\n";
				i++;
				break;

			}
			strcat(fil, ".txt");

			if (FileExists(fil))
			{
				cout << "This file exist\n";
				cout << "Try another name\n";

				continue;
			}
			else

				break;

		}
		if (i == 1)
			continue;
		std::cout << "FILE: " << fil << " has been created\n" << endl;
		break;
	}

	return fil;
}

char*PhoneBook::lltoa(long long val, int base)
{

	static char buf[64] = { 0 };

	int i = 62;
	int sign = (val < 0);
	if (sign) val = -val;

	if (val == 0) return "0";

	for (; val && i; --i, val /= base) {
		buf[i] = "0123456789abcdef"[val % base];
	}

	if (sign) {
		buf[i--] = '-';
	}
	return &buf[i + 1];

}


void PhoneBook::save(PhoneBook **blist, int i, char *filename)
{


	FILE *f;





	fopen_s(&f, filename, "w+");



	char *s;
	char *d, l[20]; char z[150] = "PROFILE #";

	_itoa_s(i, l, 10);
	s = strcat(z, l);


	fputs(s, f);
	fputs("\n", f);

	fputs("NAME: ", f);
	fputs("\t\t", f);
	fputs(blist[i - 1]->Getname(), f);
	fputs("\n", f);

	fputs("SURNAME: ", f);
	fputs("\t", f);
	fputs(blist[i - 1]->Getsurname(), f);
	fputs("\n", f);

	fputs("PATRONYMIC: ", f);
	fputs("\t", f);
	fputs(blist[i - 1]->Getpatronymic(), f);
	fputs("\n", f);

	fputs("ABOUT: ", f);
	fputs("\t\t", f);
	fputs(blist[i - 1]->Getmoreinfo(), f);
	fputs("\n", f);

	d = lltoa(blist[i - 1]->Getmobilenumber(), 10);
	fputs("MOBILENUMBER: ", f);
	fputs("\t", f);
	fputs(d, f);
	fputs("\n", f);

	d = lltoa(blist[i - 1]->Getworknumber(), 10);
	fputs("WORKNUMBER: ", f);
	fputs("\t", f);
	fputs(d, f);
	fputs("\n", f);


	d = lltoa(blist[i - 1]->Gethomenumber(), 10);
	fputs("HOMENUMBER: ", f);
	fputs("\t", f);
	fputs(d, f);
	fputs("\n", f);






	fclose(f);









}
void PhoneBook::read(/*PhoneBook **blist,*/ char *filename)
{
	FILE *f;
	long long a;

	fopen_s(&f, filename, "r");
	char tmp[100], d[1000];
	char  *s;


	fgets(tmp, 100, f);
	cout << tmp << endl;
	fgets(tmp, 100, f);
	cout << tmp/* << endl*/;
	fgets(tmp, 100, f);
	cout << tmp /*<< endl*/;
	fgets(tmp, 100, f);
	cout << tmp /*<< endl*/;
	fgets(d, 1000, f);
	cout << tmp /*<< endl*/;

	fgets(tmp, 100, f);

	s = strchr(tmp, '\t');//знаходимо вказівник на входження другої строки(програма верне її з табуляцією)

	a = atoll(s);

	int size = strlen(tmp) - strlen(s);
	char *str = new char[size];




	for (int i = 0; i < size; i++)
	{
		str[i] = tmp[i];


	}
	for (int i = 0; i < size; i++)
	{
		cout << str[i];
	}
	cout << "\t";

	cout << a << endl;


	fgets(tmp, 100, f);
	s = strchr(tmp, '\t');

	a = atoll(s);

	int size1 = strlen(tmp) - strlen(s);//довжина першої стрічки
	char *str1 = new char[size1];




	for (int i = 0; i < size1; i++)//виводим строку по буквам
	{
		str1[i] = tmp[i];


	}
	for (int i = 0; i < size1; i++)
	{
		cout << str1[i];
	}
	cout << "\t";

	cout << a << endl;

	fgets(tmp, 100, f);

	s = strchr(tmp, '\t');

	a = atoll(s);

	int size2 = strlen(tmp) - strlen(s);
	char *str2 = new char[size2];



	for (int i = 0; i < size2; i++)
	{
		str2[i] = tmp[i];


	}
	for (int i = 0; i < size2; i++)
	{
		cout << str2[i];
	}
	cout << "\t";

	cout << a << endl;





	fclose(f);




}
void PhoneBook::PhoneBook::del()
{


}


bool PhoneBook::FileExists(char* filename)
{
	struct stat fileInfo;
	return stat(filename, &fileInfo) == 0;
}

PhoneBook& PhoneBook:: operator=( PhoneBook&obj)
{
	if (this != &obj)
	{
		Setname(obj.name);
		Setsurname(obj.surname);
		Setpatronymic(obj.patronymic);
		Sethomenumber(obj.Gethomenumber());
		Setworknumber(obj.worknumber);
		Setmobilenumber(obj.mobilenumber);
		Setmoreinfo(obj.moreinfo);
	}
	return *this;

}
ostream&  operator<<(ostream& out, const PhoneBook & book)
{

	out << "name:\t\t" << book.name << endl;
	out << "surname:\t" << book.surname << endl;
	out << "patronymic:\t" << book.patronymic << endl;
	out << "homenumber:\t" << book.homenumber << endl;
	out << "mobilenumber:\t" << book.mobilenumber << endl;
	out << "worknumber:\t" <<book.worknumber << endl;
	out << "moreinfo:\t" << book.moreinfo << endl;

	return out;


	/*out << book.name << endl;

	out << book.surname << endl;
	out << book.patronymic << endl;
	out << book.homenumber << endl;
	out << book.worknumber << endl;
	out << book.mobilenumber << endl;
	out << book.moreinfo << endl;*/

}
void operator>>(istream&is, PhoneBook&book)
{
	char currentname[15];
	char currentsurname[20];
	char currentpatronymic[20];
	long long  currenthomenumber;
	long long  currentworknumber;
	long long  currentmobilenumber;
	char currentmoreinfo[1000];



	cout << "Enter mobilenumber\n";
	while (!(is >> currentmobilenumber)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input.  Try again: ";
	}

	book.Setmobilenumber(currentmobilenumber);



	cout << "Enter worknumber\n";
	while (!(is  >> currentworknumber)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input.  Try again: ";
	}
	book.Setworknumber(currentworknumber);

	cout << "Enter homenumber\n";
	while (!(is >> currenthomenumber)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input.  Try again: ";
	}
	book.Sethomenumber(currenthomenumber);

	/*cin.ignore();*/


	cout << "Enter name\n";
	is >> currentname;
	cin.clear();
	/*cout << endl;*/
	book.Setname(currentname);

	cout << "Enter surname\n";
	is >> currentsurname;
	/*cout << endl;*/
	book.Setsurname(currentsurname);

	cout << "Enter patronymic\n";
	is >> currentpatronymic;
	/*cout << endl;*/
	book.Setpatronymic(currentpatronymic);

	cout << "Enter more info\n";

	cin.ignore();
	cin.get(currentmoreinfo, 1000);
	/*cout << endl ;*/

	book.Setmoreinfo(currentmoreinfo);
	/*cin.clear('\n');
	cin.ignore();*/
	cout << "The subscriber was created successfully!\n";
	/*is >> book.name >> book.surname >> book.patronymic >> book.homenumber >> book.worknumber >> book.mobilenumber >> book.moreinfo;*/
}