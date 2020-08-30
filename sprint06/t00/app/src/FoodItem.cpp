#include "FoodItem.h"

FoodType ApplePie::GetType() {
    return FoodType::ApplePie;
}

std::string ApplePie::GetName() {
    return "Apple pie";
}

FoodType HoneyNut::GetType() {
    return FoodType::HoneyNut;
}

std::string HoneyNut::GetName() {
    return "Honey nut";
}

FoodType Sweetroll::GetType() {
    return FoodType::Sweetroll;
}

std::string Sweetroll::GetName() {
    return "Sweetroll";
}

FoodType PoisonedFood::GetType() {
    return FoodType::PoisonedFood;
}

std::string PoisonedFood::GetName() {
    return "Poison";
}
