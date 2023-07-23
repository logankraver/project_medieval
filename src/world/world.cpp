#include "world.h"
#include "../person/person.h"
#include "../person/farmer.h"
#include "../person/merchant.h"
#include "chunk.h"
#include <iostream>
#include <random>
#include <vector>
#include <ncurses.h>

world::world() {}

void world::initalize(int width, int height) {
    initscr();
    start_color();

    if (has_colors()) {
        init_pair(1, COLOR_BLUE, COLOR_BLACK);
        init_pair(2, COLOR_GREEN, COLOR_BLACK);
    }

    day = 0;
    map_width = width;
    map_height = height;
    world_dice = dice();

    // initalize population
    for (int i = 0; i < 10; i++) {
        farmer* temp = new farmer();
        population.push_back(temp);
    }

    // initalize map
    map = std::vector<std::vector<chunk*> >(map_height, std::vector<chunk*>(map_width));
    for (int i = 0; i < map_height; i++) {
        for (int j = 0; j < map_width; j++) {
            // border is water, otherwise land
            if (i == 0 || j == 0 || i == map_height - 1 || j == map_width - 1) {
                chunk* temp = new chunk('0', i, j);
                map[i][j] = temp;
            } else {
                chunk* temp = new chunk('1', i, j);
                map[i][j] = temp;
            }
        }
    }
}

void world::run() {
    print_map();
    printw("Day %d\n", day);
    printw("Current Population: %d\n", population.size());
    printw("Move onto next day?\n");

    // people take action
    for (int i = 0; i < population.size(); i++) {
        if (farmer* farmer_ptr = dynamic_cast<farmer*>(population[i])) {
            farmer_ptr->act(&world_dice);
        } else {
            person curr_person = *population[i];
            curr_person.act(&world_dice);
        }
    }

    day += 1;
    refresh();
    getch();
}

void world::print_map() {
    clear();
    for (int i = 0; i < map_height; i++) {
        for (int j = 0; j < map_width; j++) {
            if (map[i][j]->biome == '0') {
                attron(COLOR_PAIR(1));
                printw("%c", map[i][j]->biome);
                attroff(COLOR_PAIR(1));
            } else if (map[i][j]->biome == '1') {
                attron(COLOR_PAIR(2));
                printw("%c", map[i][j]->biome);
                attroff(COLOR_PAIR(2));
            } else {
                printw("%c", map[i][j]->biome);
            }
            printw(" ");
        }
        printw("\n");
    }
}
