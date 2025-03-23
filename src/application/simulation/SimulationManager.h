//
// Created by Krystian on 23.03.2025.
//

#ifndef SLIMAKS_SIMULATIONMANAGER_H
#define SLIMAKS_SIMULATIONMANAGER_H


#pragma once

#include "simulation/input/SimulationContext.h"
#include "simulation/output/IterationResult.h"

struct SimulationState {
    int currentIteration = 0;
    int totalIterations = 0;
};

class SimulationManager
{
public:
    void startSimulation(const SimulationContext &m_context);
    void simulateOneStep();
    bool isFinished() const;

    int getCurrentIteration() const { return m_state.currentIteration; }
    IterationResult getCurrentResult() const;

private:
    SimulationState m_state;
    IterationResult m_result;
};

#endif //SLIMAKS_SIMULATIONMANAGER_H
