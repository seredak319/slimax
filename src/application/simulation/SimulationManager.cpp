//
// Created by Krystian on 23.03.2025.
//

#include "SimulationManager.h"
#include "model/Plant.h"
#include "model/Snail.h"
#include <iostream>
#include <random>


void SimulationManager::simulate(Aquarium &aquarium) {
    if (aquarium.getCurrentIteration() < aquarium.getTotalIterations()) {
        std::cout << "[Iteration " << aquarium.getCurrentIteration() << "]\n";
    }
    aquarium.increaseIteration();
    aquarium.simulateStep();

    updateSnailPositions(aquarium);
    simulateFeeding(aquarium);
}

bool SimulationManager::isFinished(Aquarium &aquarium) {
    return (aquarium.getCurrentIteration() >= aquarium.getTotalIterations());
}

void SimulationManager::updateSnailPositions(Aquarium &aquarium) {
    std::vector<std::shared_ptr<Plant>> plants;
    for (auto &organism : aquarium.organisms()) {
        if (auto plant = std::dynamic_pointer_cast<Plant>(organism)) {
            plants.push_back(plant);
        }
    }

    if (plants.empty()) return;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distOffset(-30, 30);
    std::uniform_int_distribution<> plantIndexDist(0, plants.size() - 1);

    for (auto &organism : aquarium.organisms()) {
        if (auto snail = std::dynamic_pointer_cast<Snail>(organism)) {
            int randomPlantIndex = plantIndexDist(gen);
            int plantX = plants[randomPlantIndex]->x(); // pozycja rośliny
            int offset = distOffset(gen);
            int newX = plantX + offset;
            snail->setX(newX);
        }
    }
}

void SimulationManager::simulateFeeding(Aquarium &aquarium) {
    std::vector<std::shared_ptr<Plant>> plants;
    for (auto &organism : aquarium.organisms()) {
        if (auto plant = std::dynamic_pointer_cast<Plant>(organism)) {
            plants.push_back(plant);
        }
    }

    if (plants.empty()) return;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> plantIndexDist(0, plants.size() - 1);

    for (auto &organism : aquarium.organisms()) {
        if (auto snail = std::dynamic_pointer_cast<Snail>(organism)) {
            int randomPlantIndex = plantIndexDist(gen);
            auto plant = plants[randomPlantIndex];

            int eatenAmount = snail->getCurrentSize() * snail->getAppetiteAgeCorrelation();

            std::cout << "Snail at x=" << snail->x() << " eats plant at x=" << plant->x()
                      << " reducing its size by " << eatenAmount << ".\n";
        }
    }
}