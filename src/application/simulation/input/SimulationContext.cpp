//
// Created by Krystian on 23.03.2025.
//

#include "SimulationContext.h"

SimulationContext::SimulationContext(int numSnails,
                                     int sAge,
                                     int sAppetite,
                                     int sGrowthRate,
                                     int numPlants,
                                     int pVolume,
                                     int pGrowthRate,
                                     int itCount)
        : m_numberOfSnails(numSnails), m_snailAge(sAge), m_snailAppetite(sAppetite), m_snailGrowthRate(sGrowthRate),
          m_numberOfPlants(numPlants), m_plantVolume(pVolume), m_plantGrowthRate(pGrowthRate),
          m_iterationCount(itCount) {
}

int SimulationContext::numberOfSnails() const { return m_numberOfSnails; }

int SimulationContext::snailAge() const { return m_snailAge; }

int SimulationContext::snailAppetite() const { return m_snailAppetite; }

int SimulationContext::snailGrowthRate() const { return m_snailGrowthRate; }

int SimulationContext::numberOfPlants() const { return m_numberOfPlants; }

int SimulationContext::plantVolume() const { return m_plantVolume; }

int SimulationContext::plantGrowthRate() const { return m_plantGrowthRate; }

int SimulationContext::iterationCount() const { return m_iterationCount; }
