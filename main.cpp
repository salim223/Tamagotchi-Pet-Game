#include <iostream>
#include <fstream>
#include <string>
#include "Dog.h"
#include "Cat.h"
#include "Rabbit.h"

using namespace std;

void Intro ()
{
cout << " _____                                  _       _     _     ___     _       ___                     " << endl;
cout << "/__   \\__ _ _ __ ___   __ _  __ _  ___ | |_ ___| |__ (_)   / _ \\___| |_    / _ \\__ _ _ __ ___   ___ " << endl;
cout << "  / /\\/ _` | '_ ` _ \\ / _` |/ _` |/ _ \\| __/ __| '_ \| |  / /_)/ _ \\ __|  / /_\\/ _` | '_ ` _ \\ / _ \\" << endl;
cout << " / / | (_| | | | | | | (_| | (_| | (_) | || (__| | | | | / ___/  __/ |_  / /_\\\\ (_| | | | | | |  __/" << endl;
cout << " \\/   \\__,_|_| |_| |_|\\__,_|\\__, |\\___/ \\__\\___|_| |_|_| \\/    \\___|\\__| \\____/\\__,_|_| |_| |_|\\___|" << endl;
cout << "                            |___/                                                                   " << endl;
cout << "                                       Please make a selection:                                                  " << endl;
cout << "                                       1) Load a saved Pet                                                       " << endl;
cout << "                                       2) Create a new Pet                                                       " << endl;
cout << "                                       3) quit                                                                   " << endl;
}
void petSelection()
{
    cout << "Choose your pet's type: " << endl;
    cout << "        1) Dog          " << endl;
    cout << "        2) Cat          " << endl;
    cout << "        3) Rabbit       " << endl;
}
string nameText(string n)
{
    return n + ".txt";
}


