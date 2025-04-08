// Plant.cpp
#include "Plant.h"
#include <iostream>

const int Plant::MINIMAL_PLANT_GROWTH_STATE = 0;
const int Plant::MAXIMAL_PLANT_GROWTH_STATE = 11;
const int Plant::BASE_SNAIL_EATING_VALUE = 50;
const int Plant::BASE_PLANT_GROWTH_VALUE = 10;
const int Plant::BASE_PLANT_GROWTH_THRESHOLD_LEVEL_VALUE = 100;

Plant::Plant(int x, int y, int initialSize, int initialGrowthRate, int sizeGrowthCorrelation) : Organism(x, y),
                                                                                                m_initialSize(
                                                                                                        initialSize),
                                                                                                m_plantVolume(
                                                                                                        initialSize *
                                                                                                        BASE_PLANT_GROWTH_THRESHOLD_LEVEL_VALUE),
                                                                                                m_currentSize(
                                                                                                        initialSize),
                                                                                                m_initialGrowthRate(
                                                                                                        initialGrowthRate),
                                                                                                m_sizeGrowthCorrelation(
                                                                                                        sizeGrowthCorrelation) {
}

void Plant::simulateDay() {
    double normalizedInitialGrowth = m_initialGrowthRate * 0.01; // np. 50 -> 0.50
    double normalizedSizeFactor = m_currentSize * m_sizeGrowthCorrelation * 0.01;

    double totalGrowthFactor = 1.0 + normalizedInitialGrowth + normalizedSizeFactor;

    int volumeGrowthIncrement = static_cast<int>(BASE_PLANT_GROWTH_VALUE * totalGrowthFactor);

    int maxPlantVolume = BASE_PLANT_GROWTH_THRESHOLD_LEVEL_VALUE * MAXIMAL_PLANT_GROWTH_STATE;
    if (m_plantVolume < maxPlantVolume) {
        m_plantVolume = std::min(m_plantVolume + volumeGrowthIncrement, maxPlantVolume);
    }

    m_currentSize = m_plantVolume / BASE_PLANT_GROWTH_THRESHOLD_LEVEL_VALUE;
}

int Plant::getCurrentSize() {
    return m_currentSize;
}

void Plant::reduceSize(int amount) {
    m_currentSize = std::max(m_currentSize - amount, 0);
}