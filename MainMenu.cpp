#include "MainMenu.h"
#include "WorkoutDay.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "input.h"

using namespace std;

ostream& operator<<(ostream& COUT, vector<WorkoutDay*>& day)
{
	if (day.size() == 0)
		cout << "Brak dni Treninowych!" << endl;
	else
		for (int i = 0; i < day.size(); i++)
		{
			cout << "    - " << i + 1 << ". " << day[i]->getDayName() << endl;
		}

	return COUT;
}

void showMenu(vector<WorkoutDay*>& day)
{
	cout << " ----------------" << endl;
	cout << "| DNI TRENINGOWE |" << endl;
	cout << " ----------------" << endl;

	cout << day;
	
	cout << endl << endl << endl<<endl<<endl;
	cout << "Opcje: " << endl;
	cout << "1.Pokaz dzien treningowy" << endl;
	cout << "2.Dodaj dzien treningowy" << endl;
	cout << "3.Usun dzien treningowy" << endl;
	cout << "4.Zmien nazwe dnia treningowego" << endl;
	cout << "5.Exit" << endl << endl << endl;

}


void showWorkoutDay(vector<WorkoutDay*>& day,string arg)
{
	cout << "Wybierz dzien treningowy: ";
	int n;

	if (arg == "")
		n = input<int>(1, day.size());
	else
		n = input<int>(1, day.size(),arg);

	system("cls");

	if (n != -1)
		day[n - 1]->menu();
	else
		cout << "Nie ma takiego dnia!" << endl<<endl;
	
}

void addWorkoutDay(vector<WorkoutDay*> &day)
{
	cout << "Podaj Nazwe dnia: ";
	string name;
	
	getline(cin,name);

	WorkoutDay *d = new WorkoutDay(name);

	day.push_back(d);

	system("cls");
	cout << "Pomyslnie dodano dzien!" << endl << endl;

}

void deleteWorkoutDay(vector<WorkoutDay*> &day)
{
	cout << "Podaj numer dnia do skasowania: ";

	int n = input<int>(1, day.size());

	system("cls");
	if (n != -1)
	{
		day.erase(day.begin() + n - 1);
		cout << "Pomyslnie usunieto dzien!" << endl << endl;
	}
	else
		cout << "Nie ma takiego dnia!" << endl << endl;
	
}

void ChangeNameDay(vector<WorkoutDay*> &day)
{
	cout << "Podaj numer dnia do zmiany nazwy: ";

	int n = input<int>(1, day.size());
	
	if (n != -1)
	{
		cout << "Podaj nowa nazwe: ";
		string name;
		getline(cin, name);
		day[n - 1]->setDayName(name);

		system("cls");
		cout << "Pomyslnie zmieniono nazwe!" << endl << endl;
	}
	else 
	{
		system("cls");
		cout << "Nie ma takiego dnia!" << endl<<endl;
	}
}

void writeDayToFile(vector<WorkoutDay*>& day)
{
	
	fstream file;
	file.open("object_file.dat", ios::out | ios::binary);

	if (!file.is_open())
	{
		cout << "Blad otwarcia pliku!" << endl;
		exit(1);
	}
	
	int n = day.size();
	file.write(reinterpret_cast<char*>(&n), sizeof(n));
	for (int i = 0; i < n; i++)
	{
		string name = day[i]->getDayName();
		int len = name.size();
		file.write(reinterpret_cast<char*>(&len), sizeof(len));
		file.write(reinterpret_cast<char*>(&name[0]), len);

		day[i]->writeExerciseToFile(file);


	}

	file.close();
	
}

void readDayFromFile(vector<WorkoutDay*>& day)
{
	fstream file;
	file.open("object_file.dat", ios::in | ios::binary);

	if (!file.is_open())
	{
		cout << "Blad otwarcia pliku!" << endl;
		exit(1);
	}


	int n;
	file.read(reinterpret_cast<char*>(&n), sizeof(n));

	for (int i = 0; i < n; i++)
	{
		WorkoutDay *temp = new WorkoutDay;

		int len;
		file.read(reinterpret_cast<char*>(&len), sizeof(len));
		string name;
		name.resize(len);
		file.read(reinterpret_cast<char*>(&name[0]),len);

		temp->setDayName(name);
		
		day.push_back(temp);

		day[i]->readExerciseFromFile(file);

	}
	

	file.close();
}

