#include "dice.h"
#include <random>

dice::dice() : dist(1,600) {
    std::random_device rd;
    std::mt19937 rng(rd());
}

int dice::roll(int d) {
    return dist(rng) % d + 1;
}

