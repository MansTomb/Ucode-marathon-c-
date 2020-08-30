#pragma once

#include <vector>
#include <iostream>

template<typename T>
class ClassWithInitializerList final {
 public:
    template<typename...Args>
    ClassWithInitializerList(Args &&...args);
    ClassWithInitializerList(const std::initializer_list<T> lst);
    ClassWithInitializerList(const std::vector<T> &vec);
    void outputVector() const;
 private:
    std::vector<T> m_vecOfArs;
};
template<typename T>

template<typename... Args>
ClassWithInitializerList<T>::ClassWithInitializerList(Args &&... args) {
    (m_vecOfArs.push_back(args), ...);
}

template<typename T>
void ClassWithInitializerList<T>::outputVector() const {
    for (const auto &ar : m_vecOfArs) {
        std::cout << ar << std::endl;
    }
}

template<typename T>
ClassWithInitializerList<T>::ClassWithInitializerList(const std::initializer_list<T> lst) {
    for (const auto &item : lst) {
        m_vecOfArs.push_back(item);
    }
}

template<typename T>
ClassWithInitializerList<T>::ClassWithInitializerList(const std::vector<T> &vec) : m_vecOfArs(vec) {}
