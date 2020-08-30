#include "commands.h"

static bool validation(std::string item_type) {
    if (std::cin.peek() != '\n') {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cerr << "Invalid command." << std::endl;
        return 0;
    }
    if (std::string(TYPES).find(item_type, 0) == std::string::npos || item_type.size() != 1) {
        std::cerr << "Invalid item." << std::endl;
        return 0;
    }
    return 1;
}

std::vector<std::string> GetCommandArgs(std::string &command) {
    if (std::cin.peek() != '\n') {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cerr << "Invalid command." << std::endl;
        return 0;
    }
    return 1;
}

void insert(std::vector<std::string>& inventory) {
    std::string item_type;

    std::cin >> item_type;
    if (!validation(item_type)) return;
    for (int i = 0; i < 12; ++i) {
        if (inventory[i] == "-") {
            inventory[i] = item_type;
            std::cout << item_type << " was inserted." << std::endl;
            return;
        }
        else if (i == 11) {
            std::cerr << "Inventory is full." << std::endl;
            return;
        }
    }
}
void remove(std::vector<std::string>& inventory) {
    std::string item_type;

    std::cin >> item_type;
    if (!validation(item_type)) return;
    for (int i = 0; i < 12; ++i) {
        if (inventory[i] == item_type && inventory[i].size() == item_type.size()) {
            inventory.erase(inventory.begin() + i);
            inventory.push_back("-");
            std::cout << item_type << " was removed." << std::endl;
            return;
        }
        else if (i == 11) {
            std::cerr << "Invalid item." << std::endl;
            return;
        }
    }
}
void show(std::vector<std::string>& inventory) {
    if (!validation()) return;

    std::cout << "Inventory { ";
    for (int i = 0; i < 12; ++i) {
        std::cout << inventory[i] << " ";
    }
    std::cout << "}" << std::endl;
}
void help(void) {
    if (!validation()) return;

    std::cout << "Available commands:\n" <<
                "1. insert <itemType>\n" <<
                "2. remove <itemType>\n" <<
                "3. show inventory\n" <<
                "4. help\n" <<
                "5. exit\n";
}
