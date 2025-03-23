//
// Created by Krystian on 23.03.2025.
//

#ifndef SLIMAKS_SIMULATIONCONTEXT_H
#define SLIMAKS_SIMULATIONCONTEXT_H

#pragma once

class SimulationContext {
public:
    SimulationContext(int numSnails,
                      int sAge,
                      int sAppetite,
                      int sGrowthRate,
                      int numPlants,
                      int pVolume,
                      int pGrowthRate,
                      int itCount);

    int numberOfSnails() const;
    int snailAge() const;
    int snailAppetite() const;
    int snailGrowthRate() const;
    int numberOfPlants() const;
    int plantVolume() const;
    int plantGrowthRate() const;
    int iterationCount() const;

private:
    int m_numberOfSnails;
    int m_snailAge;
    int m_snailAppetite;
    int m_snailGrowthRate;

    int m_numberOfPlants;
    int m_plantVolume;
    int m_plantGrowthRate;

    int m_iterationCount;
};

#endif //SLIMAKS_SIMULATIONCONTEXT_H
