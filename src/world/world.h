#ifndef WORLD_H
#define WORLD_H

#include "../person/person.h"
#include "../person/merchant.h"
#include "../dice.h"
#include <random>
#include <vector>

class world {
    public:
        world();

        std::vector<person*> population;
        std::vector<merchant*> marketplace;
        std::vector<std::vector<char> > map;
        int map_width;
        int map_height;
        int day;
        dice world_dice;
        
        void initalize(int width = 40, int height = 40);
        void run();

    private:
        void print_map();

};

#endif // !WORLD_H
