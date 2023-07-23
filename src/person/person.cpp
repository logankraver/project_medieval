#include "person.h"
#include <iostream>
#include <random>
#include <ncurses.h>

person::person() {
    printw("Person Born...\n");
    std::cout << "Person Born...\n";
}

void person::act(dice* dice_ptr) { 
    printw("This is a test\n");
}

