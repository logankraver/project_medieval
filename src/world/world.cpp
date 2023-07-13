#include "world.h"
#include "../person/person.h"
#include "../person/farmer.h"
#include "../person/merchant.h"
#include <iostream>
#include <random>

world::world() {}

void world::initalize() {
    day = 0;
    world_dice = dice();
    for (int i = 0; i < 10; i++) {
        farmer* temp = new farmer();
        population.push_back(temp);
    }
}

void world::run() {
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
