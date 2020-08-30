#pragma once

#include "Container.h"

class Chest : public Container {
 public:
    Chest(bool isOpen, LockpickDifficulty difficulty);
    std::string name() const override;
};
