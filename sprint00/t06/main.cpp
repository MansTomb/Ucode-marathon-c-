#include "meadSong.h"

int main() {
    int bottles = 99;

    while (bottles > -1) {
        if (bottles > 0)
            printGreaterZeroOrEqualOne(bottles);
        else
            printEqualZero();
        bottles--;
    }
}