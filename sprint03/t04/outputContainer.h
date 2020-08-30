#pragma once

#include <iostream>
#include <ostream>

template<class Container>
void outputContainer(const Container& container) {
    std::ostream_iterator<typename Container::value_type> out(std::cout, "\n");
    std::copy(std::begin(container), std::end(container), out);
}
