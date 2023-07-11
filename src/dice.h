#ifndef DICE_H
#define DICE_H

#include <random>

class dice {
    public:
        dice();

        int roll(int d = 100);
        
    private:
        std::mt19937 rng;
        std::uniform_int_distribution<int> dist;
};

#endif // !DICE_H
