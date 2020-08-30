#pragma once

#include "main.h"

class Healing : public Spells::ISpell {
 public:
    bool cast(Creatures::Creature &owner, Creatures::Creature &other) override;
    Spells::SpellType getType() const override;
};

class Equilibrium : public Spells::ISpell {
 public:
    bool cast(Creatures::Creature &owner, Creatures::Creature &other) override;
    Spells::SpellType getType() const override;
};

class Flames : public Spells::ISpell {
 public:
    bool cast(Creatures::Creature &owner, Creatures::Creature &other) override;
    Spells::SpellType getType() const override;
};

class Freeze : public Spells::ISpell {
 public:
    bool cast(Creatures::Creature &owner, Creatures::Creature &other) override;
    Spells::SpellType getType() const override;
};

class Fireball : public Spells::ISpell {
 public:
    bool cast(Creatures::Creature &owner, Creatures::Creature &other) override;
    Spells::SpellType getType() const override;
};
