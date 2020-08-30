#pragma once

#include <map>
#include <string>

class CacheStorage {
 public:
    void StoreValue(const std::string& rvalue, int value);
    int GetValue(const std::string& rvalue) const;
    bool HasValue(const std::string& rvalue);
 private:
    std::map<std::string, int> cache;
};
