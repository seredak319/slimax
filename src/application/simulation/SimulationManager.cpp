//
// Created by Krystian on 23.03.2025.
//

#include "SimulationManager.h"
#include <iostream>

void SimulationManager::startSimulation(const SimulationContext &ctx) {
    m_state.currentIteration = 0;
    m_state.totalIterations = ctx.iterationCount();
    m_result.finalSnailCount = ctx.numberOfSnails();
    m_result.finalPlantCount = ctx.numberOfPlants();

}

void SimulationManager::simulateOneStep() {
    if (m_state.currentIteration < m_state.totalIterations) {
        // Przykładowa prosta logika (prawdziwa zależy od Twoich potrzeb)
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