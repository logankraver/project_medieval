#ifndef FARMER_H
#define FARMER_H

#include "person.h"

class farmer : public person {
    public:
        farmer();

        int farmed_goods;

        void act(dice* dice_ptr) override;
        void set_farmed_goods(int f);
        void farm(dice* dice_ptr);
        void sell(int amt);
};

#endif // !FARMER_H
