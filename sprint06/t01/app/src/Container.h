#pragma once

#include "ILockable.h"
#include "IOpenable.h"

class Container : public ILockable, public IOpenable {
 public:
    Container(bool isLocked, const LockpickDifficulty difficulty);

    LockpickDifficulty lockDifficulty() const override;
    bool isLocked() const override;
    bool tryToOpen(LockpickDifficulty difficulty) override;
    virtual std::string name() const = 0;
 private:
    bool m_isLocked{ false };
    LockpickDifficulty m_difficulty;
};
