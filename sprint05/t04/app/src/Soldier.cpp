#include "Soldier.h"

#include <iostream>

Soldier::Soldier(std::string &&name, int health) : m_name(name), m_health(health){
    std::cout << "Soldier " << m_name << " was created" << std::endl;
}

int Soldier::getHealth() const {
    return m_health;
}

void Soldier::setWeapon(Weapon *weapon) {
    m_weapon = weapon;
}

Soldier::~Soldier() {
    std::cout << "Soldier " << m_name << " was deleted" << std::endl;
    delete m_weapon;
}

void Soldier::attack(Soldier &other) {
    std::cout << m_name << " attacks " << other.m_name << " and deals "
              << m_weapon->getDamage()
              << " damage" << std::endl;
    other.m_health -= m_weapon->getDamage();
}
