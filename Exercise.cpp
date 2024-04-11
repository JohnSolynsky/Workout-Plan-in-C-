#include "Exercise.h"
#include <string>
#include "input.h"

void Exercise::setName()
{
	string n;
	cout << "Podaj nazwe: ";
	getline(cin, n);

	name = n;
}

void Exercise::setSets()
{
	while (1)
	{
		cout << "Podaj ilosc serii: ";
		sets = input<int>(0, INT_MAX);

		if (sets == -1)
		{
			cout << "Bledna ilosc serii!\n";
			continue;
		}

		break;
	}
}

void Exercise::setWeight()
{
	while (1)
	{
		cout << "Podaj Kilogramy: ";
		weight = input<float>(0, INT_MAX);

		if (weight == -1)
		{
			cout << "Bledna ilosc kilogramow!\n";
			continue;
		}

		break;
	}
}

void Exercise::setName(string n)
{
	name = n;
}

void Exercise::setSets(int s)
{
	sets = s;
}

void Exercise::setWeight(float w)
{
	weight = w;
}

string Exercise::getName()
{
	return name;
}

int Exercise::getSets()
{
	return sets;
}

float Exercise::getWeight()
{
	return weight;
}

int Exercise::getType()
{
	return type;
}
