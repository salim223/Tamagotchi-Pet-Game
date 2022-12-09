#include <iostream>
#include <string>
#include "Pet.h"
#include "Cat.h"
using namespace std;


void Cat::talk_to_cat()
{
    happiness += 2;
    PetStatusAdjustment();
    cout << endl;
    cout << "Petting and talking to "<< name <<"..." << endl;
}
void Cat::hunting() 
{
    satiation_level -= 2;
    energy -= 2;
    happiness += 2;
    PetStatusAdjustment();
    cout << endl;
    cout << name << " is hunting in the backyard..." << endl;
}
void Cat::Brushcat()
{
    happiness += 2;
    PetStatusAdjustment();
    cout << endl;
    cout << "You are brushing " << name << endl;
}
void Cat::catFace()
{
    cout << "      ,_     _," << endl;
    cout << "      |\\\\___//|" << endl;
    cout << "      |=6   6=|" << endl;
    cout << "      \\=._Y_.=/" << endl;
    cout << "       )  `  (    ," << endl;
    cout << "      /       \\  ((" << endl;
    cout << "      |       |   ))" << endl;
    cout << "     /| |   | |\\_//" << endl;
    cout << "jgs  \\| |._.| |/-`" << endl;
    cout << "      '\"'   '\"'" << endl;

}
void Cat::catMenu()
{
    cout << "|" << name << "|" << " |Happiness: " << happiness << "| |Satiation Level: " << satiation_level;
    cout << "| |Energy: " << energy << "| |Health Level: " << health_level << "| |Level: " << level << "|" << endl;
    catFace();
}
void Cat::Feed () 
{
    energy += 3;
    satiation_level += 5;
    health_level += 1;
    happiness += 2;
    PetStatusAdjustment();
    cout << endl;
    cout << name << " is eating \"nom...nom...\"" << endl;
}
void Cat::Sleep()
{
    energy += 2;
    health_level += 2;
    happiness -= 2;
    satiation_level -= 1;
    PetStatusAdjustment();
    cout << endl;
    cout << name << " is sleeping...  \"mrrr..mrrr...\"" << endl;
}
void Cat::Next_6hours()
{
    satiation_level -= 1;
    energy -= 2;
    health_level -= 1;
    happiness -= 1;
    PetStatusAdjustment();
    cout << endl;
    cout << "6 hours passed... " << endl;
}
void Cat::catInteractions()
{
    cout << "1 - Feed your cat" << endl;
    cout << "2 - Bring your pet to sleep" << endl;
    cout << "3 - talk to your cat" << endl;
    cout << "4 - Make your cat go hunting outside" << endl;
    cout << "5 - Brush your cat" << endl;
    cout << "6 - Go see the vet" << endl;
    cout << "7 - Save and exit the game" << endl;    
    cout << endl;
}
