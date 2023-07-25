#ifndef WORLD_H
#define WORLD_H

#include "../person/person.h"
#include "../person/merchant.h"
#include "../dice.h"
#include "chunk.h"
#include <random>
#include <string>
#include <vector>
#include <map>

class world {
    public:
        world();

        std::vector<person*> population;
        std::vector<merchant*> marketplace;
        std::vector<std::vector<chunk*> > map;
        std::map<std::string, int> color_map;
        int map_width;
        int map_height;
        int day;
        dice world_dice;
        
        int cursor_x;
        int cursor_y;
        
        void initalize(int width = 20, int height = 20);
        void run();

    private:
        void print_map();

};

#endif // !WORLD_H
