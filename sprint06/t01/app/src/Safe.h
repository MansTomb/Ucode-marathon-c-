#pragma once

#include "Container.h"

class Safe : public Container {
 public:
    Safe(bool isOpen, LockpickDifficulty difficulty);
    std::string name() const override;
};
