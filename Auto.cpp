#include "Auto.h"

Auto::Auto()

{

	*model;
	model = new char[1];
	model[0] = '\0';
	year_i = 0; //year of issue
	*colour;
	colour = new char[1];
	colour[0] = '\0';
	s_number = new char[1];
	s_number[0] = '\0';
	buffer[0] = '\0';

}
Auto::~Auto()
{
	delete[]model;
	delete[]colour;
	delete[]s_number;
}
void Auto::Settime_r()
{
	time_t time_r;
	struct tm * timeinfo;


	time(&time_r);
	timeinfo = localtime(&time_r);

	strftime(buffer, 80, "Date of registration: %c", timeinfo);
}
void Auto::Setmodel(char *_model)
{
	strcpy(model, _model);
}
void Auto::Setyear_i(int _year_i)
{
	if (_year_i < 0)
		year_i = 0;
	else
		year_i = _year_i;

}
void Auto::Setcolour(char *_colour)
{
	strcpy(colour, _colour);
}

void Auto::Sets_number(char *_s_number)
{
	strcpy(s_number, _s_number);
}


char *Auto::Gettime_r()
{
	return buffer;
}

char *Auto::Getmodel()
{
	return model;
}

int Auto::Getyear_i()
{
	return year_i;
}

char *Auto::Getcolour()
{
	return colour;
}

char *Auto::Gets_number()
{
	return s_number;
}

Auto& Auto:: operator=(Auto&obj)
{
	if (this != &obj)
	{
		/*delete[]this;*/
		model = obj.model;
		year_i = obj.year_i;
		colour = obj.colour;
		s_number = obj.s_number;
		buffer[80] = obj.buffer[80];
		/*buffer[80] = obj.buffer[80];*/
		/*Setmodel(obj.model);

		Setyear_i(obj.year_i);

		Setcolour(obj.colour);
		Sets_number(obj.s_number);
		buffer[80] = obj.buffer[80];*/

	}
	return *this;
}

ostream& operator<<(ostream&out, const Auto &obj)
{



	out << obj.buffer << endl;
	out << "model:\t" << obj.model << endl;
	out << "year of issue:\t" << obj.year_i << endl;
	out << "colour:\t" << obj.colour << endl;
	out << "serial number:\t" << obj.s_number << endl;
	return out;

}
void operator >>(istream&is, Auto &obj)
{
	cin.clear();
	
	int  currentyear_i;

	////введення дати реєстрації
	//cout << "Enter date of registration\n";
	//while (!(cin >> currenttime_r)) {
	//	cin.clear();
	//	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	//	cout << "Invalid input.  Try again: ";
	//}
	obj.Settime_r();


	//введення назви моделі
	//побуквене введення строки можливостями звичайного Сі
	char *prevmodel = nullptr;
	char *currentmodel = nullptr;
	char currentSymbol = '\0';
	int Symbolcounter = 0;
	cout << "Press enter\n";//тут не вистарчає розуміння потоків
	cin.ignore();
	cout << "Enter model\n";
	//cin >> currentSymbol; //побуквене введення строки
	char z = '\n';


	cin.get(currentSymbol);
	
	while (currentSymbol != '\n')
	{

		Symbolcounter++;

		prevmodel = currentmodel;

		currentmodel = new char[Symbolcounter + 1];
		if (prevmodel != nullptr)
			strcpy(currentmodel, prevmodel);

		currentmodel[Symbolcounter - 1] = currentSymbol;
		currentmodel[Symbolcounter] = '\0';
		delete[]prevmodel;
		//cin >> currentSymbol;
		cin.get(currentSymbol);
	}
	/*delete[]obj.model;*/
	obj.model = new char[strlen(currentmodel) + 1];
	obj.Setmodel(currentmodel);
	delete[]currentmodel;


	//введення року випуску
	cout << "Enter year of issue\n";
	while (!(is >> currentyear_i)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input.  Try again: ";
	}
	obj.Setyear_i(currentyear_i);


	//введення кольору авто
	//побуквене введення строки можливостями звичайного Сі
	char *prevcolour = nullptr;
	char *currentcolour = nullptr;
	currentSymbol = '\0';
	Symbolcounter = 0;
	cin.ignore();
	cout << "Enter colour\n";
	//cin >> currentSymbol; //побуквене введення строки
	cin.get(currentSymbol);
	while (currentSymbol != '\n')
	{
		Symbolcounter++;

		prevcolour = currentcolour;

		currentcolour = new char[Symbolcounter + 1];
		if (prevcolour != nullptr)
			strcpy(currentcolour, prevcolour);

		currentcolour[Symbolcounter - 1] = currentSymbol;
		currentcolour[Symbolcounter] = '\0';
		delete[]prevcolour;
		//cin >> currentSymbol;
		cin.get(currentSymbol);
	}
	delete[]obj.colour;
	obj.colour = new char[strlen(currentcolour) + 1];
	obj.Setcolour(currentcolour);
	delete[]currentcolour;


	//введення номеру
	char *currents_number = nullptr;
	char *prevcurrents_number = nullptr;

	currentSymbol = '\0';
	Symbolcounter = 0;
	/*cin.ignore();*/
	cout << "Enter number\n";
	//cin >> currentSymbol; //побуквене введення строки
	cin.get(currentSymbol);
	while (currentSymbol != '\n')
	{
		Symbolcounter++;

		prevcurrents_number = currents_number;

		currents_number = new char[Symbolcounter + 1];
		if (prevcurrents_number != nullptr)
			strcpy(currents_number, prevcurrents_number);

		currents_number[Symbolcounter - 1] = currentSymbol;
		currents_number[Symbolcounter] = '\0';
		delete[]prevcurrents_number;
		//cin >> currentSymbol;
		cin.get(currentSymbol);
	}
	delete[]obj.s_number;
	obj.s_number = new char[strlen(currents_number) + 1];
	obj.Sets_number(currents_number);
	delete[]currents_number;
	cout << "Auto is registered\n";




}