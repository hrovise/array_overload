#include "Array.h"
#include "Registration.h"
#include "PhoneBook.h"
#include <string>
int main()
{
	
	int msw;//menu switch;
	do {
		cout << "Choose type of massive\n";
		cout << "1.Int\n";
		cout << "2.String\n";
		cout << "3.PhoneBook\n";
		cout << "4.Registration(car)\n";
		cout << "0.Exit\n";

		while (!(cin >> msw)) {


			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input.  Try again: ";

		}
	} while (msw < 0 && msw>4);
	switch (msw)
	{
	case 1:
	{

		int sw = -1;
		int sz = 0;//size of
		int sz1 = 0;

		cout << "Enter size\n";
		cin >> sz; cout << endl;
		Array<int>a(sz);
		cout << "Fill massive\n";
		for (int i = 0; i < sz; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < sz; i++)
		{
			cout << a[i] << "\t";
		}
		cout << endl;
		do
		{
			do {
				cout << "1.Change size\n";
				cout << "2.Fill massive\n";
				cout << "3.Sort massive\n";
				cout << "4.Take minimal element\n";
				cout << "5.Take average element\n";
				cout << "6.Take maximal element\n";
				cout << "7.Pushback element\n";
				cout << "8.Pushfront element\n";
				cout << "9.Delete last element\n";
				cout << "10.Delete first element\n";
				cout << "11.Insert element in variable position \n Put element:\n";
				cout << "12.Show last element\n";
				cout << "13.Show first element\n";
				cout << "14.Clear massive\n";
				cout << "15.Compare massives\n";//тут сделать подменю для создания нового масива и сравнения их
				cout << "16.Concatenation\n";//-//-
				cout << "0.Exit\n";

				while (!(cin >> sw)) {


					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input.  Try again: ";

				}
			} while (sw < 0 && sw>16);
			switch (sw)
			{
			case 1:
			{
				cout << "New size\n";
				cin >> sz;
				a.resize(sz);
				system("pause");
				break;
			}
			case 2:
			{
				cout << "Fill massive\n";
				for (int i = 0; i < sz; i++)
				{
					cin >> a[i];
				}
				for (int i = 0; i < sz; i++)
				{
					cout << a[i] << "\t";
				}
				system("pause");

				break;
			}
			case 3:
			{
				a.selectSort(a);
				a.Output();
				system("pause");
				break;
			}
			case 4:
			{
				cout << "minimal \n";
				cout << a.min(a);
				system("pause");
				break;
			}
			case 5:
			{
				cout << "average\n";
				cout << a.average(a) << endl;
				system("pause");
				break;
			}
			case 6:
			{
				cout << "maximal\n";
				cout << a.max(a) << endl;
				system("pause");
				break;
			}
			case 7:
			{

				cout << "Pushback element\n";
				int pb;
				cin >> pb;
				a.push_back(pb);
				a.Output();
				system("pause");
				break;
			}
			case 8:
			{
				int pf;
				cout << "Pushfront element\n";
				cin >> pf;
				a.push_front(pf);
				a.Output();
				system("pause");
				break;
			}
			case 9:
			{
				int YN;
				cout << "Delete last element\n";
				cout << "1.Yes\n2.No\n";
				cin >> YN;
				if (YN == 2)
					break;
				a.pop_back();
				a.Output();
				system("pause");

				break;
			}
			case 10:
			{
				int YN;
				cout << "Delete first element\n";
				cout << "1.Yes\n2.No\n";
				cin >> YN;
				if (YN == 2)
					break;

				a.pop_front();
				a.Output();

				system("pause");
				break;
			}
			case 11:
			{
				cout << "Insert element in variable position \n Put element:\n";
				int el;
				cin >> el;
				cout << "Choose position\n";
				int pos;
				cin >> pos;
				a.insert(el, pos);
				a.Output();
				system("pause");
				break;
			}
			case 12:
			{
				cout << "Last element\n";
				cout << a.back() << endl;;
				system("pause");
				break;
			}
			case 13:
			{
				cout << "First element\n";
				cout << a.front() << endl;
				system("pause");
				break;
			}
			case 14:
			{
				cout << "Clear massive\n";
				a.clear();
				a.Output();
				cout << endl;
				cout << "Enter new size\n";
				cin >> sz;
				a.resize(sz);
				system("pause");
				break;
			}

			case 15:
			{
				bool eq;
				int us;
				cout << "Enter size\n";
				cin >> sz1; cout << endl;
				Array<int>b(sz1);
				cout << "Fill massive\n";
				for (int i = 0; i < sz1; i++)
				{
					cin >> b[i];
				}
				for (int i = 0; i < sz1; i++)
				{
					cout << b[i] << "\t";
				}
				cout << endl;
				cout << "1.Use \"==\"\n";
				cout << "2.Use \"!=\"\n";
				cin >> us;
				switch (us)
				{
				case 1:
				{

					eq = (a == b);
					if (eq)
						cout << "true";
					else
						cout << "false";
					system("pause");
					break;
				}
				case 2:
				{
					eq = (a != b);
					cout << eq;
					if (eq)

						cout << "true";
					else
						cout << "false";


					system("pause");

					break;
				}




				}


				break;
			}

			case 16:
			{

				cout << "Enter size\n";
				cin >> sz1; cout << endl;
				Array<int>b(sz1);
				cout << "Fill massive\n";
				for (int i = 0; i < sz1; i++)
				{
					cin >> b[i];
				}
				for (int i = 0; i < sz1; i++)
				{
					cout << b[i] << "\t";
				}
				cout << endl;
				Array<int>c;
				c = a + b;
				c.Output();
				system("pause");
				break;
			}


			}


			}while (sw != 0);

			break;
		}
	


	case 2:
	{

		int sw=-1;
		int sz = 0;//size of
		int sz1 = 0;

		cout << "Enter size\n";
		cin >> sz; cout << endl;
		Array<string>a(sz);
		cout << "Fill massive\n";
		for (int i = 0; i < sz; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < sz; i++)
		{
			cout << a[i] << "\t";
		}
		cout << endl;


		do
		{
			do {
				cout << "1.Change size\n";
				cout << "2.Fill massive\n";
			
				cout << "3.Pushback element\n";
				cout << "4.Pushfront element\n";
				cout << "5.Delete last element\n";
				cout << "6.Delete first element\n";
				cout << "7.Insert element in variable position \n";
				cout << "8.Show last element\n";
				cout << "9.Show first element\n";
				cout << "10.Clear massive\n";
				cout << "11.Compare massives\n";//тут сделать подменю для создания нового масива и сравнения их
				cout << "12.Concatenation\n";//-//-
				cout << "0.Exit\n";

				while (!(cin >> sw)) {


					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input.  Try again: ";

				}
			} while (sw < 0 && sw>16);
			switch (sw)
			{
			case 1:
			{
				cout << "New size\n";
				cin >> sz;
				a.resize(sz);
				system("pause");
				break;
			}
			case 2:
			{
				cout << "Fill massive\n";
				for (int i = 0; i < sz; i++)
				{
					cin >> a[i];
				}
				for (int i = 0; i < sz; i++)
				{
					cout << a[i] << "\t";
				}
				system("pause");

				break;
			}
			
			case 3:
			{

				cout << "Pushback element\n";
				string pb;
				cin >> pb;
				a.push_back(pb);
				a.Output();
				system("pause");
				break;
			}
			case 4:
			{
				string pf;
				cout << "Pushfront element\n";
				cin >> pf;
				a.push_front(pf);
				a.Output();
				system("pause");
				break;
			}
			case 5:
			{
				if (a.Getlength() == 0)
					break;
				int YN;
				cout << "Delete last element\n";
				cout << "1.Yes\n2.No\n";
				cin >> YN;
				if (YN == 2)
					break;
				a.pop_back();
				a.Output();
				system("pause");

				break;
			}
			case 6:
			{
				if (a.Getlength() == 0)
					break;
				int YN;
				cout << "Delete first element\n";
				cout << "1.Yes\n2.No\n";
				cin >> YN;
				if (YN == 2)
					break;
				a.pop_front();
				a.Output();
				system("pause");

				break;
			}
			case 7:
			{
				cout << "Insert element in variable position \n Put element:\n";
				string el;
				cin >> el;
				cout << "Choose position\n";
				int pos;
				cin >> pos;
				a.insert(el, pos);
				a.Output();
				system("pause");
				break;
			}
			case 8:
			{
				cout << "Last element\n";
				cout << a.back() << endl;;
				system("pause");
				break;
			}
			case 9:
			{
				cout << "First element\n";
				cout << a.front() << endl;
				system("pause");
				break;
			}
			case 10:
			{
				cout << "Clear massive\n";
				a.clear();
				a.Output();
				cout << endl;
				cout << "Enter new size\n";
				cin >> sz;
				a.resize(sz);
				system("pause");
				break;
			}

			case 11:
			{
				bool eq;
				int us;
				cout << "Enter size\n";
				cin >> sz1; cout << endl;
				Array<string>b(sz1);
				cout << "Fill massive\n";
				for (int i = 0; i < sz1; i++)
				{
					cin >> b[i];
				}
				for (int i = 0; i < sz1; i++)
				{
					cout << b[i] << "\t";
				}
				cout << endl;
				cout << "1.Use \"==\"\n";
				cout << "2.Use \"!=\"\n";
				cin >> us;
				switch (us)
				{
				case 1:
				{

					eq = (a == b);
					if (eq)
						cout << "true";
					else
						cout << "false";
					system("pause");

					break;
				}
				case 2:
				{
					eq = (a != b);
					cout << eq;
					if (eq)

						cout << "true";
					else
						cout << "false";


					system("pause");

					break;
				}




				}





				break;
			}

			case 12:
			{

				cout << "Enter size\n";
				cin >> sz1; cout << endl;
				Array<string>b(sz1);
				cout << "Fill massive\n";
				for (int i = 0; i < sz1; i++)
				{
					cin >> b[i];
				}
				for (int i = 0; i < sz1; i++)
				{
					cout << b[i] << "\t";
				}
				cout << endl;
				Array<string>c;
				c = a + b;
				c.Output();
				cout << endl;
				system("pause");
				break;
			}

			}
		}while (sw != 0);
		break;
	}


	case 3:
	{
		int sw;
		int sz = 0;//size of
		int sz1 = 0;

		cout << "Enter size\n";
		cin >> sz; cout << endl;
		Array<PhoneBook>a(sz);
		cout << "Fill massive\n";
		for (int i = 0; i < sz; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < sz; i++)
		{
			cout << a[i];
			cout << "\t";
		}
		cout << endl;


		do
		{
			do {
				cout << "1.Change size\n";
				cout << "2.Fill massive\n";
				
				cout << "3.Delete last element\n";
				cout << "4.Delete first element\n";
				
				cout << "5.Show last element\n";
				cout << "6.Show first element\n";
				cout << "7.Clear massive\n";
				
				cout << "8.Concatenation\n";//-//-
				cout << "0.Exit\n";

				while (!(cin >> sw)) {


					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input.  Try again: ";

				}
			} while (sw < 0 && sw>16);
			switch (sw)
			{
			case 1:
			{
				cout << "New size\n";
				cin >> sz;
				a.resize(sz);
				system("pause");
				break;
			}
			case 2:
			{
				cout << "Fill massive\n";
				for (int i = 0; i < sz; i++)
				{
					cin >> a[i];
				}
				for (int i = 0; i < sz; i++)
				{
					cout << a[i];
					cout << "\t";
				}
				system("pause");

				break;
			}
			
			case 3:
			{
				int YN;
				cout << "Delete last element\n";
				cout << "1.Yes\n2.No\n";
				cin >> YN;
				if (YN == 2)
					break;
				a.pop_back();
				a.Output();

				system("pause");
				break;
			}
			case 4:
			{
				int YN;
				cout << "Delete first element\n";
				cout << "1.Yes\n2.No\n";
				cin >> YN;
				if (YN == 2)
					break;
				a.pop_front();
				a.Output();
				system("pause");

				break;
			}
			
			case 5:
			{
				if (a.Getlength() == 0)
					break;
				cout << "Last element\n";
				cout << a.back();
				cout << endl;;
				system("pause");
				break;
			}
			case 6:
			{
				if (a.Getlength() == 0)
					break;
				cout << "First element\n";
				cout << a.front();
				cout << endl;
				system("pause");
				break;
			}
			case 7:
			{

				cout << "Clear massive\n";
				a.clear();
				a.Output();
				cout << endl;
				cout << "Enter new size\n";
				cin >> sz;
				a.resize(sz);
				system("pause");
				break;
			}

		

			case 8:
			{

				cout << "Enter size\n";
				cin >> sz1; cout << endl;
				Array<PhoneBook>b(sz1);
				cout << "Fill massive\n";
				for (int i = 0; i < sz1; i++)
				{
					cin >> b[i];
				}
				for (int i = 0; i < sz1; i++)
				{
					cout << b[i];
					cout << "\t";
				}
				cout << endl;
				Array<PhoneBook>c;
				c = a + b;
				cout << c[0];
				c.Output();
				system("pause");
				break;
			}


			}



		}while (sw != 0);

			break;
		}


		


	case 4:
	{
		int sw;
		int sz = 0;//size of
		int sz1 = 0;

		cout << "Enter size\n";
		cin >> sz; cout << endl;
		Array<Registration>a(sz);
		cout << "Fill massive\n";
		for (int i = 0; i < sz; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < sz; i++)
		{
			cout << a[i];
			cout << "\t";
		}
		cout << endl;


		do
		{
			do {
				cout << "1.Change size\n";
				cout << "2.Fill massive\n";
				
				cout << "3.Delete last element\n";
				cout << "4.Delete first element\n";
				
				cout << "5.Show last element\n";
				cout << "6.Show first element\n";
				cout << "7.Clear massive\n";
				
				cout << "8.Concatenation\n";//-//-
				cout << "0.Exit\n";

				while (!(cin >> sw)) {


					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input.  Try again: ";

				}
			} while (sw < 0 && sw>16);
			switch (sw)
			{
			case 1:
			{
				cout << "New size\n";
				cin >> sz;
				a.resize(sz);
				system("pause");
				break;
			}
			case 2:
			{
				cout << "Fill massive\n";
				for (int i = 0; i < sz; i++)
				{
					cin >> a[i];
				}
				for (int i = 0; i < sz; i++)
				{
					cout << a[i];
					cout << "\t";
				}
				system("pause");

				break;
			}
			
			case 3:
			{
				int YN;
				cout << "Delete last element\n";
				cout << "1.Yes\n2.No\n";
				cin >> YN;
				if (YN == 2)
					break;
				a.pop_back();
				a.Output();
				system("pause");

				break;
			}
			case 4:
			{
				int YN;
				cout << "Delete first element\n";
				cout << "1.Yes\n2.No\n";
				cin >> YN;
				if (YN == 2)
					break;
				a.pop_front();
				a.Output();
				system("pause");

				break;
			}
			
			case 5:
			{
				if (a.Getlength() == 0)
					break;
				cout << "Last element\n";
				cout << a.back();
				cout << endl;;
				
				system("pause");
				break;
			}
			case 6:
			{
				if (a.Getlength() == 0)
					break;
				cout << "First element\n";
				cout << a.front();
				cout << endl;
				system("pause");
				break;
			}
			case 7:
			{

				cout << "Clear massive\n";
				a.clear();
				a.Output();
				cout << endl;
				cout << "Enter new size\n";
				cin >> sz;
				a.resize(sz);
				system("pause");
				break;
			}

			

			case 8:
			{

				cout << "Enter size\n";
				cin >> sz1; cout << endl;
				Array<Registration>b(sz1);
				cout << "Fill massive\n";
				for (int i = 0; i < sz1; i++)
				{
					cin >> b[i];
				}
				for (int i = 0; i < sz1; i++)
				{
					cout << b[i];
					cout << "\t";
				}
				cout << endl;
				Array<Registration>c;
				c = a + b;

				c.Output();
				cout << endl;
				system("pause");
				break;
			}


			}
		}while (sw != 0);
		break;
	}

	}













	
	system("pause");
	return 0;
}