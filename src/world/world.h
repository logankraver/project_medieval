#ifndef WORLD_H
#define WORLD_H

#include "../person/person.h"
#include "../dice.h"
#include <random>
#include <vector>

class world {
    public:
        world();

        std::vector<person*> population;
        int day;
        dice world_dice;
        
        void initalize();
        void run();

};

#endif // !WORLD_H
