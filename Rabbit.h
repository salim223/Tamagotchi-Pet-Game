#include <iostream>
#include "Pet.h"
using namespace std;

#ifndef RABBIT_H
#define RABBIT_H

class Rabbit : public Pet
{
public:
    using Pet::Pet;
    void digging();
    void chewing_cardboard();
    void cleanEars();
    void Feed();
    void Sleep();
    void Next_6hours();
    void rabbitFace();
    void rabbitMenu();
    void rabbitInteractions();

};





#endif
