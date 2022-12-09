#include <iostream>
#include <string>
#include "Pet.h"
#include <algorithm>

Pet::Pet()
{
	name = "";
	happiness = 0;
	health_level = 0;
	satiation_level = 0;
	energy = 0;

}
Pet::Pet(string _name, int _happiness, int satiation, int health, int _energy, int _level)
{
	name = _name;
	happiness = _happiness;
	satiation_level = satiation;
	health_level = health;
	energy = _energy;
	level = _level;
}
void Pet::setName (string n)
{
	name = n;
}
string Pet::getName()
{
	return name;
}

void Pet::Sad()
{
	if (happiness < 5)
	{
		health_level -= 2;
		PetStatusAdjustment();
		cout << name << " is reallly sad (-_-)" << endl;
	}
	
}
void Pet::death()
{
	string temp = name;
	std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
	cout << "     " << temp << " IS DEAD (+_+)" << endl;
	cout << "		  !! GAME OVER !!            " << endl;
}

void  Pet::Ill()
{
	if (energy < 5)
	{
		cout << name << " feels sleepy." << endl;
	}
	if (energy < 4)
	{
		health_level -= 2;
		PetStatusAdjustment();
	}
	if (health_level < 5)
	{
		cout << name << " is ill." << endl;
	}
	
}
void Pet::Hunger()
{
	if (satiation_level < 4)
	{
		health_level -= 1;
		PetStatusAdjustment();
		cout << name << " is hungry." << endl;
	}
}

void Pet::PetStatusAdjustment()
{
	if (happiness < 0) 
	{
		happiness = 0;
	}
	else if (happiness > 10) {
		happiness = 10;
	}
	if (energy < 0) {
		energy = 0;
	}
	else if (energy > 10) {
		energy = 10;
	}
	if (satiation_level > 10) {
		satiation_level = 10;
	}
	else if (satiation_level < 0) {
		satiation_level = 0;
	}
	if (health_level > 10) {
		health_level = 10;
	}
	else if (health_level < 0) {
		health_level = 0;
	}
}
void Pet::go_to_the_vet()
{	
	if (health_level < 5)
	{
		health_level = 10;
		cout << "Doc treated " << name << endl;
	}
	else
	{
		cout << name << " is not sick" << endl;
	}
}
int Pet::getHappiness()
{
	return happiness;
}
int Pet::getHealth_level()
{
	return health_level;
}
int Pet::getsatiation_level()
{
	return satiation_level;
}
int Pet::getEnergy()
{
	return energy;
}
int Pet::getLevel()
{
	return level;
}
void Pet::levelUp()
{
	level++;
}



