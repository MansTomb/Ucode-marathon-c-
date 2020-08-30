#include "Draugr.h"

Draugr::Draugr() : m_health(100), m_frostResist(50) {

}

void Draugr::shoutPhrase(int shoutNumber) const {
    switch (shoutNumber) {
        case 0: std::cout << DROAR + std::string("Qiilaan Us Dilon!\n");
            break;
        case 1: std::cout << DROAR + std::string("Bolog Aaz, Mal Lir!\n");
            break;
        case 2: std::cout << DROAR + std::string("Kren Sosaal!\n");
            break;
        case 3: std::cout << DROAR + std::string("Dir Volaan!\n");
            break;
        case 4: std::cout << DROAR + std::string("Aar Vin Ok!\n");
            break;
        case 5: std::cout << DROAR + std::string("Unslaad Krosis!\n");
            break;
        case 6: std::cout << DROAR + std::string("Faaz! Paak! Dinok!\n");
            break;
        case 7: std::cout << DROAR + std::string("Aav Dilon!\n");
            break;
        case 8: std::cout << DROAR + std::string("Sovngarde Saraan!\n");
            break;
    }
    if (shoutNumber < 0 && shoutNumber > 8)
        std::cerr << "Invalid shoutNumber" << std::endl;
}
