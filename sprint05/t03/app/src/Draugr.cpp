#include "Draugr.h"

static std::string BuildString(double health, int frostResist, std::string name) {
    return std::string(
        std::string("Draugr " + name + " (") + std::to_string(static_cast<int>(health))
            + " health, " + std::to_string(frostResist)
            + "% frost resist) shouts:\n");
}

Draugr::Draugr() : Draugr(100, 50) {
}

Draugr::Draugr(int frostResist) : Draugr(100, frostResist) {

}

Draugr::Draugr(double health, int frostResist)
    : m_health(health), m_frostResist(frostResist) {
    std::cout << "Draugr with " << m_health << " health and " << m_frostResist
              << "% frost resist was born!" << std::endl;
}

void Draugr::shoutPhrase(int shoutNumber) const {
    std::string roar = BuildString(m_health, m_frostResist, m_name);

    switch (shoutNumber) {
        case 0: std::cout << roar + std::string("Qiilaan Us Dilon!\n");
            break;
        case 1: std::cout << roar + std::string("Bolog Aaz, Mal Lir!\n");
            break;
        case 2: std::cout << roar + std::string("Kren Sosaal!\n");
            break;
        case 3: std::cout << roar + std::string("Dir Volaan!\n");
            break;
        case 4: std::cout << roar + std::string("Aar Vin Ok!\n");
            break;
        case 5: std::cout << roar + std::string("Unslaad Krosis!\n");
            break;
        case 6: std::cout << roar + std::string("Faaz! Paak! Dinok!\n");
            break;
        case 7: std::cout << roar + std::string("Aav Dilon!\n");
            break;
        case 8: std::cout << roar + std::string("Sovngarde Saraan!\n");
            break;
    }
}

void Draugr::setName(const std::string &&name) {
    m_name = name;
}
