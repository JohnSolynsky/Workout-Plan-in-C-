#include "ExerciseReps.h"
#include "input.h"

void ExerciseReps::getExercise()
{
	cout << name << ":    " << sets << " Sets    " << reps << " reps    " << weight << " Kg" << endl;
}

void ExerciseReps::setRepsOrTime()
{
	while (1)
	{
		cout << "Podaj ilosc powtorzen: ";
		reps = input<int>(0, INT_MAX);

		if (reps == -1)
		{
			cout << "Bledna ilosc powtorzen!\n";
			continue;
		}

		break;
	}
}

void ExerciseReps::setRepsOrTime(int rt)
{
	reps = rt;
}

int ExerciseReps::getRepsOrTime()
{
	return reps;
}

void ExerciseReps::getModifyInfo1()
{
	cout << "Podaj parametr do zmiany ( 1.Nazwa, 2.Serie, 3.Kilogramy, 4.Powtorzenia ):  ";
}

