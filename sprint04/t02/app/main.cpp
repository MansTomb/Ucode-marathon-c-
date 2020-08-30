#include <iostream>
#include <map>
#include <array>

#include "src/Dragonborn.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "usage: ./dragonborn [action]\n";
        return EXIT_FAILURE;
    }
    Dragonborn muskurta;
    std::map<std::string, Dragonborn::Actions> table = {
        {std::string("shout"), Dragonborn::Actions::Shout},
        {std::string("magic"), Dragonborn::Actions::Magic},
        {std::string("weapon"), Dragonborn::Actions::Weapon}
    };

    if (table.count(std::string(argv[1])))
        muskurta.executeAction(table[argv[1]]);
    else
        std::cerr << "Invalid action" << std::endl;
}
