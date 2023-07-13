#include "merchant.h"
#include <iostream>

merchant::merchant() {
    store_goods = 0;
    price = 0;
}

void merchant::sell(int amt) {
    if (amt <= store_goods) {
        money += amt * price;
        store_goods -= amt;
    } else {
        std::cout << "Not enough goods to sell\n";
    }
}

void merchant::buy(int amt) {
    if (amt * price <= money) {
        money -= amt * price;
        store_goods += amt;
    } else {
        std::cout << "Not enough money to buy\n";
    }
}

void merchant::act(dice* dice_ptr) {

}
