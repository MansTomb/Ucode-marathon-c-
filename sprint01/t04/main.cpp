#include <iostream>
#include <fstream>
#include <forward_list>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>

static void PrintRich(std::forward_list<std::string>& names) {
    if (std::any_of(names.begin(), names.end(), [](std::string& s) {
        if (s.find("rich") != std::string::npos)
            return true;
        return false;
    }))
        std::cout << "contains 'rich': " << "true\n";
    else
        std::cout << "contains 'rich': " << "false\n";
}

static void PrintLength(std::forward_list<std::string>& names) {
    if (std::any_of(names.begin(), names.end(), [](std::string& s) {
        if (s.size() == 15)
            return true;
        return false;
    }))
        std::cout << "none of lengths is 15: " << "false\n";
    else
        std::cout << "none of lengths is 15: " << "true\n";
}

static void PrintAllEnd(std::forward_list<std::string>& names, int size) {
    if (std::count_if(names.begin(), names.end(), [](std::string& s) {
        if (s.compare(s.size() - 3, 3, "vel") == 0)
            return true;
        return false;
    }) != size)
        std::cout << "all end with 'vel': " << "false\n";
    else
        std::cout << "all end with 'vel': " << "true\n";
}

static void PrintNotContains(std::forward_list<std::string>& names, int size) {
    auto count = std::count_if(names.begin(), names.end(), [](std::string& s) {
        if (s.find("mel") != std::string::npos)
            return true;
        return false;
    });
    std::cout << "not contains 'mel': " << size - count << std::endl;
}

static void Validate(std::string& name) {
    std::stringstream ss(name);
    std::string nme;
    std::vector<std::string> check;

    while (getline(ss, nme, ' ')) {
        if (nme.size() != 0)
            check.push_back(nme);
    }
    if (check.size() != 1) {
        std::cerr << "error" << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "usage: ./stdAlgoV1 [file_name]" << std::endl;
        return EXIT_FAILURE;
    }
    std::forward_list<std::string> names;
    std::ifstream file(argv[1]);

    if (file.is_open()) {
        std::string name;
        int size = 0;

        while (std::getline(file, name)) {
            Validate(name);
            names.push_front(name);
            size++;
        }
        if (size == 0) {
            std::cerr << "error" << std::endl;
            return EXIT_FAILURE;
        }
        std::cout << "size: " << size << std::endl;
        PrintRich(names);
        PrintLength(names);
        PrintAllEnd(names, size);
        PrintNotContains(names, size);
    }
    else {
        std::cerr << "error" << std::endl;
        return EXIT_FAILURE;
    }
}
