#include "Player.h"

#include <iostream>

void Player::openContainer(Container *container) {
    if (container->tryToOpen(m_lockpickSkill))
        std::cout << m_name << " succesfully opened " << container->name() << std::endl;
    else
        std::cout << m_name << " skill is too low to open " << container->name() << std::endl;
}

void Player::setLockpickSkill(LockpickDifficulty skill) {
    m_lockpickSkill = skill;
}

Player::Player(const std::string &name) : m_name(name) {

}
