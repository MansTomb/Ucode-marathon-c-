#include <iostream>
#include <string>

static void CheckArgc(int argc) {
    if (argc != 5) {
        std::cerr << "usage:./automaton [name] [level] [health] [stamina]"
                  << std::endl;
        exit(EXIT_FAILURE);
    }
}

template<typename T>
void ConvertAndCheck(std::string &result, const std::string &argument,
                     std::function<T(const std::string &, size_t *)> func) {
    try {
        size_t readed = 0;
        result += std::to_string(func(argument, &readed)) + "\n";
        if (readed != argument.size()) {
            std::cerr << "Invalid argument: " << argument << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    catch (std::invalid_argument &e) {
        std::cerr << "Invalid argument: " << argument << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    CheckArgc(argc);
    std::string result;

    result += "Name = " + std::string(argv[1]) + "\n";
    result += "Health = ";
    ConvertAndCheck<int>(result, std::string(argv[2]),
                         [](const std::string &arg, size_t *read) {
                             return std::stoi(arg, read);
                         });
    result += "Level = ";
    ConvertAndCheck<float>(result, argv[3],
                           [](const std::string &arg, size_t *read) {
                               return std::stof(arg, read);
                           });
    result += "Stamina = ";
    ConvertAndCheck<double>(result, argv[4],
                            [](const std::string &arg, size_t *read) {
                                return std::stod(arg, read);
                            });
    std::cout << result;
}
