#pragma once

#include "LockpickDifficulty.h"

class ILockable {
 public:
    virtual LockpickDifficulty lockDifficulty() const = 0;
    virtual bool isLocked() const = 0;
    virtual ~ILockable() = default;
};
