#include "StormcloakSoldier.h"

#include <iostream>

StormcloakSoldier::StormcloakSoldier() {
    m_health = 100;
}

StormcloakSoldier::~StormcloakSoldier() {
    delete m_weapon;
}

int StormcloakSoldier::getHealth() const {
    return m_health;
}

void StormcloakSoldier::setWeapon(Axe *axe) {
    m_weapon = axe;
}

void StormcloakSoldier::attack(ImperialSoldier &enemy) {
    std::cout << "Stormcloak soldier attacks and deals "
              << m_weapon->getDamage() << " damage" << std::endl;
    enemy.consumeDamage(m_weapon->getDamage());
}

void StormcloakSoldier::consumeDamage(int amount) {
    std::cout << "Stormcloak soldier consumes " << amount << " of damage"
              << std::endl;
    m_health -= amount;
}

