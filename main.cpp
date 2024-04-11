#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include "MainMenu.h"
#include "WorkoutDay.h"
#include <string>
#include "Input.h"

vector<WorkoutDay*> day;
using namespace std;

int main(int argc, char *argv[])
{
	readDayFromFile(day);


	if (argc == 2)
	{
		string arg = argv[1];
		showWorkoutDay(day,arg);
	}

	cout << "" << endl<<endl;
	while (1)
	{
		showMenu(day);

		cout << "Wybierz opcje: ";
		int ch = input<int>(1,5);

		switch (ch)
		{
			case 1:
				showWorkoutDay(day);
				break;
			case 2:
				addWorkoutDay(day);
				break;
			case 3:
				deleteWorkoutDay(day);
				break;
			case 4:
				ChangeNameDay(day);
				break;
			case 5:
				writeDayToFile(day);
				exit(0);
			default:
				system("cls");
				cout << "Bledna opcja!" << endl << endl;;
				break;
		}

	}

}

