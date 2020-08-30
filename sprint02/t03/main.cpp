#include "src/validate.h"

void CheckWithRegexAndAdd(std::multimap<std::string, std::string> &library,
                          const std::string &line, int lineNum) {
    std::smatch match;
    std::regex_match(line, match, std::regex(REGEX));
    if (match.size() != 3) {
        std::cerr << "Line " << lineNum << " is invalid\n";
        exit(EXIT_FAILURE);
    }
    library.insert(std::make_pair(match.str(1), match.str(2)));
}

void PrintAllLibrary(std::multimap<std::string, std::string> &library,
                     const std::string &author) {
    std::cout << author << ":\n";
    int count = 1;
    for (auto &it : library) {
        if (it.first == author)
            std::cout << " " << count++ << ": " << it.second << std::endl;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "usage: ./tesLibrary [file_name]\n";
        return EXIT_FAILURE;
    }
    std::multimap<std::string, std::string> library;
    std::ifstream file(argv[1]);
    if (file.is_open()) {
        std::string line;
        int lineNum = 1;

        while (std::getline(file, line)) {
            if (!line.empty())
                CheckWithRegexAndAdd(library, line, lineNum++);
        }
        if (library.empty()) {
            std::cerr << "error\n";
            return EXIT_FAILURE;
        }
        for (auto it = library.begin(); it != library.end();
             it = library.upper_bound(it->first))
            PrintAllLibrary(library, it->first);
    } else {
        std::cerr << "error" << std::endl;
        return EXIT_FAILURE;
    }
}
