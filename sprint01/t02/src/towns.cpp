#include "towns.h"

static void CheckIfAllCharsDigit(std::string& str) {
    for (const auto& i : str) {
        if (!isdigit(i))
            throw std::invalid_argument("");
    }
}

std::istream& operator>>(std::istream& stream, Town& town) {
    std::string town_name, stamina, distance;

    getline(stream, town_name, ',');
    getline(stream, stamina, ',');
    getline(stream, distance);

    if (town_name.empty() || stamina.empty() || distance.empty()) {
        stream.setstate(std::ios::failbit);
        return stream;
    }
    try {
        CheckIfAllCharsDigit(stamina);
        CheckIfAllCharsDigit(distance);
        town.name = town_name;
        town.stamina = std::stoi(stamina);
        town.distance = std::stoi(distance);
        if (town.stamina <= 0 || town.distance <= 0)
            stream.setstate(std::ios::failbit);
    }
    catch (...) {
        stream.setstate(std::ios::failbit);
    }
    return stream;
}

Town ParseToTown(std::string argument, int id) {
    Town town;
    std::stringstream ss(argument);

    ss >> town;
    if (ss.fail()) {
        std::cerr << "Argument " << argument << " is not valid\n";
        exit(EXIT_FAILURE);
    }
    town.id = id;
    return town;
}
