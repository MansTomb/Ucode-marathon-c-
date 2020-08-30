#include "Container.h"

bool Container::isLocked() const {
    return m_isLocked;
}

bool Container::tryToOpen(LockpickDifficulty difficulty) {
    if (m_difficulty > difficulty && m_isLocked)
        return false;
    m_isLocked = false;
    return true;
}

Container::Container(bool isLocked, const LockpickDifficulty difficulty)
    : m_isLocked(isLocked), m_difficulty(difficulty) {

}

LockpickDifficulty Container::lockDifficulty() const {
    return m_difficulty;
}
