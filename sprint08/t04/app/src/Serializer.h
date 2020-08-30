#pragma once

#include <iostream>
#include <ostream>
#include <fstream>

class Serializer {
 public:
    template<class T>
    void serialize(const T* object, const std::string& fileName) {
        std::ofstream file(fileName, std::ios::binary);
        if (file) {
            file.write(reinterpret_cast<const char *>(object), sizeof(T));
            file.close();
        }
        else
            throw std::runtime_error("error");
    }
    template<class T>
    T deserialize(const std::string& fileName) {
        T object;
        std::ifstream out(fileName, std::ios::binary);
        if (out) {
            out.read(reinterpret_cast<char *>(&object), sizeof(T));
            return object;
        }
        else
            throw std::runtime_error("error");
    }
};

class SomeClass {
 public:
    SomeClass() = default;
    SomeClass(int intVal, char charVal, float floatVal) : m_intArg(intVal), m_charArg(charVal), m_floatArg(floatVal) {};
    void output() const {
        std::cout << m_intArg << " " << m_charArg << " " << m_floatArg << std::endl;
    }
 private:
    int m_intArg;
    char m_charArg;
    float m_floatArg;
};
