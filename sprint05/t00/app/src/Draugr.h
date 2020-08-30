#pragma once

#include <iostream>

#define DROAR "Draugr (100 health, 50% frost resist) shouts:\n"

class Draugr {
 public:
    Draugr();
    void shoutPhrase(int shoutNumber) const;
 private:
    double m_health;
    const int m_frostResist;
};
