// Plant.cpp
#include "Plant.h"
#include <iostream>

const int Plant::MAXIMAL_PLANT_GROWTH_STATE = 11;
const int Plant::BASE_PLANT_GROWTH_VALUE = 10;
const int Plant::BASE_PLANT_GROWTH_THRESHOLD_LEVEL_VALUE = 100;

// Dziedziczenie
Plant::Plant(int x, int initialSize, int initialGrowthRate, int sizeGrowthCorrelation) : Organism(x),
                                                                                         m_plantVolume(
                                                                                                 initialSize *
                                                                                                 BASE_PLANT_GROWTH_THRESHOLD_LEVEL_VALUE),
                                                                                         m_isAlive(true),
                                                                                         m_currentSize(
                                                                                                 initialSize),
                                                                                         m_initialGrowthRate(
                                                                                                 initialGrowthRate),
                                                                                         m_sizeGrowthCorrelation(
                                                                                                 sizeGrowthCorrelation) {
}

void Plant::simulateDay() {
    if (isPlantAlive()) {
        double normalizedInitialGrowth = m_initialGrowthRate * 0.01;
        double normalizedSizeFactor = m_currentSize * m_sizeGrowthCorrelation * 0.01;

        double totalGrowthFactor = 1.0 + normalizedInitialGrowth + normalizedSizeFactor;

        int volumeGrowthIncrement = static_cast<int>(BASE_PLANT_GROWTH_VALUE * totalGrowthFactor);

        int maxPlantVolume = BASE_PLANT_GROWTH_THRESHOLD_LEVEL_VALUE * MAXIMAL_PLANT_GROWTH_STATE;
        if (m_plantVolume < maxPlantVolume) {
            m_plantVolume = std::min(m_plantVolume + volumeGrowthIncrement, maxPlantVolume);
        }
    }
    m_currentSize = m_plantVolume / BASE_PLANT_GROWTH_THRESHOLD_LEVEL_VALUE;
}

int Plant::getCurrentSize() {
    return m_currentSize;
}

void Plant::reduceSize(int amount) {
    if (isPlantAlive()) {
        m_plantVolume = m_plantVolume - amount;

        if (m_plantVolume <= 0) {
            m_isAlive = false;
        }
        m_currentSize = m_plantVolume / BASE_PLANT_GROWTH_THRESHOLD_LEVEL_VALUE;
    }
}

int Plant::getPlantVolume() const {
    return m_plantVolume;
}

bool Plant::isPlantAlive() const {
    return m_isAlive;
}
