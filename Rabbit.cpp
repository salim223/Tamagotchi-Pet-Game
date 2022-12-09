#include <iostream>
#include <string>
#include "Pet.h"
#include "Rabbit.h"


void Rabbit::digging()
{
    happiness += 1;
    energy -= 2;
    cout << endl;
    cout << name << " is digging in the backyard" << endl;
    PetStatusAdjustment();
}
void Rabbit::chewing_cardboard() 
{
    health_level -= 2;
    happiness += 2;
    energy -= 1;
    PetStatusAdjustment();
    cout << endl;
    cout << name << " is chewing a cardboard..." << endl;
}
void Rabbit::cleanEars()
{
    cout << endl;
    happiness += 1;
    PetStatusAdjustment();
    cout << endl;
    cout << "You are cleaning " << name << "'s ears";
}
void Rabbit::Feed()
{
    energy += 2;
    health_level += 1;
    happiness += 2;
    PetStatusAdjustment();
    cout << endl;
    cout << name << " is eating... \"hum.. hum...\"" << endl;
}
void Rabbit::Sleep()
{
    energy += 2;
    health_level += 2;
    happiness += 1;
    cout << name << " is sleeping...  \"zzzzz...\"" << endl;
    PetStatusAdjustment();
}
void Rabbit::Next_6hours()
{
    satiation_level -= 2;
    energy -= 3;
    health_level -= 3;
    happiness -= 3;
    cout << endl;
    cout << "6 hours passed... " << endl;
    PetStatusAdjustment();

}
void Rabbit::rabbitFace()
{
    cout << "         ((`\\" << endl;
    cout << "      ___ \\\\ '--._" << endl;
    cout << "   .'`   `'    o  )" << endl;
    cout << "  /    \\   '. __.'" << endl;
    cout << " _|    /_  \\ \\_\\_" << endl;
    cout << "{_\\______\\-'\\__\\_\\" << endl;
}
void Rabbit::rabbitMenu()
{
    cout << "|" << name << "|" << " |Happiness: " << happiness << "| |Satiation Level: " << satiation_level;
    cout << "| |Energy: " << energy << "| |Health Level: " << health_level <<"| |Level: " << level <<"|" << endl;
    rabbitFace();
}
void Rabbit::rabbitInteractions()
{
    cout << "1 - Feed your rabbit" << endl;
    cout << "2 - Bring your rabbit to sleep" << endl;
    cout << "3 - Let your rabbit go dig" << endl;
    cout << "4 - Let your rabbit chew cardboards" << endl;
    cout << "5 - Clean your rabbit ears" << endl;
    cout << "6 - Go see the vet" << endl;
    cout << "7 - Save and exit the game" << endl;    
    cout << endl;
}
