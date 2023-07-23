#include "farmer.h"
#include <climits>
#include <iostream>
#include "../dice.h"
#include "person.h"
#include <ncurses.h>

farmer::farmer() {
    farmed_goods = 0;
}

void farmer::farm(dice* dice_ptr) {
    farmed_goods += dice_ptr->roll(20);
    printw("We farmed! Total farmed goods: %d\n", farmed_goods);
}

void farmer::sell(int amt) {
    if (amt <= farmed_goods && amt > 0) {
        money += amt * 10;
        printw("Sold %d Goods\n", amt);
        farmed_goods -= amt;
    } else {
        printw("Not Enough In Inventory\n");
    }
}

void farmer::act(dice* dice_ptr) {
    farm(dice_ptr);
}
