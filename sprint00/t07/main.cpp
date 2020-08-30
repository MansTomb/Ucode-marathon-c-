#include "src/commands.h"

int main() {
    std::vector<std::string> inventory(12);

    inventory.assign(12, "-");
    while(1) {
        std::string command;

        std::cout << "Enter command:> ";
        std::cin >> command;
        if (command == "insert")
            insert(inventory);
        else if (command == "remove")
            remove(inventory);
        else if (command == "show")
            show(inventory);
        else if (command == "help")
            help();
        else if (command == "exit") {
            if (!validation()) continue;
            std::cout << "Bye." << std::endl;
            return 0;
        }
        else {
            std::cerr << "Invalid command." << std::endl;
        }
    }
}
