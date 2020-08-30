#include <iostream>
#include <vector>
#include <algorithm>

size_t findCaseInsensitive(std::string data, std::string toSearch) {
    std::transform(data.begin(), data.end(), data.begin(), ::tolower);
    return data.find(toSearch);
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cerr << "usage: ./moveAlong [args]" << std::endl;
        return EXIT_FAILURE;
    }
    std::vector<std::string> elements;

    for (int i = 1; i < argc; ++i)
        elements.push_back(argv[i]);
    for (auto& item : elements) {
        if (findCaseInsensitive(item, "mercer") != std::string::npos ||
            findCaseInsensitive(item, "emer") != std::string::npos ||
            findCaseInsensitive(item, "jim") != std::string::npos)
            std::cout << item << ", move along!\n";
    }
    return 0;
}
