#pragma once

#include "Soldier.h"
#include "ImperialSoldier.h"
#include "Axe.h"

class ImperialSoldier;
class StormcloakSoldier : public Soldier {
 public:
    StormcloakSoldier(std::string &&name, int health);
    ~StormcloakSoldier() override;
};
