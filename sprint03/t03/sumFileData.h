#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <iterator>

template<class T>
T sumFileData(const std::string& fileName) {
    std::ifstream ss(fileName);
    T sum = 0;

    std::istream_iterator<T> eos;
    std::istream_iterator<T> iit(ss);

    while (iit != eos) {
        sum += *iit;
        iit++;
    }
    ss.close();
    return sum;
}
