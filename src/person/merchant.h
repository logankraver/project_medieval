#ifndef MERCHANT_H
#define MERCHANT_H

#include "person.h"

class merchant : public person {
    public:
        merchant();

        void act(dice* dice_ptr) override;
        int store_goods;
        int price;
        void sell(int amt);
        void buy(int amt);
};

#endif // !MERCHANT_H
