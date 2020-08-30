#include "StormcloakSoldier.h"

#include <iostream>

StormcloakSoldier::~StormcloakSoldier() {
    std::cout << "Stormcloak soldier was deleted" << std::endl;
}

StormcloakSoldier::StormcloakSoldier(std::string &&name, int health) : Soldier(
    std::move(name), health) {
    std::cout << "Stormcloak soldier was created" << std::endl;
}
