#include <iostream>
#include "world/world.h"
#include <ncurses.h>

int main (int argc, char *argv[]) {
    initscr();
    start_color();
    world controller = world();
    controller.initalize();
    for (int i = 0; i < 10; i++) {
        controller.run();
    }
    endwin();
    
    return 0;
}


