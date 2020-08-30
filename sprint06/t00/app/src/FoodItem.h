#pragma once

#include <iostream>
#include <string>

enum class FoodType {
    ApplePie,
    HoneyNut,
    Sweetroll,
    PoisonedFood,
    Invalid
};

class FoodItem {
 public:
    virtual ~FoodItem() = default;
    virtual FoodType GetType() = 0;
    virtual std::string GetName() = 0;
};

class ApplePie : public FoodItem {
    FoodType GetType() override;
    std::string GetName() override;
};

class HoneyNut : public FoodItem {
    FoodType GetType() override;
    std::string GetName() override;
};

class Sweetroll : public FoodItem {
    FoodType GetType() override;
    std::string GetName() override;
};

class PoisonedFood : public FoodItem {
    FoodType GetType() override;
    std::string GetName() override;
};