int main()
{
    //To save name
    string saved_name = "";
    int saved_happiness = 0, saved_satiation = 0, saved_health = 0, saved_energy = 0, saved_level = 0;
    //To Load name
    string load_name = "";
    int load_happiness = 0, load_satiation = 0, load_health = 0, load_energy = 0, load_level = 0;

    ifstream Load;
    ofstream save;
    string Lname;
    string pet_Type;
    bool is_dead = false;
    bool played = false;

    int counter = 0;
    int introSelection;
    int petTypeSelection;
    

    Intro();
    cin >> introSelection;

    while (introSelection != 1 && introSelection != 2 && introSelection != 3)
    {
        cout << "You made the wrong choice !" << endl;
        cout << "Re-enter selection: " << endl;
        cout << "1) Load a saved Pet" << endl;
        cout << "2) Create a new Pet" << endl;
        cout << "3) quit" << endl;
        cin >> introSelection;
    }
    switch (introSelection)
    {
    case 1:
        cout << "Please enter the pet name: " << endl;
        cin >> Lname;
        cout << "Please enter the pet type: " << endl;
        cout << "Dog, Cat, Rabbit" << endl;
        cin >> pet_Type;
        Lname = nameText(Lname);
        Load.open(Lname);
        if(!Load.is_open()) 
        {
            cout << "File does not exist !!" << endl;
            cout << "Please re-enter the pet name or enter \"q\" to quit : " << endl;
            cin >> Lname;
            while (!Load.is_open() && Lname != "q")
            {
                cout << "File does not exist !!" << endl;
                cout << "Please re-enter the pet name or enter \"q\" to quit : " << endl;
                cin >> Lname;
            }
        }
        if (Lname == "q")
        {
            introSelection = 3;
        }
        else if (Load.is_open())
        {
            if (pet_Type == "Dog")
            {
                played = true;
                int intera_selection;
                Load >> load_name >> load_happiness >> load_satiation >> load_health >> load_energy >> load_level;
                Dog dog(load_name, load_happiness, load_satiation, load_health, load_energy, load_level);
                Load.close();
                dog.dogMenu();
                dog.dogInteractions();
                cin >> intera_selection;
                while (intera_selection != 1 && intera_selection != 2 && intera_selection != 3 &&
                    intera_selection != 4 && intera_selection != 5 && intera_selection != 6 && intera_selection != 7)
                {
                    cout << "You made the wrong choice !" << endl;
                    dog.dogInteractions();
                    cin >> intera_selection;
                }
                while (intera_selection != 7)
                {
                    cout << endl;
                    if (intera_selection == 1)
                    {
                        dog.Feed();
                        dog.Sad();
                        dog.Ill();
                        dog.Hunger();
                        dog.PetStatusAdjustment();
                    }
                    else if (intera_selection == 2)
                    {
                        dog.Sleep();
                        dog.Sad();
                        dog.Ill();
                        dog.Hunger();
                        dog.PetStatusAdjustment();
                    }
                    else if (intera_selection == 3)
                    {
                        dog.play_ball();
                        dog.Sad();
                        dog.Ill();
                        dog.Hunger();
                        dog.PetStatusAdjustment();
                    }
                    else if (intera_selection == 4)
                    {
                        dog.play_hide_and_seek();
                        dog.Sad();
                        dog.Ill();
                        dog.Hunger();
                        dog.PetStatusAdjustment();
                    }
                    else if (intera_selection == 5)
                    {
                        dog.petDog();
                        dog.Sad();
                        dog.Ill();
                        dog.Hunger();
                        dog.PetStatusAdjustment();
                    }
                    else if (intera_selection == 6)
                    {
                        dog.go_to_the_vet();
                    }
                    cout << endl;
                    counter++;
                    if (counter == 3)
                    {
                        dog.Next_6hours();
                        counter = 0;
                        if (dog.getHealth_level() > 4)
                        {
                            dog.levelUp();
                        }
                    }
                    if (dog.getHealth_level() == 0)
                    {
                        is_dead = true;
                        dog.dogMenu();
                        dog.death();
                        intera_selection = 7;
                        break;
                    }
                    dog.dogMenu();
                    dog.dogInteractions();
                    cin >> intera_selection;
                }
                if (intera_selection == 7 )
                {
                    cout << "You exited the game" << endl;
                    if (!is_dead)
                    {
                        saved_name = dog.getName();
                        saved_happiness = dog.getHappiness();
                        saved_satiation = dog.getsatiation_level();
                        saved_health = dog.getHealth_level();
                        saved_energy = dog.getEnergy();
                        saved_level = dog.getLevel();
                        save.open(nameText(saved_name));
                        save << saved_name << endl;
                        save << saved_happiness << endl;
                        save << saved_satiation << endl;
                        save << saved_health << endl;
                        save << saved_energy << endl;
                        save << saved_level << endl;
                        save.close();
                    }
                    break;
                }
                break;
            }
            else if (pet_Type == "Cat")
            {
                played = true;
                int intera_selection;
                Load >> load_name >> load_happiness >> load_satiation >> load_health >> load_energy >> load_level;
                Cat cat(load_name, load_happiness, load_satiation, load_health, load_energy, load_level);
                Load.close();
                cat.catMenu();
                cat.catInteractions();
                cin >> intera_selection;
                while (intera_selection != 1 && intera_selection != 2 && intera_selection != 3 &&
                    intera_selection != 4 && intera_selection != 5 && intera_selection != 6 && intera_selection != 7)
                {
                    cout << "You made the wrong choice !" << endl;
                    cat.catInteractions();
                    cin >> intera_selection;
                }
                while (intera_selection != 7)
                {
                    if (intera_selection == 1)
                    {
                        cat.Feed();
                        cat.Sad();
                        cat.Ill();
                        cat.Hunger();
                        cat.PetStatusAdjustment();
                    }
                    else if (intera_selection == 2)
                    {
                        cat.Sleep();
                        cat.Sad();
                        cat.Ill();
                        cat.Hunger();
                        cat.PetStatusAdjustment();
                    }
                    else if (intera_selection == 3)
                    {
                        cat.talk_to_cat();
                        cat.Sad();
                        cat.Ill();
                        cat.Hunger();
                        cat.PetStatusAdjustment();
                    }
                    else if (intera_selection == 4)
                    {
                        cat.hunting();
                        cat.Sad();
                        cat.Ill();
                        cat.Hunger();
                        cat.PetStatusAdjustment();
                    }
                    else if (intera_selection == 5)
                    {
                        cat.Brushcat();
                        cat.Sad();
                        cat.Ill();
                        cat.Hunger();
                        cat.PetStatusAdjustment();
                    }
                    else if (intera_selection == 6)
                    {
                        cat.go_to_the_vet();
                        cat.Sad();
                        cat.Ill();
                        cat.Hunger();
                        cat.PetStatusAdjustment();
                    }               
                    cout << endl;
                    counter++;
                    if (counter == 3)
                    {
                        cat.Next_6hours();
                        counter = 0;
                        if (cat.getHealth_level() > 4)
                        {
                            cat.levelUp();
                        }
                    }
                    if (cat.getHealth_level() == 0)
                    {
                        is_dead = true;
                        cat.catMenu();
                        cat.death();
                        intera_selection = 7;
                        break;
                    }
                    cat.catMenu();
                    cat.catInteractions();
                    cin >> intera_selection;           
                }
                if (intera_selection == 7)
                {
                    cout << "You exited the game" << endl;
                    if (!is_dead)
                    {
                        saved_name = cat.getName();
                        saved_happiness = cat.getHappiness();
                        saved_satiation = cat.getsatiation_level();
                        saved_health = cat.getHealth_level();
                        saved_energy = cat.getEnergy();
                        saved_level = cat.getLevel();
                        save.open(nameText(saved_name));
                        save << saved_name << endl;
                        save << saved_happiness << endl;
                        save << saved_satiation << endl;
                        save << saved_health << endl;
                        save << saved_energy << endl;
                        save << saved_level << endl;
                        save.close();
                    }
                    break;
                }
                break;
            }
            else if (pet_Type == "Rabbit")
            {
                played = true;
                int intera_selection;
                Load >> load_name >> load_happiness >> load_satiation >> load_health >> load_energy >> load_level;
                Rabbit rabbit(load_name, load_happiness, load_satiation, load_health, load_energy, load_level);
                Load.close();
                rabbit.rabbitMenu();
                rabbit.rabbitInteractions();
                cin >> intera_selection;
                while (intera_selection != 1 && intera_selection != 2 && intera_selection != 3 &&
                    intera_selection != 4 && intera_selection != 5 && intera_selection != 6 && intera_selection != 7)
                {
                    cout << "You made the wrong choice !" << endl;
                    rabbit.rabbitInteractions();
                    cin >> intera_selection;
                }
                while (intera_selection != 7)
                {
                    if (intera_selection == 1)
                    {
                        rabbit.Feed();
                        rabbit.Sad();
                        rabbit.Ill();
                        rabbit.Hunger();
                        rabbit.PetStatusAdjustment();
                    }
                    else if (intera_selection == 2)
                    {
                        rabbit.Sleep();
                        rabbit.Sad();
                        rabbit.Ill();
                        rabbit.Hunger();
                        rabbit.PetStatusAdjustment();
                    }
                    else if (intera_selection == 3)
                    {
                        rabbit.digging();
                        rabbit.Sad();
                        rabbit.Ill();
                        rabbit.Hunger();
                        rabbit.PetStatusAdjustment();
                    }
                    else if (intera_selection == 4)
                    {
                        rabbit.chewing_cardboard();
                        rabbit.Sad();
                        rabbit.Ill();
                        rabbit.Hunger();
                        rabbit.PetStatusAdjustment();
                    }
                    else if (intera_selection == 5)
                    {
                        rabbit.cleanEars();
                        rabbit.Sad();
                        rabbit.Ill();
                        rabbit.Hunger();
                        rabbit.PetStatusAdjustment();
                    }
                    else if (intera_selection == 6)
                    {
                        rabbit.go_to_the_vet();
                    }
                    cout << endl;
                    counter++;
                    if (counter == 3)
                    {
                        rabbit.Next_6hours();
                        counter = 0;
                        if (rabbit.getHealth_level() > 4)
                        {
                            rabbit.levelUp();
                        }
                    }
                    if (rabbit.getHealth_level() == 0)
                    {
                        is_dead = true;
                        rabbit.rabbitMenu();
                        rabbit.death();
                        intera_selection = 7;
                        break;
                    }
                    rabbit.rabbitMenu();
                    rabbit.rabbitInteractions();
                    cin >> intera_selection;
                }
                if (intera_selection == 7)
                {
                    cout << "You exited the game" << endl;
                    if (!is_dead)
                    {
                        saved_name = rabbit.getName();
                        saved_happiness = rabbit.getHappiness();
                        saved_satiation = rabbit.getsatiation_level();
                        saved_health = rabbit.getHealth_level();
                        saved_energy = rabbit.getEnergy();
                        saved_level = rabbit.getLevel();
                        save.open(nameText(saved_name));
                        save << saved_name << endl;
                        save << saved_happiness << endl;
                        save << saved_satiation << endl;
                        save << saved_health << endl;
                        save << saved_energy << endl;
                        save << saved_level << endl;
                        save.close();
                    }
                    break;
                }
                break;
            }
            else 
            {
            cout << "That pet does not exist" << endl;
            }
        }
        break;

    case 2:
        petSelection();
        cin >> petTypeSelection;
        while (petTypeSelection != 1 && petTypeSelection != 2 && petTypeSelection != 3)
        {
            cout << "You made the wrong choice !" << endl;
            petSelection();
            cin >> petTypeSelection;
        }
        if (petTypeSelection == 1)
        {
            int intera_selection;
            string name;
            cout << "Please enter dog name: ";
            cin >> name;
            Dog dog(name, 6, 6, 6, 6, 0);
            dog.dogMenu();
            dog.dogInteractions();
            cin >> intera_selection;
            while (intera_selection != 1 && intera_selection != 2 && intera_selection != 3 && 
                   intera_selection != 4 && intera_selection != 5 && intera_selection != 6 && intera_selection != 7)
            {
                cout << "You made the wrong choice !" << endl;
                dog.dogInteractions();
                cin >> intera_selection;
            }
            played = true;
            while (intera_selection != 7)
            {
                if (intera_selection == 1)
                {
                    dog.Feed();
                    dog.Sad();
                    dog.Ill();
                    dog.Hunger();
                    dog.PetStatusAdjustment();
                }
                else if (intera_selection == 2)
                {
                    dog.Sleep();
                    dog.Sad();
                    dog.Ill();
                    dog.Hunger();
                    dog.PetStatusAdjustment();
                }
                else if (intera_selection == 3)
                {
                    dog.play_ball();
                    dog.Sad();
                    dog.Ill();
                    dog.Hunger();
                    dog.PetStatusAdjustment();
                }
                else if (intera_selection == 4)
                {
                    dog.play_hide_and_seek();
                    dog.Sad();
                    dog.Ill();
                    dog.Hunger();
                    dog.PetStatusAdjustment();
                }
                else if (intera_selection == 5)
                {
                    dog.petDog();
                    dog.Sad();
                    dog.Ill();
                    dog.Hunger();
                    dog.PetStatusAdjustment();
                }
                else if (intera_selection == 6)
                {
                    dog.go_to_the_vet();
                }
                cout << endl;
                counter++;
                if (counter == 3)
                {
                    dog.Next_6hours();
                    counter = 0;
                    if (dog.getHealth_level() > 4)
                    {
                        dog.levelUp();
                    }
                }
                if (dog.getHealth_level() == 0)
                {
                    is_dead = true;
                    dog.dogMenu();
                    dog.death();
                    intera_selection = 7;
                    break;
                }
                dog.dogMenu();
                dog.dogInteractions();
                cin >> intera_selection;
            }
            if (intera_selection == 7)
            {
                saved_name = dog.getName();
                saved_happiness = dog.getHappiness();
                saved_satiation = dog.getsatiation_level();
                saved_health = dog.getHealth_level();
                saved_energy = dog.getEnergy();
                saved_level = dog.getLevel();
                introSelection = 3;
            }
            
        }
        else if (petTypeSelection == 2)
        {
            int intera_selection = 0;
            string name;
            cout << "Please enter cat name: ";
            cin >> name;
            Cat cat(name, 6, 6, 6, 6, 0);
            cat.catMenu();
            cat.catInteractions();
            cin >> intera_selection;
            while (intera_selection != 1 && intera_selection != 2 && intera_selection != 3 &&
                intera_selection != 4 && intera_selection != 5 && intera_selection != 6 && intera_selection != 7)
            {
                cout << "You made the wrong choice !" << endl;
                cat.catInteractions();
                cin >> intera_selection;
            }
            played = true;
            while (intera_selection != 7)
            {
                if (intera_selection == 1)
                {
                    cat.Feed();
                    cat.Sad();
                    cat.Ill();
                    cat.Hunger();
                    cat.PetStatusAdjustment();
                }
                else if (intera_selection == 2)
                {
                    cat.Sleep();
                    cat.Sad();
                    cat.Ill();
                    cat.Hunger();
                    cat.PetStatusAdjustment();
                }
                else if (intera_selection == 3)
                {
                    cat.talk_to_cat();
                    cat.Sad();
                    cat.Ill();
                    cat.Hunger();
                    cat.PetStatusAdjustment();
                }
                else if (intera_selection == 4)
                {
                    cat.hunting();
                    cat.Sad();
                    cat.Ill();
                    cat.Hunger();
                    cat.PetStatusAdjustment();
                }
                else if (intera_selection == 5)
                {
                    cat.Brushcat();
                    cat.Sad();
                    cat.Ill();
                    cat.Hunger();
                    cat.PetStatusAdjustment();
                }
                else if (intera_selection == 6)
                {
                    cat.hunting();
                    cat.Sad();
                    cat.Ill();
                    cat.Hunger();
                    cat.PetStatusAdjustment();
                }
                cout << endl;
                counter++;
                if (counter == 3)
                {
                    cat.Next_6hours();
                    counter = 0;
                    if (cat.getHealth_level() > 4)
                    {
                        cat.levelUp();
                    }
                }
                if (cat.getHealth_level() == 0)
                {
                    is_dead = true;
                    cat.catMenu();
                    cat.death();
                    intera_selection = 7;
                    break;
                }
                cat.catMenu();
                cat.catInteractions();
                cin >> intera_selection;
            }
            if (intera_selection == 7)
            {
                saved_name = cat.getName();
                saved_happiness = cat.getHappiness();
                saved_satiation = cat.getsatiation_level();
                saved_health = cat.getHealth_level();
                saved_energy = cat.getEnergy();
                saved_level = cat.getLevel();
                introSelection = 3;
            }
        }
        else if (petTypeSelection == 3)
        {
            int intera_selection = 0;
            string name;
            cout << "Please enter rabbit name: ";
            cin >> name;
            Rabbit rabbit(name, 6, 6, 6, 6, 0);
            rabbit.rabbitMenu();
            rabbit.rabbitInteractions();
            cin >> intera_selection;
            while (intera_selection != 1 && intera_selection != 2 && intera_selection != 3 &&
                intera_selection != 4 && intera_selection != 5 && intera_selection != 6 && intera_selection != 7)
            {
                cout << "You made the wrong choice !" << endl;
                rabbit.rabbitInteractions();
                cin >> intera_selection;
            }
            played = true;
            while (intera_selection != 7)
            {
                if (intera_selection == 1)
                {
                    rabbit.Feed();
                    rabbit.Sad();
                    rabbit.Ill();
                    rabbit.Hunger();
                    rabbit.PetStatusAdjustment();
                }
                else if (intera_selection == 2)
                {
                    rabbit.Sleep();
                    rabbit.Sad();
                    rabbit.Ill();
                    rabbit.Hunger();
                    rabbit.PetStatusAdjustment();
                }
                else if (intera_selection == 3)
                {
                    rabbit.digging();
                    rabbit.Sad();
                    rabbit.Ill();
                    rabbit.Hunger();
                    rabbit.PetStatusAdjustment();
                }
                else if (intera_selection == 4)
                {
                    rabbit.chewing_cardboard();
                    rabbit.Sad();
                    rabbit.Ill();
                    rabbit.Hunger();
                    rabbit.PetStatusAdjustment();
                }
                else if (intera_selection == 5)
                {
                    rabbit.cleanEars();
                    rabbit.Sad();
                    rabbit.Ill();
                    rabbit.Hunger();
                    rabbit.PetStatusAdjustment();
                }
                else if (intera_selection == 6)
                {
                    rabbit.go_to_the_vet();
                }
                cout << endl;
                counter++;
                if (counter == 3)
                {
                    rabbit.Next_6hours();
                    counter = 0;
                    if (rabbit.getHealth_level() > 4)
                    {
                        rabbit.levelUp();
                    }
                }
                if (rabbit.getHealth_level() == 0)
                {
                    is_dead = true;
                    rabbit.rabbitMenu();
                    rabbit.death();
                    intera_selection = 7;
                    break;
                }
                rabbit.rabbitMenu();
                rabbit.rabbitInteractions();
                cin >> intera_selection;
            }
            if (intera_selection == 7)
            {
                saved_name = rabbit.getName();
                saved_happiness = rabbit.getHappiness();
                saved_satiation = rabbit.getsatiation_level();
                saved_health = rabbit.getHealth_level();
                saved_energy = rabbit.getEnergy();
                saved_level = rabbit.getLevel();
                introSelection = 3;
            }
        }
    case 3:
        cout << "You exited the game." << endl;
        if (!is_dead && played)
        {
            save.open(nameText(saved_name));
            save << saved_name << endl; 
            save << saved_happiness << endl; 
            save << saved_satiation << endl;
            save << saved_health << endl;
            save << saved_energy << endl;
            save << saved_level << endl;
            save.close();
        }
        break;
    }
    
}

