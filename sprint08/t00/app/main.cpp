#include <string>
#include "src/Player.h"
#include "src/Map.h"
#include <regex>

static void Validate(int num, char **av) {
    std::cmatch m;
    if (num != 3) {
        std::cerr << "usage: ./smartPointers [width] [height]" << std::endl;
        exit(EXIT_FAILURE);
    }
    if ((!std::regex_match(av[1], m, std::regex("[\\d]+")) || !std::regex_match(av[2], m, std::regex("[\\d]+")))) {
        std::cerr << "usage: ./smartPointers [width] [height]" << std::endl;
        exit(EXIT_FAILURE);
    }
    size_t w = std::stoul(av[1]);
    size_t h = std::stoul(av[2]);

    if ((w < 5 || w > 20) || (h < 5 || h > 20)) {
        std::cerr << "Invalid map size" << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    Validate(argc, argv);
    std::shared_ptr<Player> player(new Player);
    std::shared_ptr<Map> map(new Map(std::stoul(argv[1]), std::stoul(argv[2]), player));
    std::unique_ptr<MoveManager> manager(new MoveManager(player, map));

    while (1) {
        map->outputMap();
        std::string s;
        std::cin >> s;
        manager->processInputAndMove(s);
    }
    return 0;
}
