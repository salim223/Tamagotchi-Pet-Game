#include <iostream>
using namespace std;

#ifndef PET_H
#define PET_H

class Pet
{
protected:
	string name;
	int happiness;
	int health_level;
	int satiation_level;
	int energy;
	int level;
public:
	Pet();
	Pet(string _name, int _happiness, int satiation, int health_level, int _energy, int _level);
	void setName(string n);
	string getName();
	virtual void Feed() = 0;
	virtual void Sleep() = 0;
	virtual void Next_6hours() = 0;
	void Hunger();
	void Sad();
	void Ill();
	void death();
	void go_to_the_vet();
	void PetStatusAdjustment();
	int getHappiness();
	int getHealth_level();
	int getsatiation_level();
	int getEnergy();
	int getLevel();
	void levelUp();
};












#endif
