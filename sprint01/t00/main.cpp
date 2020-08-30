#include <iostream>
#include <algorithm>
#include <array>
#include <string>

int main(int argc, char *argv[]) {
    if (argc != 6) {
        std::cerr << "usage: ./simpleSort arg1 arg2 arg3 arg4 arg5" << std::endl;
        return EXIT_FAILURE;
    }
    std::array<std::string, 5> ar = {argv[1], argv[2], argv[3], argv[4], argv[5]};

    std::sort(ar.begin(), ar.end());
    for (auto it = ar.begin(); it != ar.end(); ++it) {
        if (it != ar.begin())
            std::cout << " " << *it;
        else
            std::cout << *it;
    }
    std::cout << std::endl;
    return 0;
}
