#include "Calculator.h"

void CacheStorage::StoreValue(const std::string& rvalue, int value) {
    cache[rvalue] = value;
}

int CacheStorage::GetValue(const std::string& rvalue) const {
    return cache.at(rvalue);
}

bool CacheStorage::HasValue(const std::string& rvalue) {
    return cache.count(rvalue);
}
