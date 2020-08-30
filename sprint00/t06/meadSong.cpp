#include "meadSong.h"

void printGreaterZeroOrEqualOne(int bottles) {
    if (bottles == 1)
        std::cout << bottles << BOTTLE << bottles << BOTTLE_MEAD;
    else
        std::cout << bottles << BOTTLES << bottles << BOTTLES_MEAD;
    if (bottles > 1) {
        if (bottles == 2) {
            std::cout << TAKE_ONE_DOWN << bottles - 1 << BOTTLE_MEAD << std::endl;
        } else {
            std::cout << TAKE_ONE_DOWN << bottles - 1 << BOTTLES_MEAD << std::endl;
        }
    } else
        std::cout << NO_MORE_BOTTLES;
}

void printEqualZero() {
    std::cout << EQUAL_ZERO;
}
