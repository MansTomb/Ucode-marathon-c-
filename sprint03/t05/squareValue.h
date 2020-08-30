#pragma once

#include <iostream>
#include <ostream>
#include <cmath>

template<class Container>
void squareValue(Container& container) {
    for (typename Container::iterator it = std::begin(container); it != std::end(container); ++it) {
        *it = std::pow(*it, 2);
    }
}
