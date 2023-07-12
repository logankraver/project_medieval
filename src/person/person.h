#ifndef PERSON_H
#define PERSON_H

#include "../dice.h"

class person {
    public:
        person();

        virtual void act(dice* dice_ptr);

        int health;
        int money;
        
};

#endif // !PERSON_H
