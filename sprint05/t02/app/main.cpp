#include "src/Draugr.h"

#include <iostream>
#include <regex>

int main(int argc, char *argv[]) {
    std::smatch match;

    if (argc != 4 && argc != 5) {
        std::cerr
            << "usage: ./draugr [shoutNumber] [name1,name2] [health] [frostResist]"
            << std::endl;
        return EXIT_FAILURE;
    }
    std::string names = std::string(argv[2]);
    try {
        if (argc >= 2) {
            if (std::stoi(argv[1]) < 0 || std::stoi(argv[1]) > 8) {
                std::cerr << "Invalid shoutNumber" << std::endl;
                return EXIT_FAILURE;
            }
        }
        if (!std::regex_match(names,
                              match,
                              std::regex(R"(\s*([\w]+),([\w]+)\s*)"))) {
            std::cerr << "Invalid names" << std::endl;
            return EXIT_FAILURE;
        }
        if (argc == 4) {
            Draugr dr1(std::stod(argv[3]));

            dr1.setName(match.str(1));
            dr1.shoutPhrase(std::stoi(argv[1]));
            Draugr dr = dr1;
            dr.setName(match.str(2));
            dr.shoutPhrase(std::stoi(argv[1]));
        } else {
            Draugr dr1(std::stod(argv[3]), std::stoi(argv[4]));

            dr1.setName(match.str(1));
            dr1.shoutPhrase(std::stoi(argv[1]));
            Draugr dr = std::move(dr1);
            dr.setName(match.str(2));
            dr.shoutPhrase(std::stoi(argv[1]));
        }
    }
    catch (...) {
        std::cerr << "Error" << std::endl;
    }
}
