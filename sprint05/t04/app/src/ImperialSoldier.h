#pragma once

#include "Soldier.h"
#include "StormcloakSoldier.h"
#include "Sword.h"

class StormcloakSoldier;
class ImperialSoldier : public Soldier {
 public:
    ImperialSoldier(std::string &&name, int health);
    ~ImperialSoldier() override;
};
