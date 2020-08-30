#include "Player.h"

void Player::movePlayer(MoveManager::Direction dir) {
    if (dir == MoveManager::Direction::Up)
        m_posY -= 1;
    else if (dir == MoveManager::Direction::Down)
        m_posY += 1;
    else if (dir == MoveManager::Direction::Left)
        m_posX -= 1;
    else
        m_posX += 1;
}

size_t Player::posX() const {
    return m_posX;
}

size_t Player::posY() const {
    return m_posY;
}

char Player::getIdentifier() const {
    return 'P';
}
