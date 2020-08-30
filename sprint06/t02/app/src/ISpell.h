#pragma once

#include <iostream>
#include <string>
#include <set>

namespace Creatures {
    class Creature;
}

namespace Spells {

enum class SpellType {
    Healing,
    Equilibrium,
    Flames,
    Freeze,
    Fireball
};

class ISpell {
 public:
    virtual ~ISpell() = default;

    virtual bool cast(Creatures::Creature &owner, Creatures::Creature &other) = 0;
    virtual SpellType getType() const = 0;
};
}

bool operator==(Spells::ISpell &lhs, Spells::ISpell &rhs);
