#include "Imperial.h"

Imperial::Imperial(std::string &&name) : Creatures::Creature(std::move(name)) {}

void Imperial::sayPhrase() const {
    std::cout << "I am " << getName() << ", Imperial soldier! Stop right here!" << std::endl;
}
