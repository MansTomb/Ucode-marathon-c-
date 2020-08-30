#include "Dragonborn.h"

#include <iostream>
#include <map>

void Dragonborn::executeAction(const Dragonborn::Actions action) {
    const static std::map<Actions, void (Dragonborn::*)() const> table = {
        {Actions::Shout, &Dragonborn::shoutThuum},
        {Actions::Magic, &Dragonborn::attackWithMagic},
        {Actions::Weapon, &Dragonborn::attackWithWeapon}
    };
    std::__invoke(table.at(action), this);
}

void Dragonborn::shoutThuum() const {
    std::cout << "Yol Toor Shul" << std::endl;
}

void Dragonborn::attackWithMagic() const {
    std::cout << "*attacks with magic spell*" << std::endl;
}

void Dragonborn::attackWithWeapon() const {
    std::cout << "*attacks with weapon*" << std::endl;
}
