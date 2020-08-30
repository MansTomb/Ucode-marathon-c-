#pragma once

#include "Worker.h"

class MultithreadedClass {
 public:
    MultithreadedClass() = default;
    ~MultithreadedClass() = default;
    int getInt() const {
        return m_int;
    }
    void add(int addValue) {
        m_mutex.lock();
        for (int i = 0; i < std::abs(addValue); ++i)
            m_int += 1;
        m_mutex.unlock();
    }
    void subtract(int subtractValue) {
        std::lock_guard lock(m_mutex);
        for (int i = 0; i < std::abs(subtractValue); ++i)
            m_int -= 1;
    }
 private:
    int m_int{0};
    std::mutex m_mutex;
};
