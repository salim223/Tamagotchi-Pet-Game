#include <iostream>
#include "Pet.h"
using namespace std;

#ifndef DOG_H
#define DOG_H

class Dog : public Pet
{
public:
    using Pet::Pet;
    void petDog();
    void play_hide_and_seek();
    void play_ball();
    void Feed();
    void Sleep();
    void Next_6hours();
    void dogFace();
    void dogMenu();
    void dogInteractions();

};













#endif
