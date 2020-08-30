#include "src/Draugr.h"

#include <iostream>
#include <regex>

//int main(int argc, char *argv[]) {
//    std::smatch match;
//    std::string names = std::string(argv[2]);
//
//    if (argc != 4 && argc != 5) {
//        std::cerr
//            << "usage: ./draugr [shoutNumber] [name1,name2] [health] [frostResist]"
//            << std::endl;
//        return EXIT_FAILURE;
//    }
//    try {
//        if (argc >= 2) {
//            if (std::stoi(argv[1]) < 0 || std::stoi(argv[1]) > 8) {
//                std::cerr << "Invalid shoutNumber" << std::endl;
//                return EXIT_FAILURE;
//            }
//        }
//        if (!std::regex_match(names,
//                              match,
//                              std::regex(R"(\s*([\w\d]+),([\w\d]+)+\s*)"))) {
//            std::cerr << "Invalid names" << std::endl;
//            return EXIT_FAILURE;
//        }
//        if (argc == 4) {
//            Draugr dr1(std::stod(argv[3]));
//
//            dr1.setName(match.str(1));
//            dr1.shoutPhrase(std::stoi(argv[1]));
//            Draugr dr = dr1;
//            dr.setName(match.str(2));
//            dr.shoutPhrase(std::stoi(argv[1]));
//        } else {
//            Draugr dr1(std::stod(argv[3]), std::stoi(argv[4]));
//
//            dr1.setName(match.str(1));
//            dr1.shoutPhrase(std::stoi(argv[1]));
//            Draugr dr = std::move(dr1);
//            dr.setName(match.str(2));
//            dr.shoutPhrase(std::stoi(argv[1]));
//        }
//    }
//    catch (...) {
//        std::cerr << "Error" << std::endl;
//    }
//}

int main() {
    Draugr d1;

    d1.setName("Death Overlord");
    d1.shoutPhrase(3);
//    Draugr d2 = d1;
    Draugr d3(10.0, 30);
    d3.setName("Thrall");
    d3.shoutPhrase(4);
//    Draugr d4 = std::move(d3);
    return 0;
}
