#include "src/rabbits.h"

int main() {
    std::list<Rabbit> population;
    
    for (int i = 0; i < 10; ++i) {
        population.push_front(CreateRabbit());
    }

    while (population.size() < 1000 && population.size() != 0) {
        PrintPopulation(population);
        KillOlderBoys(population);
        Reproduction(population);
        Vampirization(population);
        IncrementAge(population);
        sleep(1);
    }
}
