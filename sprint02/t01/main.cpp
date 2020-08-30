#include <iostream>
#include <fstream>
#include <ostream>
#include <set>
#include <string>
#include <sstream>

void ModifyAndPush(std::multiset<std::string> &words,
                   std::set<std::string> &words_unique,
                   std::string &name) {
    std::stringstream ss(name);
    std::string toPush;
    std::string chars = ",.!?";

    while (getline(ss, toPush, ' ')) {
        toPush.erase(std::remove_if(toPush.begin(),
                                    toPush.end(),
                                    [&chars](char a) {
                                      return chars.find(a) != std::string::npos;
                                    }), toPush.end());
        words.insert(toPush);
        words_unique.insert(toPush);
    }
}

void CreateOutputFile(char *const *argv, std::ofstream &out) {
    std::string fname(argv[1]);
    unsigned long pos = fname.find_last_of('.');
    std::string nname(fname.begin(), fname.begin() + pos);
    if (!std::string(fname.begin() + pos + 1, fname.end()).empty())
        out.open(nname + "_mod" + std::string(fname.begin() + pos, fname.end()),
                 std::ofstream::out);
    else
        out.open(nname + "_mod", std::ofstream::out);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "usage: ./countUniqueWords [file_name]\n";
        return EXIT_FAILURE;
    }
    std::multiset<std::string> words;
    std::set<std::string> words_unique;
    std::ifstream file(argv[1]);
    std::ofstream out;

    if (file.is_open()) {
        std::string name;

        while (std::getline(file, name)) {
            ModifyAndPush(words, words_unique, name);
        }
        if (words.size() == 0) {
            std::cerr << "error\n";
            return EXIT_FAILURE;
        }
        CreateOutputFile(argv, out);
        if (out.is_open()) {
            for (auto &item : words_unique) {
                out << item << ": " << words.count(item) << std::endl;
            }
        } else {
            std::cerr << "error" << std::endl;
            return EXIT_FAILURE;
        }

    } else {
        std::cerr << "error\n";
        return EXIT_FAILURE;
    }
}
