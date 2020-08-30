#include "Spells.h"

Spells::SpellType Healing::getType() const {
    return Spells::SpellType::Healing;
}

Spells::SpellType Equilibrium::getType() const {
    return Spells::SpellType::Equilibrium;
}

Spells::SpellType Flames::getType() const {
    return Spells::SpellType::Flames;
}

Spells::SpellType Freeze::getType() const {
    return Spells::SpellType::Freeze;
}

Spells::SpellType Fireball::getType() const {
    return Spells::SpellType::Fireball;
}

bool Healing::cast(Creatures::Creature &owner, Creatures::Creature &other) {
    if (owner.getMana() >= 15) {
        owner.setHealth(owner.getHealth() + 10);
        owner.setMana(owner.getMana() - 15);
        return true;
    }
    return false;
}

bool Equilibrium::cast(Creatures::Creature &owner, Creatures::Creature &other) {
    if (owner.getHealth() > 25) {
        owner.setHealth(owner.getHealth() - 25);
        owner.setMana(owner.getMana() + 25);
        return true;
    }
    return false;
}

bool Flames::cast(Creatures::Creature &owner, Creatures::Creature &other) {
    if (owner.getMana() >= 14) {
        owner.setMana(owner.getMana() - 14);
        other.setHealth(other.getHealth() - 8);
        return true;
    }
    return false;
}

bool Freeze::cast(Creatures::Creature &owner, Creatures::Creature &other) {
    if (owner.getMana() >= 30) {
        owner.setMana(owner.getMana() - 30);
        other.setHealth(other.getHealth() - 20);
        return true;
    }
    return false;
}

bool Fireball::cast(Creatures::Creature &owner, Creatures::Creature &other) {
    if (owner.getMana() >= 50) {
        owner.setMana(owner.getMana() - 50);
        other.setHealth(other.getHealth() - 40);
        return true;
    }
    return false;
}
