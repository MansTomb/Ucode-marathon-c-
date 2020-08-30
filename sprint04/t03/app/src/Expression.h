#pragma once

#include <string>
#include <regex>
#include <iostream>
#include <map>
#include "Calculator.h"

#define regular R"(\s*([a-zA-Z]+|[\-\+]?[\d]+)\s*([\+\-\*\/])\s*([a-zA-Z]+|[\-\+]?[\d]+)\s*(?:=\s*([a-zA-Z]+))?\s*)"

class Expression {
 public:
    enum class Operations {
        Add,
        Substract,
        Multiply,
        Division,
    };
    explicit Expression(CacheStorage &store, std::string expr);
    Operations GetOperation();
    int GetOperand1();
    int GetOperand2();
    std::string GetRvalue();
    int Evaluate();
 private:
    int op1, op2;
    std::string rvalue;
    Operations operation;
    CacheStorage &cache;
};
