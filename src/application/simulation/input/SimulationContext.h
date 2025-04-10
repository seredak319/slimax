#ifndef SLIMAKS_SIMULATIONCONTEXT_H
#define SLIMAKS_SIMULATIONCONTEXT_H

#pragma once

class SimulationContext {
public:
    SimulationContext(int numSnails,
                      int sAge,
                      int sAppetite,
                      int sGrowthRate,
                      int sAppetiteAgeCorrelation,
                      int numPlants,
                      int pVolume,
                      int pGrowthRate,
                      int pSizeGrowthCorrelation,
                      int itCount,
                      int aquariumWidth,
                      bool isRandomEnabled,
                      int randomRate);

    int numberOfSnails() const;

    int snailAge() const;

    int snailAppetite() const;

    int snailGrowthRate() const;

    int snailAppetiteAgeCorrelation() const;

    int numberOfPlants() const;

    int plantVolume() const;

    int plantGrowthRate() const;

    int plantSizeGrowthCorrelation() const;

    int iterationCount() const;

    int aquariumWidth() const;

    bool isRandomEnabled() const;

    int randomRate() const;

private:
    int m_numberOfSnails;
    int m_snailAge;
    int m_snailAppetite;
    int m_snailGrowthRate;
    int m_appetiteAgeCorrelation;

    int m_numberOfPlants;
    int m_plantVolume;
    int m_plantGrowthRate;
    int m_plantSizeGrowthCorrelation;

    int m_iterationCount;
    int m_aquariumWidth;

    int m_isRandomEnabled;
    int m_randomRate;
};

#endif
