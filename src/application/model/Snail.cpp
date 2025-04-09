//
// Created by Krystian on 15.03.2025.
//

#include <algorithm>
#include "Snail.h"

const int Snail::MINIMAL_SNAIL_GROWTH_STATE = 0;
const int Snail::MAXIMAL_SNAIL_GROWTH_STATE = 11;
const int Snail::BASE_SNAIL_GROWTH_VALUE = 10;
const int Snail::SNAIL_GROWTH_THRESHOLD_LEVEL_VALUE = 100;
const int Snail::BASE_SNAIL_EATING_VALUE = 30;

Snail::Snail(int x, int y, int initialAge, int initialAppetite, int growthRate,
             int appetiteAgeCorrelation) : Organism(x, y),
                                           m_initialAge(initialAge),
                                           m_snailVolume(initialAge * SNAIL_GROWTH_THRESHOLD_LEVEL_VALUE),
                                           m_currentSize(initialAge),
                                           m_initialAppetite(initialAppetite),
                                           m_initialGrowthRate(growthRate),
                                           m_appetiteAgeCorrelation(appetiteAgeCorrelation) {

}

void Snail::simulateDay() {
    double normalizedGrowthRate = m_initialGrowthRate * 0.01;
    double normalizedAgeFactor = m_currentSize * m_appetiteAgeCorrelation * 0.01;
    double totalGrowthFactor = 1.0 + normalizedGrowthRate + normalizedAgeFactor;

    int growthIncrement = static_cast<int>(BASE_SNAIL_GROWTH_VALUE * totalGrowthFactor);

    int maxSnailVolume = SNAIL_GROWTH_THRESHOLD_LEVEL_VALUE * MAXIMAL_SNAIL_GROWTH_STATE;

    if (m_snailVolume < maxSnailVolume) {
        m_snailVolume = std::min(m_snailVolume + growthIncrement, maxSnailVolume);
    }

    m_currentSize = m_snailVolume / SNAIL_GROWTH_THRESHOLD_LEVEL_VALUE;
}

int Snail::getCurrentSize() {
    return m_currentSize;
}

int Snail::getAppetite() const {
    return m_initialAppetite;
}

int Snail::getAppetiteAgeCorrelation() const {
    return m_appetiteAgeCorrelation;
}

int Snail::getBaseSnailEatingValue() const {
    return BASE_SNAIL_EATING_VALUE;
}

void Snail::setNearbyPlantNumber(int n) {
   m_nearbyPlantNumber = n;
}

int Snail::getNearbyPlantNumber() const {
    return m_nearbyPlantNumber;
}

bool Snail::isMaximumAge() const {
    return m_currentSize == MAXIMAL_SNAIL_GROWTH_STATE;
}
