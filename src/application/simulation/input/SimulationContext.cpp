//
// Created by Krystian on 23.03.2025.
//

#include "SimulationContext.h"

SimulationContext::SimulationContext(int numSnails,
                                     int sAge,
                                     int sAppetite,
                                     int sGrowthRate,
                                     int sAppetiteAgeCorrelation,
                                     int numPlants,
                                     int pVolume,
                                     int pGrowthRate,
                                     int pPlantSizeGrowthCorrelation,
                                     int itCount,
                                     int aquariumWidth,
                                     bool isRandomEnabled,
                                     int randomRate)
        : m_numberOfSnails(numSnails), m_snailAge(sAge), m_snailAppetite(sAppetite), m_snailGrowthRate(sGrowthRate),
          m_appetiteAgeCorrelation(sAppetiteAgeCorrelation),
          m_numberOfPlants(numPlants), m_plantVolume(pVolume), m_plantGrowthRate(pGrowthRate),
          m_plantSizeGrowthCorrelation(pPlantSizeGrowthCorrelation),
          m_iterationCount(itCount), m_aquariumWidth(aquariumWidth), m_isRandomEnabled(isRandomEnabled),
          m_randomRate(randomRate) {
}

int SimulationContext::numberOfSnails() const { return m_numberOfSnails; }

int SimulationContext::snailAge() const { return m_snailAge; }

int SimulationContext::snailAppetite() const { return m_snailAppetite; }

int SimulationContext::snailGrowthRate() const { return m_snailGrowthRate; }

int SimulationContext::snailAppetiteAgeCorrelation() const { return m_appetiteAgeCorrelation; }

int SimulationContext::numberOfPlants() const { return m_numberOfPlants; }

int SimulationContext::plantVolume() const { return m_plantVolume; }

int SimulationContext::plantGrowthRate() const { return m_plantGrowthRate; }

int SimulationContext::plantSizeGrowthCorrelation() const { return m_plantSizeGrowthCorrelation; }

int SimulationContext::iterationCount() const { return m_iterationCount; }

int SimulationContext::aquariumWidth() const { return m_aquariumWidth; }

bool SimulationContext::isRandomEnabled() const { return m_isRandomEnabled; }

int SimulationContext::randomRate() const { return m_randomRate; }
