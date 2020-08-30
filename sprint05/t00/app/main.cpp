#include "src/Draugr.h"

#include <iostream>
#include <regex>

int main(int argc, char *argv[]) {
    std::string num(argv[1]);
    std::smatch smat;

    if (argc != 2) {
        std::cerr << "usage: ./draugr [shoutNumber]\n";
        return EXIT_FAILURE;
    }
    if (!std::regex_match(num, smat, std::regex(R"(\s*\d+\s*)"))) {
        std::cerr << "Invalid shoutNumber\n";
        return EXIT_FAILURE;
    }
    Draugr dr;

    try {

        dr.shoutPhrase(std::stoi(argv[1]));
    }
    catch (...) {}
}
