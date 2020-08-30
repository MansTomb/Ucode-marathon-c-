#include "Creatures.h"

static std::string SpellNameByType(Spells::SpellType type) {
    if (type == Spells::SpellType::Healing)
        return "healing";
    else if (type == Spells::SpellType::Equilibrium)
        return "equilibrium";
    else if (type == Spells::SpellType::Flames)
        return "flames";
    else if (type == Spells::SpellType::Freeze)
        return "freeze";
    else if (type == Spells::SpellType::Fireball)
        return "fireball";
    return "Invalid";
}

static bool IsSpellKnown(const std::set<Spells::ISpell *> &spells, Spells::ISpell *spell) {
    return std::count_if(spells.begin(), spells.end(), [spell](const Spells::ISpell *item) {
        return spell->getType() == item->getType();
    });
}

static Spells::ISpell *GetSpellByType(const std::set<Spells::ISpell *> &spells, const Spells::SpellType type) {
    Spells::ISpell *spell = nullptr;

    std::count_if(spells.begin(), spells.end(), [&spell, type](Spells::ISpell *item) {
        if (item->getType() == type)
            spell = item;
        return item->getType() == type;
    });
    return spell;
}

Creatures::Creature::Creature(std::string &&name) : m_name(name) {
    std::cout << m_name << " was born!" << std::endl;
}

Creatures::Creature::~Creature() {
    std::for_each(m_spells.begin(), m_spells.end(), [](auto *spell) {
        delete spell;
    });
}

void Creatures::Creature::learnSpell(Spells::ISpell *spell) {
    if (!spell)
        return;
    if (IsSpellKnown(m_spells, spell)) {
        std::cout << m_name << " already knows " << SpellNameByType(spell->getType()) << " spell!\n";
        delete spell;
    }
    else {
        m_spells.insert(spell);
        std::cout << m_name << " has learned " << SpellNameByType(spell->getType()) << " spell successfully!\n";
    }
}

void Creatures::Creature::castSpell(const Spells::SpellType type, Creature &creature) {
    Spells::ISpell *spell = GetSpellByType(m_spells, type);
    if (spell == nullptr)
        std::cout << SpellNameByType(type) << " spell is not learned by " << m_name << "." << std::endl;
    else if (spell->cast(*this, creature))
        std::cout << m_name << " casted " << SpellNameByType(spell->getType()) << " spell on " << creature.getName()
                  << "!" << std::endl;
    else
        std::cout << m_name << " can't cast " << SpellNameByType(spell->getType()) << std::endl;
}

std::string Creatures::Creature::getName() const {
    return m_name;
}

int Creatures::Creature::getHealth() const {
    return m_health;
}

int Creatures::Creature::getMana() const {
    return m_mana;
}

void Creatures::Creature::setHealth(int health) {
    m_health = health;
}

void Creatures::Creature::setMana(int mana) {
    m_mana = mana;
}

std::ostream &operator<<(std::ostream &os, const Creatures::Creature &creature) {
    os << creature.getName() << " : " << creature.getHealth() << " HP, " << creature.getMana() << " MP.";
    return os;
}
