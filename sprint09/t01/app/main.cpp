#include <string>
#include "src/MultithreadedClass.h"
#include <regex>

static void Validate(int ar, char **arg) {
    if (ar != 4) {
        std::cerr << "usage: ./simpleWorkerV2 [addValue] [subtractValue] [count]" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cmatch match;
    if (!std::regex_match(arg[1], match, std::regex("^(\\d{1,4})$")) ||
        !std::regex_match(arg[2], match, std::regex("^(\\d{1,4})$")) ||
        !std::regex_match(arg[3], match, std::regex("^(\\d{1,2})$"))) {
        std::cerr << "Incorrect Values" << std::endl;
        exit(EXIT_FAILURE);
    }
    int add = 0;
    int substract = 0;
    int count = 0;
    try {
        add = std::stoi(arg[1]);
        substract = std::stoi(arg[2]);
        count = std::stoi(arg[3]);
    }
    catch (std::exception& e) {
        std::cerr << "Incorrect Values" << std::endl;
        exit(EXIT_FAILURE);
    }
    if (!(std::abs(add) <= 2000) || !(std::abs(substract) <= 2000) || !(count <= 10 && count >= 5)) {
        std::cerr << "Incorrect Values" << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv) {
    Validate(argc, argv);
    int addValue = std::stoi(argv[1]);
    int subtractValue = std::stoi(argv[2]);
    int count = std::stoi(argv[3]);
    MultithreadedClass obj;
    Worker worker;
    for (auto i = 0; i < count; ++i) {
        worker.startNewThread(&MultithreadedClass::add, &obj, addValue);
    }
    for (auto i = 0; i < count; ++i) {
        worker.startNewThread(&MultithreadedClass::subtract, &obj, subtractValue);
    }
    worker.joinAllThreads();
    std::cout << obj.getInt() << std::endl;
    for (auto i = 0; i < count; ++i) {
        worker.startNewThread(&MultithreadedClass::add, &obj, addValue);
        worker.startNewThread(&MultithreadedClass::subtract, &obj, subtractValue);
    }
    worker.joinAllThreads();
    std::cout << obj.getInt() << std::endl;
}
