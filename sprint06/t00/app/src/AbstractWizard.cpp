#include "AbstractWizard.h"

MightyWizard::MightyWizard(std::string &name) : m_name(name) {}

void MightyWizard::checkFood(FoodItem &food) {
    FoodType foodType = deductFoodType(food);

    if (foodType == FoodType::ApplePie || foodType == FoodType::PoisonedFood) {
        std::cout << food.GetName() << ". Ugh, not again!" << std::endl;
    } else {
        std::cout << food.GetName() << ". Mmm, tasty!" << std::endl;
    }
}

void MightyWizard::checkFood(FoodItem *food) {
    if (food != nullptr)
        checkFood(*food);
    else
        std::cout << "<wtf>. Ugh, not again!" << std::endl;
}

FoodType MightyWizard::deductFoodType(FoodItem &food) {
    return food.GetType();
}
