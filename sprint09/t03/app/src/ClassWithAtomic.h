#pragma once

#include <thread>
#include <vector>
#include <algorithm>
#include <iostream>

class ClassWithAtomic {
 public:
    ClassWithAtomic() = default;
    ~ClassWithAtomic() = default;
    void addToInt(int addValue) {
        for (int i = 0; i < std::abs(addValue); ++i)
            m_int += 1;
    }
    void subtractFromInt(int subtractValue) {
        for (int i = 0; i < std::abs(subtractValue); ++i)
            m_int -= 1;
    }
    void pushToVector(int value) {
        std::lock_guard<std::mutex> lck(m_vecMutex);
        m_vector.push_back(value);
    }
    void eraseFromVector(int value) {
        std::lock_guard<std::mutex> lck(m_vecMutex);
        auto it = std::remove_if(m_vector.begin(), m_vector.end(), [value](int i) {
            return i == value;
        });
        if (it != m_vector.end())
            m_vector.erase(it, m_vector.end());
    }
    int getInt() const {
        return m_int;
    }
    std::vector<int> getVector() const {
        return m_vector;
    }
 private:
    std::mutex m_vecMutex;
    std::atomic<int> m_int;
    std::vector<int> m_vector;
};
