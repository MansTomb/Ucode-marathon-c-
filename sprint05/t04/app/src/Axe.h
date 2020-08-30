#pragma once

#include "Weapon.h"

class Axe : public Weapon {
 public:
    explicit Axe(int damage);
    ~Axe() override = default;
 private:
    int m_damage;
};
