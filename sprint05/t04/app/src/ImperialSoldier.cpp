#include "ImperialSoldier.h"

#include <iostream>

ImperialSoldier::~ImperialSoldier() {
    std::cout << "Imperial soldier was deleted" << std::endl;
}

ImperialSoldier::ImperialSoldier(std::string &&name, int health) : Soldier(
    std::move(name), health) {
    std::cout << "Imperial soldier was created" << std::endl;
}

