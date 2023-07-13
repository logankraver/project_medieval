#include "world.h"
#include "../person/person.h"
#include "../person/farmer.h"
#include "../person/merchant.h"
#include <iostream>
#include <random>
#include <vector>

// ANSI color codes
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

world::world() {}

void world::initalize(int width, int height) {
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
    map = std::vector<std::vector<char> >(map_height, std::vector<char>(map_width, 'e'));
    for (int i = 0; i < map_height; i++) {
        for (int j = 0; j < map_width; j++) {
            // border is water, otherwise land
            if (i == 0 || j == 0 || i == map_height - 1 || j == map_width - 1) {
                map[i][j] = '0';
            } else {
                map[i][j] = '1';
            }
        }
    }
}

void world::run() {
    print_map();
    std::string dummy;
    std::cout << "Day " << day << "\n";
    std::cout << "Current Population: " << population.size() << "\n";
    std::cout << "Move onto next day?";
    std::cin >> dummy;

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
}

void world::print_map() {
    for (int i = 0; i < map_height; i++) {
        for (int j = 0; j < map_width; j++) {
            if (map[i][j] == '0') {
                std::cout << BLUE << map[i][j] << RESET;
            } else if (map[i][j] == '1') {
                std::cout << GREEN << map[i][j] << RESET;
            } else {
                std::cout << RED << map[i][j] << RESET;
            }
            std::cout << " ";
        }
        std::cout << "\n";
    }
}
