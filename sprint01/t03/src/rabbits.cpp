#include "rabbits.h"

Rabbit CreateRabbit() {
    Rabbit rab;

    rab.age = 0;
    rab.gender = rand() % 2 ? Gender::Female : Gender::Male;
    rab.isVampire = rab.bornVampire = rand() % 100 == 0 ? true : false;
    return rab;
}

void IncrementAge(std::list<Rabbit>& population) {
    for (auto& rab : population)
        rab.age++;
}

void KillOlderBoys(std::list<Rabbit> &population) {
    std::remove_if(population.begin(), population.end(), [](const Rabbit& rab) {
        if (rab.isVampire == false && rab.age > 3)
            return true;
        else if (rab.isVampire == true && rab.age > 8) {
            return true;
        }
        return false;
    });
}

void Reproduction(std::list<Rabbit> &population) {
    int m_num = std::count_if(population.begin(), population.end(), [](const Rabbit& rab) {
        if (rab.gender == Gender::Male && rab.isVampire == false)
            return true;
        return false;
    });
    int f_num = std::count_if(population.begin(), population.end(), [](const Rabbit& rab) {
        if (rab.gender == Gender::Female && rab.isVampire == false)
            return true;
        return false;
    });

    if (m_num > f_num) {
        for (int i = 0; i < f_num; ++i)
            population.push_back(CreateRabbit());
    }
    else if (f_num >= m_num){
        for (int i = 0; i < m_num; ++i)
            population.push_back(CreateRabbit());
    }
}

void Vampirization(std::list<Rabbit> &population) {
    int vampires = std::count_if(population.begin(), population.end(), [](const Rabbit& rab) {
        if (rab.bornVampire)
            return true;
        return false;
    });
    int current = 0;

    for (int i = 0; i < vampires && current < static_cast<int>(population.size()); ++i) {
        auto rab = std::next(population.begin(), current++);
        if (rab->isVampire)
            i--;
        else
            rab->isVampire = true;
    }
}

void PrintPopulation(std::list<Rabbit>& population) {
    int males = std::count_if(population.begin(), population.end(), [](const Rabbit& rab) {
        if (rab.gender == Gender::Male)
            return true;
        return false;
    });
    int females = std::count_if(population.begin(), population.end(), [](const Rabbit& rab) {
        if (rab.gender == Gender::Female)
            return true;
        return false;
    });
    int vampires = std::count_if(population.begin(), population.end(), [](const Rabbit& rab) {
        if (rab.isVampire)
            return true;
        return false;
    });

    std::cout << "Males: " << males << "\n" << "Females: " << females << "\n" << "Vampires: " << vampires << "\n\n";
}
