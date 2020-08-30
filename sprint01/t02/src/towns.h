#pragma once

#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <istream>
#include <numeric>

struct Town {
    int id;
    std::string name;
    int stamina;
    int distance;
};

std::istream& operator>>(std::istream &stream, Town& town);
Town ParseToTown(std::string argument, int id);
