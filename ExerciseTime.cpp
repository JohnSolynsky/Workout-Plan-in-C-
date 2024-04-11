#include "ExerciseTime.h"
#include "input.h"

void ExerciseTime::getExercise()
{
	cout << name << ":    " << sets << " Sets    " << time << " seconds    " << weight << " Kg" << endl;
}

void ExerciseTime::setRepsOrTime()
{
	while (1)
	{
		cout << "Podaj Czas: ";
		time = input<int>(0, INT_MAX);

		if (time == -1)
		{
			cout << "Bledna ilosc powtorzen!\n";
			continue;
		}

		break;
	}
}

void ExerciseTime::setRepsOrTime(int rt)
{
	time = rt;
}

int ExerciseTime::getRepsOrTime()
{
	return time;
}

void ExerciseTime::getModifyInfo1()
{
	cout << "Podaj parametr do zmiany ( 1.Nazwa, 2.Serie, 3.Kilogramy, 4.Czas ):  ";
}


