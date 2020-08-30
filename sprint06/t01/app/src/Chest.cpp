#include "Chest.h"

Chest::Chest(bool isOpen, LockpickDifficulty difficulty) : Container(isOpen, difficulty) {}

std::string Chest::name() const {
    return "Chest";
}
