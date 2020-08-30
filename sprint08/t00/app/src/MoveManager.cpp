#include "MoveManager.h"
#include "Player.h"
#include "Map.h"

MoveManager::MoveManager(std::shared_ptr<Player> &player, std::shared_ptr<Map> &map) : m_player(player), m_map(map) {}

bool MoveManager::checkMove(MoveManager::Direction dir) const {
    int pposition = m_player.get()->posX() + (m_player.get()->posY() * m_map->height());

    switch (dir) {
        case MoveManager::Direction::Down:
            if (pposition + m_map->height() < m_map->width() * m_map->height())
                return true;
            break;
        case MoveManager::Direction::Up:
            if (static_cast<int>(pposition) - static_cast<int>(m_map->height()) > 0)
                return true;
            break;
        case MoveManager::Direction::Left:
            if (m_player->posX() > 0)
                return true;
            break;
        case MoveManager::Direction::Right:
            if (m_player->posX() < m_map->height() - 1)
                return true;
            break;
    }
    std::cerr << "Invalid direction" << std::endl;
    return false;
}

void MoveManager::processInputAndMove(const std::string &inputStr) {
    if (inputStr == "u") {
        if (checkMove(MoveManager::Direction::Up))
            m_player.get()->movePlayer(MoveManager::Direction::Up);
    }
    else if (inputStr == "d") {
            if (checkMove(MoveManager::Direction::Down))
                m_player.get()->movePlayer(MoveManager::Direction::Down);
        }
    else if (inputStr == "l") {
            if (checkMove(MoveManager::Direction::Left))
                m_player.get()->movePlayer(MoveManager::Direction::Left);
        }
    else if (inputStr == "r") {
            if (checkMove(MoveManager::Direction::Right))
                m_player.get()->movePlayer(MoveManager::Direction::Right);
        }
    else if (inputStr == "e") {
            exit(EXIT_FAILURE);
        }
    else
        std::cerr << "Invalid input" << std::endl;
}
