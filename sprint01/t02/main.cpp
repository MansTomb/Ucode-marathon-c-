#include "src/towns.h"

void PrintPath(const std::deque<Town>& towns) {
    for (const auto& item : towns) {
        std::cout << item.id << ". " << item.name << std::endl;
    }
}

int main(int argc, char *argv[]) {
    std::deque<Town> towns;

    for (int i = 1; i < argc; ++i)
        towns.push_back(ParseToTown(argv[i], i - 1));
    if (towns.size() == 1) {
        PrintPath(towns);
        return 0;
    }
    for (int cycle = 0, size = towns.size(); cycle != size; ++cycle) {
        int acc = std::accumulate(towns.begin(), towns.end(), 0, [](int acc, Town& town) {
            if (acc >= 0)
                return acc + town.stamina - town.distance;
            else
                return acc;
        });
        if (acc >= 0) {
            PrintPath(towns);
            return 0;
        }
        else {
            Town& town = towns.front();
            towns.pop_front();
            towns.push_back(town);
        }
    }
    std::cerr << "Mission: Impossible\n";
    return 0;
}
