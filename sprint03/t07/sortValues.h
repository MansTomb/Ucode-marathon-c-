#pragma once

#include <iostream>
#include <vector>
#include <ostream>

template<class RandomAccessIterator>
RandomAccessIterator sortValues(RandomAccessIterator begin, RandomAccessIterator end) {
    int length = end - begin;
    if (length < 2)
        return begin;
    std::vector<typename RandomAccessIterator::value_type> elements(begin, end);

    auto one_three = elements.begin() + length / 3;
    auto two_three = elements.begin() + length * 2 / 3;

    sortValues(elements.begin(), one_three);
    sortValues(one_three, two_three);
    sortValues(two_three, elements.end());

    std::vector<typename RandomAccessIterator::value_type> middle_result;
    std::merge(elements.begin(), one_three, one_three, two_three, std::back_inserter(middle_result));
    std::merge(middle_result.begin(), middle_result.end(), two_three, elements.end(), begin);
    return begin;
}
