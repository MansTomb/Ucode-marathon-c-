#include "Redguard.h"

Redguard::Redguard(std::string &&name) : Creatures::Creature(std::move(name)) {}

void Redguard::sayPhrase() const {
    std::cout << "I am " << getName() << ", from Redguards, wanna trade?" << std::endl;
}
