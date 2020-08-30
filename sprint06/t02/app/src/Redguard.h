#pragma once

#include "Creatures.h"

class Redguard : public Creatures::Creature {
 public:
    Redguard(std::string&& name);
    void sayPhrase() const override;
};
