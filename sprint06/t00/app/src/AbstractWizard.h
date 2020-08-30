#pragma once

#include "FoodItem.h"

class AbstractWizard {
 protected:
    virtual FoodType deductFoodType(FoodItem &food) = 0;
};

class MightyWizard : public AbstractWizard {
 public:
    MightyWizard(std::string &name);
    void checkFood(FoodItem &food);
    void checkFood(FoodItem *food);
 protected:
    FoodType deductFoodType(FoodItem &food) override;
 private:
    std::string m_name;
};
