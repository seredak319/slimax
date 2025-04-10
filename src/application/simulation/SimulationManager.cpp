#include "SimulationManager.h"
#include "model/Plant.h"
#include "model/Snail.h"
#include "SimulationStatus.h"
#include <iostream>
#include <random>
#include <algorithm>


void SimulationManager::simulate(Aquarium &aquarium) {
    if (aquarium.getCurrentIteration() < aquarium.getTotalIterations()) {
        std::cout << "[Iteration " << aquarium.getCurrentIteration() << "]\n";
    }
    aquarium.increaseIteration();
    aquarium.simulateStep();

    updateSnailPositions(aquarium);
    simulateFeeding(aquarium);
}

SimulationStatus SimulationManager::getCurrentSimulationStatus(Aquarium &aquarium) {
    if (aquarium.getCurrentIteration() >= aquarium.getTotalIterations()) {
        return SimulationStatus::IterationLimit;
    }

    bool allPlantsDead = true;
    bool allSnailsAtMaxAge = true;

    for (const auto &organism: aquarium.organisms()) {
        if (auto plant = std::dynamic_pointer_cast<Plant>(organism)) {
            if (plant->isPlantAlive()) {
                allPlantsDead = false;
            }
        }
        if (auto snail = std::dynamic_pointer_cast<Snail>(organism)) {
            if (!snail->isMaximumAge()) {
                allSnailsAtMaxAge = false;
            }
        }
    }

    if (allPlantsDead) {
        return SimulationStatus::AllPlantsDead;
    }
    if (allSnailsAtMaxAge) {
        return SimulationStatus::AllSnailsAtMaxAge;
    }

    return SimulationStatus::Continue;
}

void SimulationManager::updateSnailPositions(Aquarium &aquarium) {
    std::vector<std::pair<int, std::shared_ptr<Plant>>> plants;
    const auto &organisms = aquarium.organisms();
    for (size_t i = 0; i < organisms.size(); ++i) {
        if (auto plant = std::dynamic_pointer_cast<Plant>(organisms[i])) {
            plants.push_back({static_cast<int>(i), plant});
        }
    }
    if (plants.empty()) {
        return;
    }

    std::vector<std::shared_ptr<Snail>> snails;
    for (auto &organism: organisms) {
        if (auto snail = std::dynamic_pointer_cast<Snail>(organism)) {
            snails.push_back(snail);
        }
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> plantIndexDist(0, plants.size() - 1);
    std::uniform_int_distribution<int> offsetDist(-25, 25);

    for (auto &snail: snails) {
        int randomIndexInPlants = plantIndexDist(gen);
        auto chosenPair = plants[randomIndexInPlants];
        auto chosenPlant = chosenPair.second;
        int originalPlantIndex = chosenPair.first;

        if (!chosenPlant->isPlantAlive()) {
            double maxVolume = plants[0].second->getPlantVolume();
            std::pair<int, std::shared_ptr<Plant>> maxPair = plants[0];
            for (const auto &pair: plants) {
                double vol = pair.second->getPlantVolume();
                if (vol > maxVolume) {
                    maxVolume = vol;
                    maxPair = pair;
                }
            }
            chosenPlant = maxPair.second;
            originalPlantIndex = maxPair.first;
        }

        snail->setNearbyPlantNumber(originalPlantIndex);
        int newX = chosenPlant->x() + offsetDist(gen);
        snail->setX(newX);
    }
}

void SimulationManager::simulateFeeding(Aquarium &aquarium) {
    std::vector<std::shared_ptr<Plant>> plants;
    for (auto &organism: aquarium.organisms()) {
        if (auto plant = std::dynamic_pointer_cast<Plant>(organism)) {
            plants.push_back(plant);
        }
    }

    for (auto &organism: aquarium.organisms()) {
        if (auto snail = std::dynamic_pointer_cast<Snail>(organism)) {
            int plantIndex = snail->getNearbyPlantNumber();
            std::shared_ptr<Plant> plant = (const std::shared_ptr<Plant> &) aquarium.organisms()[plantIndex];

            double normalizedAppetite = snail->getAppetite() * 0.01;
            double normalizedEatingFactor = snail->getCurrentSize() * snail->getAppetiteAgeCorrelation() * 0.01;
            double totalEatingFactor = 1.0 + normalizedAppetite + normalizedEatingFactor;

            int eatenAmount = static_cast<int>(snail->getBaseSnailEatingValue() * totalEatingFactor);

            plant->reduceSize(eatenAmount);

            std::cout << "Snail at x=" << snail->x()
                      << " eats plant at with number=" << snail->getNearbyPlantNumber()
                      << ", reducing its size by " << eatenAmount << ".\n";
        }
    }
}