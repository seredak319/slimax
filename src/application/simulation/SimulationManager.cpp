//
// Created by Krystian on 23.03.2025.
//

#include "SimulationManager.h"
#include <iostream>


void SimulationManager::simulate(Aquarium &aquarium) {
    if (aquarium.getCurrentIteration() < aquarium.getTotalIterations()) {
        std::cout << "[Iteration " << aquarium.getCurrentIteration() << "]\n";
    }
    aquarium.increaseIteration();
    aquarium.simulateStep();
}

bool SimulationManager::isFinished(Aquarium &aquarium) {
    return (aquarium.getCurrentIteration() >= aquarium.getTotalIterations());
}