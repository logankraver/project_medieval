#include "farmer.h"
#include <climits>
#include <iostream>
#include "../dice.h"
#include "person.h"

farmer::farmer() {
    farmed_goods = 0;
}

void farmer::farm(dice* dice_ptr) {
    farmed_goods += dice_ptr->roll(20);
    std::cout << "We farmed! Total farmed goods: " << farmed_goods << "\n";
}

void farmer::sell(int amt) {
    if (amt <= farmed_goods && amt > 0) {
        money += amt * 10;
        std::cout << "Sold " << amt << " Goods\n";
        farmed_goods -= amt;
    } else {
        std::cout << "Not Enough In Inventory\n";
    }
}

void farmer::act(dice* dice_ptr) {
    farm(dice_ptr);
}
