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
    cbreak();
    noecho();
    start_color();
    keypad(stdscr, TRUE);

    if (has_colors()) {
        init_pair(1, COLOR_BLUE, COLOR_BLACK);
        init_pair(2, COLOR_GREEN, COLOR_BLACK);
        init_pair(3, COLOR_BLUE, COLOR_YELLOW);
        init_pair(4, COLOR_GREEN, COLOR_YELLOW);
        color_map["BLUE"] = COLOR_PAIR(1);
        color_map["GREEN"] = COLOR_PAIR(2);
        color_map["BLUE_SELECT"] = COLOR_PAIR(3);
        color_map["GREEN_SELECT"] = COLOR_PAIR(4);
    }

    day = 0;
    map_width = width;
    map_height = height;
    world_dice = dice();
    cursor_x = 0;
    cursor_y = 0;

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
    // people take action
    for (int i = 0; i < population.size(); i++) {
        if (farmer* farmer_ptr = dynamic_cast<farmer*>(population[i])) {
            farmer_ptr->act(&world_dice);
        } else {
            person curr_person = *population[i];
            curr_person.act(&world_dice);
        }
    }

    // handle user_input
    bool done = false;
    int ch;
    while (!done) {
        print_map();
        printw("Day %d\n", day);
        printw("Current Population: %d\n", population.size());
        printw("Current pos: %d %d\n", cursor_x, cursor_y);
        printw("Press 'y' to move onto next day...\n");

        ch = getch();
        if (ch == 'y') {
            done = true;
        } else if (ch == KEY_LEFT && cursor_x > 0) {
            cursor_x -= 1;
        } else if (ch == KEY_RIGHT && cursor_x < map_width-1) {
            cursor_x += 1;
        } else if (ch == KEY_UP && cursor_y > 0) {
            cursor_y -= 1;
        } else if (ch == KEY_DOWN && cursor_y < map_height-1) {
            cursor_y += 1;
        }
        refresh();
    }
    day += 1;
}

void world::print_map() {
    clear();
    for (int i = 0; i < map_height; i++) {
        for (int j = 0; j < map_width; j++) {
            // user position
            if (j == cursor_x && i == cursor_y) {
                map[i][j]->print(color_map, true);
            } else {
                map[i][j]->print(color_map);
            }
            printw(" ");
        }
        printw("\n");
    }
}
