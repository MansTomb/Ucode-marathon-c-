#include "ImperialSoldier.h"

#include <iostream>

ImperialSoldier::ImperialSoldier() {
    m_health = 100;
}

ImperialSoldier::~ImperialSoldier() {
    delete m_weapon;
}

int ImperialSoldier::getHealth() const {
    return m_health;
}

void ImperialSoldier::setWeapon(Sword *sword) {
    m_weapon = sword;
}

void ImperialSoldier::attack(StormcloakSoldier &enemy) {
    std::cout << "Imperial soldier attacks and deals " << m_weapon->getDamage()
              << " damage" << std::endl;
    enemy.consumeDamage(m_weapon->getDamage());
}

void ImperialSoldier::consumeDamage(int amount) {
    std::cout << "Imperial soldier consumes " << amount << " of damage"
              << std::endl;
    m_health -= amount;
}
