#pragma once

#include <iostream>
#include <ostream>

template<class BidirectionalIterator>
bool isPalindrome(BidirectionalIterator begin, BidirectionalIterator end) {
    end--;
    for (; begin != end; begin++, end--)
        if (*begin != *end)
            return false;
    return true;
}
