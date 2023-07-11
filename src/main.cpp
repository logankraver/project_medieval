#include <iostream>
#include "world/world.h"

int main (int argc, char *argv[]) {
    std::cout << "Hello World\n";

    world controller = world();
    controller.initalize();
    for (int i = 0; i < 10; i++) {
        controller.run();
    }
    
    return 0;
}


