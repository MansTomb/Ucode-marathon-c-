#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <array>

#include "src/Calculator.h"
#include "src/Expression.h"

static int CheckArgument(std::string &arg) {
    std::vector<std::string> args;
    std::stringstream ss(arg);
    std::string argu;

    while (std::getline(ss, argu, ' ')) {
        if (argu.size() != 0)
            args.push_back(argu);
    }
    return args.size();
}

int main(int argc, char *argv[]) {
    std::string line;
    CacheStorage store;

    while (1) {
        std::cout << ":>";
        getline(std::cin, line);
        if (line.find("quit") != std::string::npos && CheckArgument(line) == 1)
            return EXIT_SUCCESS;
        try {
            Expression expr(store, line);

            std::cout << expr.Evaluate() << std::endl;
        }
        catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
}
