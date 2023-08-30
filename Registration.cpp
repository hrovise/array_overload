
#include "Registration.h"

Registration::Registration()
{
	**Autos;
	Autos = new Auto*[1];
	Autos[0] = new Auto;
	**pAutos;
	pAutos = new Auto*[1];
	pAutos[0] = new Auto;
	int bcounter = 0;
}
Registration::~Registration()
{
	if (bcounter > 0)
	{
		for (int i = 0; i < bcounter; i++)
		{
			delete[] Autos[i];
		}
	}
	delete[]Autos;

}
void Registration::ConsoleInput()
{



	pAutos = Autos;//previous blist

	bcounter++;

	Autos = new Auto*[bcounter];
	for (int i = 0; i < bcounter - 1; i++)

	{

		Autos[i] = pAutos[i];


	}

	delete[]pAutos;

	Autos[bcounter - 1] = new Auto;//cout << "!";







	int  currentyear_i;

	////введення дати реєстрації
	//cout << "Enter date of registration\n";
	//while (!(cin >> currenttime_r)) {
	//	cin.clear();
	//	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	//	cout << "Invalid input.  Try again: ";
	//}
	Autos[bcounter - 1]->Settime_r();


	//введення назви моделі
	//побуквене введення строки можливостями звичайного Сі
	char *prevmodel = nullptr;
	char *currentmodel = nullptr;
	char currentSymbol = '\0';
	int Symbolcounter = 0;
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
	Autos[bcounter - 1]->model = new char[strlen(currentmodel) + 1];
	Autos[bcounter - 1]->Setmodel(currentmodel);
	delete[]currentmodel;


	//введення року випуску
	cout << "Enter year of issue\n";
	while (!(cin >> currentyear_i)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input.  Try again: ";
	}
	Autos[bcounter - 1]->Setyear_i(currentyear_i);


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
	Autos[bcounter - 1]->colour = new char[strlen(currentcolour) + 1];
	Autos[bcounter - 1]->Setcolour(currentcolour);
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
	Autos[bcounter - 1]->s_number = new char[strlen(currents_number) + 1];
	Autos[bcounter - 1]->Sets_number(currents_number);
	delete[]currents_number;
	cout << "Auto is registered\n";






}
char *Registration::Get_model(int i)
{
	return Autos[i]->Getmodel();
}
char *Registration::Get_colour(int i)
{
	return Autos[i]->Getcolour();
}
char *Registration::Get_s_number(int i)
{
	return Autos[i]->Gets_number();
}


void Registration::ConsoleOutput()//b - змінна елементу масива, який потрібно показати
{

	/*cout << "Auto #" << b + 1 << ":\n";*/
	cout << Autos[bcounter - 1]->buffer << endl;
	cout << "model:\t" << Autos[bcounter - 1]->model << endl;
	cout << "year of issue:\t" << Autos[bcounter - 1]->year_i << endl;
	cout << "colour:\t" << Autos[bcounter - 1]->colour << endl;
	cout << "serial number:\t" << Autos[bcounter - 1]->s_number << endl;


}
void Registration::ConsoleOutput1(int i)//b - змінна елементу масива, який потрібно показати
{

	cout << "Auto #" << i + 1 << ":\n";
	cout << Autos[bcounter - 1]->buffer << endl;
	cout << "model:\t" << Autos[bcounter - 1]->model << endl;
	cout << "year of issue:\t" << Autos[bcounter - 1]->year_i << endl;
	cout << "colour:\t" << Autos[bcounter - 1]->colour << endl;
	cout << "serial number:\t" << Autos[bcounter - 1]->s_number << endl;


}


void Registration::Show(Registration **Autos, int size)
{


	for (int i = 0; i < size; i++)
	{
		if (Autos[i] != nullptr)
			Autos[i]->ConsoleOutput1(i);
	}

}
void Registration::Delete(Registration **Auto, int b, int size)
{
	Registration **FakeAuto = nullptr;
	FakeAuto = Auto;


	delete Auto[b];

	Auto[b] = nullptr;
	/*Auto[b] = new Registration();*/
	delete[]Auto;


	/*Auto[b]->ConsoleOutput();*/


	for (int i = 0; i < b; i++)
	{

		Auto[i] = FakeAuto[i];

	}
	for (int i = b + 1, k = b; i < size; i++, k++)
	{

		Auto[k] = FakeAuto[i];

	}

	delete[]FakeAuto;
	Auto[0]->ConsoleOutput();
}

ostream& operator<<(ostream&out, const Registration &obj)
{

	out << (*(*obj.Autos));
	return out;

}
void operator >>(istream&is, Registration &obj)

{
	
	delete[]obj.Autos;
	

	obj.Autos = new Auto*[1];
	

	obj.Autos[0] = new Auto;//cout << "!";
	is >> (*(*obj.Autos));

}
Registration&Registration:: operator=(const Registration &obj)
{
	if (this != &obj)
	{
		/*for (int i = 0; i < bcounter; i++)
		{
		delete Autos[i];
		}*/
		delete Autos[0];
		delete[] Autos;

		bcounter++;
	
		Autos = new Auto*[1];

		
		Autos[0] = new Auto;

		
		**Autos = (*(*obj.Autos));
		
	}
	return *this;

}