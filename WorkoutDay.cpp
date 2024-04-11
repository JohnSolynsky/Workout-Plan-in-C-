#include "WorkoutDay.h"
#include "Exercise.h"
#include "ExerciseTime.h"
#include "ExerciseReps.h"
#include <string>
#include <vector>
#include "Input.h"

string WorkoutDay::getDayName()
{
	return name;
}

void WorkoutDay::setDayName()
{
	cout << "Podaj nowa nazwe: ";
	string n;
	getline(cin, n);
	name = n;
}

void WorkoutDay::setDayName(const string& n)
{
	name = n;
}

ostream& operator<<(ostream& COUT, vector<Exercise*>& exercise)
{
	if (exercise.size() == 0)
		cout << "    Brak cwiczen w tym dniu!" << endl;
	else
		for (int i = 0; i < exercise.size(); i++)
		{
			cout << "     - " << i + 1 << ". " << " ";
			exercise[i]->getExercise();
		}

	return COUT;
}
void WorkoutDay::menu()
{
	cout << endl << endl;
	while (1)
	{
		
		cout <<"| "<< getDayName() <<" |"<< endl << endl;
		
		cout << exercise;

		cout << endl << endl << endl << endl;
		cout << "Opcje: "<<endl;
		cout << "1.Dodaj cwiczenie" << endl;
		cout << "2.Usun cwiczenie" << endl;
		cout << "3.Modyfikuj cwiczenie" << endl;
		cout << "4.Powrot" << endl<<endl;
		cout<<"Wybierz opcje: ";

		int ch=input<int>(1,4);

		if (ch == 4)
		{
			system("cls");
			break;
		}

		switch (ch)
		{
			case 1:
				addExercise(exercise);
				break;

			case 2:
				deleteExercise(exercise);
				break;

			case 3:
				modifyExercise(exercise);
				break;

			default:
				system("cls");
				cout << "Blad wyboru!" << endl << endl;
				break;
		}
	}
}

void WorkoutDay::addExercise(vector<Exercise*>& exercise)
{
	Exercise* ex{};
	int t;
	
	while (1)
	{
		cout << "Podaj typ cwiczenia ( 1.Reps lub 2.Time ): ";
		t=input<int>(1,2);
		
		if (t == -1)
		{
			cout << "Bledny typ!\n";
			continue;
		}
		
		break;
	}

	if (t == 1)
		ex = new ExerciseReps("0", 0, 0, 0,1);
	else if (t == 2)	
		ex = new ExerciseTime("0",0,0,0,2);

	ex->setName();
	ex->setSets();
	ex->setWeight();
	ex->setRepsOrTime();
			
	exercise.push_back(ex);

	system("cls");
	cout << ("Pomyslnie dodano cwiczenie!") << endl << endl;
}

void WorkoutDay::deleteExercise(vector<Exercise*>& exercise)
{
	
	cout << "Podaj numer cwiczenia do usuniecia:  ";
	int n = input<int>(1,exercise.size());

	system("cls");
	
	if (n != -1)
	{
		exercise.erase(exercise.begin() + n - 1);
		cout << "Pomyslnie usunieto cwiczenie!" << endl << endl;
	}
	else
	{
		cout << "Nie ma takiego cwiczenia!" << endl << endl;
	}

}

void WorkoutDay::modifyExercise(vector<Exercise*>& exercise)
{
	
	cout << "Podaj numer cwiczenia do modyfikacji:  ";
	
	int n = input<int>(1, exercise.size());

	if(n!=-1)
	{
		exercise[n - 1]->getModifyInfo1();

		int ch = input<int>(1, 4);

		switch (ch)
		{
			case 1:
				exercise[n-1]->setName();
				system("cls");
				break;
			case 2:
				exercise[n - 1]->setSets();
				system("cls");
				break;
			case 3:
				exercise[n - 1]->setWeight();
				system("cls");
				break;
			case 4:
				exercise[n - 1]->setRepsOrTime();
				system("cls");
				break;
			default:
				system("cls");
				cout << "Nie ma takiego parametru!" << endl << endl;
				break;
		}

		if (ch != -1)
			cout << "Pomyslnie zmieniono!" << endl << endl;
		
	}
	else
	{
		system("cls");
		cout << "Nie ma takiego cwiczenia!" << endl << endl;
	}


}

void WorkoutDay::writeExerciseToFile(fstream& file)
{
	int n = exercise.size();
	file.write(reinterpret_cast<char*>(&n), sizeof(n));

	for (int i = 0; i < n; i++)
	{
		int ty = exercise[i]->getType();
		file.write(reinterpret_cast<char*>(&ty), sizeof(ty));

		string n = exercise[i]->getName();
		int len = n.size();
		file.write(reinterpret_cast<char*>(&len), sizeof(len));
		file.write(reinterpret_cast<char*>(&n[0]), len);

		int s = exercise[i]->getSets();
		file.write(reinterpret_cast<char*>(&s), sizeof(s));

		float w = exercise[i]->getWeight();
		file.write(reinterpret_cast<char*>(&w), sizeof(float));

		int rt = exercise[i]->getRepsOrTime();
		file.write(reinterpret_cast<char*>(&rt), sizeof(rt));

	}
}

void WorkoutDay::readExerciseFromFile(fstream& file)
{
	int n;
	file.read(reinterpret_cast<char*>(&n), sizeof(n));

	for (int i = 0; i < n; i++)
	{
		int ty;
		file.read(reinterpret_cast<char*>(&ty), sizeof(ty));

		Exercise* temp{};

		if (ty == 1)
			temp = new ExerciseReps("0", 0, 0, 0, 1);
		else if (ty == 2)
			temp = new ExerciseTime("0", 0, 0, 0, 2);


		int len;
		file.read(reinterpret_cast<char*>(&len), sizeof(len));
		string n;
		n.resize(len);
		file.read(reinterpret_cast<char*>(&n[0]), len);
		temp->setName(n);

		int s;
		file.read(reinterpret_cast<char*>(&s), sizeof(s));
		temp->setSets(s);

		float w;
		file.read(reinterpret_cast<char*>(&w), sizeof(float));
		temp->setWeight(w);

		int rt;
		file.read(reinterpret_cast<char*>(&rt), sizeof(rt));
		temp->setRepsOrTime(rt);

	
		exercise.push_back(temp);
	}
}