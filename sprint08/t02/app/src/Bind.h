#pragma once

#include <iostream>
#include <typeinfo>
#include <string>

namespace UniversalReferenceDeterminant{
    template<typename T>
    void determineReference(T&& obj) {
        if (!std::is_lvalue_reference<T>())
            std::cout << (strcmp(typeid(obj).name(), "i") == 0 ? "int" : "char") << " is l-value reference" << std::endl;
        else if (!std::is_rvalue_reference<T>())
            std::cout << (strcmp(typeid(obj).name(), "i") == 0 ? "int" : "char") << " is r-value reference" << std::endl;
    }
}
