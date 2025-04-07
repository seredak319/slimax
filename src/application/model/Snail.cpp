//
// Created by Krystian on 15.03.2025.
//

#include "Snail.h"
#include <iostream>

Snail::Snail(int x, int y, int initialAge, int initialAppetite, int growthRate,
             int appetiteAgeCorrelation) : Organism(x, y), m_initialAge(initialAge), m_initialAppetite(initialAppetite),
                                           m_initialGrowthRate(growthRate),
                                           m_appetiteAgeCorrelation(appetiteAgeCorrelation) {

}

void Snail::simulateDay() {
    m_currentSize = m_initialAge++;
//    std::cout << "[Snail] simulate()" << std::endl;
}

int Snail::getCurrentSize() {
    return m_currentSize;
}