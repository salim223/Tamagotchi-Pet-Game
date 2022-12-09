#include <iostream>
#include "Pet.h"

using namespace std;

#ifndef CAT_H
#define CAT_H

class Cat : public Pet
{
public:
    using Pet::Pet;
    void talk_to_cat();
    void hunting();
    void Brushcat();
    void catMenu();
    void catFace();
    void Feed();
    void Sleep();
    void Next_6hours();
    void catInteractions();
};












#endif
