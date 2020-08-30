#include "src/Draugr.h"

#include <iostream>
#include <regex>

void Validate(int argc, char **p_string) {
    std::smatch match;
    std::string str;

    for (int i = 1; i < argc; ++i) {
        str = std::string(p_string[i]);
        if (!std::regex_match(str, match, std::regex(R"(\s*\d+\s*)"))) {
            std::cerr << "Error" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
}

int main(int argc, char *argv[]) {
    Validate(argc, argv);
    try {
        if (argc >= 2) {
            if (std::stoi(argv[1]) < 0 || std::stoi(argv[1]) > 8) {
                std::cerr << "Invalid shoutNumber" << std::endl;
                return EXIT_FAILURE;
            }
        }
        if (argc == 2) {
            Draugr dr;

            dr.shoutPhrase(std::stoi(argv[1]));
        } else if (argc == 3) {
            Draugr dr1(std::stod(argv[2]));

            dr1.shoutPhrase(std::stoi(argv[1]));
            Draugr dr(std::stoi(argv[2]));

            dr.shoutPhrase(std::stoi(argv[1]));
        } else if (argc == 4) {
            Draugr dr(std::stod(argv[2]), std::stoi(argv[3]));

            dr.shoutPhrase(std::stoi(argv[1]));
        } else {
            std::cerr << "usage: ./draugr [shoutNumber] [health] [frostResist]"
                      << std::endl;
        }
    }
    catch (...) {
        std::cerr << "Error" << std::endl;
    }
}
