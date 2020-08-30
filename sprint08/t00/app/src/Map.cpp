#include "Map.h"
#include "Player.h"

Map::Map(size_t width, size_t height, std::shared_ptr<Player> &player) : m_width(width), m_height(height), m_player(player) {
    generateMap();
}

size_t Map::width() const {
    return m_width;
}

size_t Map::height() const {
    return m_height;
}

void Map::generateMap() {
    m_map = std::unique_ptr<char[]> (new char[m_width * m_height]);
    std::fill(m_map.get(), m_map.get() + width() * height(), '.');
    for (int i = 0; i < m_width * m_height; ++i) {
        int element = std::rand() % 3 % 2 + std::rand() % 3 % 2;
        if (element == 0)
            m_map.get()[i] = '.';
        else if (element == 1)
            m_map.get()[i] = 'T';
        else if (element == 2)
            m_map.get()[i] = '@';
    }
}

void Map::outputMap() const {
    for (int i = 1; i <= m_width * m_height; ++i) {
        if (m_player.get()->posX() + (m_player.get()->posY() * height()) == i - 1)
            std::cout << m_player->getIdentifier();
        else
            std::cout << m_map.get()[i - 1];
        if (!(i % m_height))
            std::cout << std::endl;
    }
}
