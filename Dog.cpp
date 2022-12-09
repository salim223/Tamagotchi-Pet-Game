#include <iostream>
#include <string>
#include "Pet.h"
#include "Dog.h"
using namespace std;


void Dog::play_hide_and_seek()
{
    happiness += 4;
    energy -= 2;
    PetStatusAdjustment();
    cout << endl;
    cout << "You are playing hide and seek with " << name << "..." << endl;
}
void Dog::play_ball() {
    satiation_level -= 2;
    energy -= 3;
    happiness += 5;
    PetStatusAdjustment();
    cout << endl;
    cout << name << " is playing with a ball..." << endl;
}
void Dog::petDog()
{
    happiness += 3;
}
void Dog::Feed()
{
    cout << name << " is eating... \"Chewing meat...\"" << endl;
    energy += 5;
    satiation_level += 2;
    health_level += 1;
    happiness +=2;
}
void Dog::Sleep()
{
    energy += 5;
    health_level += 2;
    happiness += 2;
    satiation_level -= 2;
    PetStatusAdjustment();
    cout << endl;
    cout << name << " is sleeping..." << endl;
}
void Dog::Next_6hours()
{
    satiation_level -= 2;
    energy -= 2;
    health_level -= 1;
    happiness -= 2;
    PetStatusAdjustment();
    cout << endl;
    cout << "6 hours passed... " << endl;
}
void Dog::dogFace()
{
    cout <<"  ___    ___" << endl;
    cout <<" / / \\__/ \\ \\" << endl;
    cout <<" \\/| /\\/\\ |\\/" << endl;
    cout <<"  _||o o ||_" << endl;
    cout <<" /. .\\__/. .\\" << endl;
    cout <<"/ . .(__) . .\\" << endl;
    cout <<"\\ .  /__\\  . /" << endl;
    cout <<" \\__/\\__/\\__/" << endl;

}
void Dog::dogMenu()
{
    cout <<"|" << name <<"|"<< " |Happiness: " << happiness << "| |Satiation Level: " << satiation_level;
    cout << "| |Energy: " << energy << "| |Health Level: " << health_level << "| |Level: " << level << "|" << endl;
    dogFace();
}
void Dog::dogInteractions()
{
    cout << "1 - Feed your dog" << endl;
    cout << "2 - Bring your dog to sleep" << endl;
    cout << "3 - Play ball with your dog" << endl;
    cout << "4 - Play hide and seek with your dog" << endl;
    cout << "5 - Pet your dog" << endl;
    cout << "6 - Go see the vet" << endl;
    cout << "7 - Save and exit the game" << endl;    
    cout << endl;
}