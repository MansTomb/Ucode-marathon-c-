#include "Safe.h"

Safe::Safe(bool isOpen, LockpickDifficulty difficulty) : Container(isOpen, difficulty) {}

std::string Safe::name() const {
    return "Safe";
}
