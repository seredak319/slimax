// Plant.cpp
#include "Plant.h"
#include <iostream>

Plant::Plant(int x, int y, int initialSize, int initialGrowthRate, int sizeGrowthCorrelation) : Organism(x, y),
                                                                                                m_initialSize(
                                                                                                        initialSize),
                                                                                                m_initialGrowthRate(
                                                                                                        initialGrowthRate),
                                                                                                m_sizeGrowthCorrelation(
                                                                                                        sizeGrowthCorrelation) {
}

void Plant::simulateDay() {
    m_currentSize = m_initialSize++;
//    std::cout << "[Plant] simulate()" << std::endl;

}

int Plant::getCurrentSize() {
    return m_currentSize;
}
