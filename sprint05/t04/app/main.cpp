#include <iostream>
#include <string>
#include <regex>
#include "src/ImperialSoldier.h"
#include "src/StormcloakSoldier.h"
#include "src/Axe.h"
#include "src/Sword.h"

template<typename T>
bool IsInRange(const T &val, const T &from, const T &to) {
    return val <= to && val >= from;
}

void Validation(int argc, char **p_string) {
    if (argc != 3) {
        std::cerr << "usage: ./imperialVsStormcloak [dmgOfSword] [dmgOfAxe]\n";
        exit(EXIT_FAILURE);
    }
    std::smatch reg;
    std::string SwordDamage = std::string(p_string[1]);
    std::string AxeDamage = std::string(p_string[2]);
    if (!std::regex_match(SwordDamage, reg, std::regex("(\\d+)")) ||
        !std::regex_match(AxeDamage, reg, std::regex("(\\d+)"))) {
        return;
    }
    int sDamage = std::stoi(p_string[1]);
    int aDamage = std::stoi(p_string[2]);
    if (!IsInRange(sDamage, 10, 20) || !IsInRange(aDamage, 10, 20)) {
        std::cerr << "Damage has to be in a range of 10-20 points."
                  << std::endl;
        exit(EXIT_FAILURE);
    }
}
#include <unistd.h>
int main(int argc, char *argv[]) {
    Validation(argc, argv);

    ImperialSoldier imperial("Martin", 100);
    StormcloakSoldier stormcloak("Flynn", 100);
    bool someOneALive = true;

    imperial.setWeapon(new Sword(std::stoi(argv[1])));
    stormcloak.setWeapon(new Axe(std::stoi(argv[2])));
    std::cout << "\n***The battle has begun!***\n" << std::endl;
    while (someOneALive) {
        stormcloak.attack(imperial);
        imperial.attack(stormcloak);
        std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>"
                  << std::endl;
        if (imperial.getHealth() <= 0 && !(someOneALive = false)) {
            std::cout << "Stormcloak has won!\n" << std::endl;
        }
        else if (stormcloak.getHealth() <= 0 && !(someOneALive = false)) {
            std::cout << "Imperial has won!\n" << std::endl;
        }
    }
}
