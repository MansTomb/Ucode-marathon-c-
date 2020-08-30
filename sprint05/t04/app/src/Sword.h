#pragma once

#include "Weapon.h"

class Sword : public Weapon {
 public:
    explicit Sword(int damage);
    ~Sword() override = default;
 private:
    int m_damage;
};
