#include <iostream>
#include <fstream>
#include <ostream>
#include <forward_list>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>

static void Remove(std::forward_list<std::string>& names) {
    names.remove_if([](const std::string& str) {
        if (str.find("c") != std::string::npos ||
            str.find("b") != std::string::npos ||
            str.find("l") != std::string::npos)
            return true;
        return false;
    });
}

static void ReplaceLong(std::forward_list<std::string>& names) {
    std::replace_if(names.begin(), names.end(), [](const std::string& str) {
        if (str.size() > 10)
            return true;
        return false;
    }, "Long One");
}

static void ReplaceShort(std::forward_list<std::string>& names) {
    std::replace_if(names.begin(), names.end(), [](const std::string& str) {
        if (str.size() < 4)
            return true;
        return false;
    }, "Short One");
}

static void Modify(std::forward_list<std::string>& names) {
    Remove(names);
    ReplaceLong(names);
    ReplaceShort(names);
    names.sort();
    names.unique();
    names.reverse();
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
        std::cerr << "usage: ./stdAlgoV2 [file_name]" << std::endl;
        return EXIT_FAILURE;
    }
    std::forward_list<std::string> names;
    std::ifstream file(argv[1]);
    std::ofstream out;

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
        Modify(names);
        std::string fname(argv[1]);

        if (fname.find(".txt") != std::string::npos)
            fname.erase(fname.size() - 4);
        out.open(fname + "_mod.txt", std::ofstream::out);
        if (out.is_open()) {
            for (auto& item : names) {
                out << item << std::endl;
            }
        }
        else {
            std::cerr << "error" << std::endl;
            return EXIT_FAILURE;
        }
    }
    else {
        std::cerr << "error" << std::endl;
        return EXIT_FAILURE;
    }
}
