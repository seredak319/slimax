//
// Created by Krystian on 23.03.2025.
//

#include "SimulationManager.h"
#include <iostream>

void SimulationManager::startSimulation(const SimulationContext &context) {
    m_state.currentIteration = 0;
    m_state.totalIterations = context.iterationCount();
    m_result.finalSnailCount = context.numberOfSnails();
    m_result.finalPlantCount = context.numberOfPlants();
}

void SimulationManager::simulateOneStep() {
    if (m_state.currentIteration < m_state.totalIterations) {
        std::cout << "[Iteration " << m_state.currentIteration << "]\n";
        std::cout << "  Snails: " << m_result.finalSnailCount << "\n";
        std::cout << "  Plants: " << m_result.finalPlantCount << "\n";

        // Przykladowe modyfikacje
        m_result.finalSnailCount += 1;
        m_result.finalPlantCount -= 1;

        m_state.currentIteration++;
    }
}

bool SimulationManager::isFinished() const {
    return (m_state.currentIteration >= m_state.totalIterations);
}

IterationResult SimulationManager::getCurrentResult() const {
    return m_result;
}