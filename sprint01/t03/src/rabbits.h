#pragma once

#include <list>
#include <iostream>
#include <unistd.h>
#include <algorithm>

enum class Gender {
    Male,
    Female
};

struct Rabbit {
    Gender gender;
    bool isVampire;
    bool bornVampire;
    int age;
};

Rabbit CreateRabbit();
void IncrementAge(std::list<Rabbit>& population);
void KillOlderBoys(std::list<Rabbit> &population);
void Reproduction(std::list<Rabbit> &population);
void Vampirization(std::list<Rabbit> &population);
void PrintPopulation(std::list<Rabbit>& population);
