//
// Created by Krystian on 23.03.2025.
//

#include "SimulationManager.h"
#include "model/Plant.h"
#include "model/Snail.h"
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

bool SimulationManager::isFinished(Aquarium &aquarium) {
    if (aquarium.getCurrentIteration() >= aquarium.getTotalIterations()) {
        return true;
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

    return allPlantsDead || allSnailsAtMaxAge;
}

//void SimulationManager::updateSnailPositions(Aquarium &aquarium) {
//    std::vector<std::shared_ptr<Plant>> plants;
//    for (auto &organism: aquarium.organisms()) {
//        if (auto plant = std::dynamic_pointer_cast<Plant>(organism)) {
//            plants.push_back(plant);
//        }
//    }
//
//    if (plants.empty()) return;
//
//    std::random_device rd;
//    std::mt19937 gen(rd());
//    std::uniform_int_distribution<int> distOffset(-30, 30);
//    std::uniform_int_distribution<> plantIndexDist(0, plants.size() - 1);
//
//    for (auto &organism: aquarium.organisms()) {
//        if (auto snail = std::dynamic_pointer_cast<Snail>(organism)) {
//            int randomPlantIndex = plantIndexDist(gen);
//            snail->setNearbyPlantNumber(randomPlantIndex);
//            int plantX = plants[randomPlantIndex]->x();
//            int offset = distOffset(gen);
//            int newX = plantX + offset;
//            snail->setX(newX);
//        }
//    }
//}

void SimulationManager::updateSnailPositions(Aquarium &aquarium) {
    std::vector<std::shared_ptr<Plant>> alivePlants;
    for (auto &organism: aquarium.organisms()) {
        if (auto plant = std::dynamic_pointer_cast<Plant>(organism)) {
            if (plant->isPlantAlive()) {
                alivePlants.push_back(plant);
            }
        }
    }

//    if (alivePlants.empty()) return;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distOffset(-30, 30);
    std::uniform_int_distribution<> plantIndexDist(0, alivePlants.size() - 1);

    for (auto &organism: aquarium.organisms()) {
        if (auto snail = std::dynamic_pointer_cast<Snail>(organism)) {
            int randomPlantIndex = plantIndexDist(gen);
            snail->setNearbyPlantNumber(randomPlantIndex);
            int plantX = alivePlants[randomPlantIndex]->x();
            int offset = distOffset(gen);
            int newX = plantX + offset;
            snail->setX(newX);
        }
    }
}

//void SimulationManager::updateSnailPositions(Aquarium &aquarium) {
//    // Krok 1: Pobierz wszystkie rośliny do wektora
//    std::vector<std::shared_ptr<Plant>> plants;
//    for (auto &organism : aquarium.organisms()) {
//        if (auto plant = std::dynamic_pointer_cast<Plant>(organism)) {
//            plants.push_back(plant);
//        }
//    }
//
//    if (plants.empty()) return;
//
//    // Krok 2: Znajdź roślinę o największej objętości
//    auto bestPlantIt = std::max_element(plants.begin(), plants.end(),
//                                        [](const std::shared_ptr<Plant>& a, const std::shared_ptr<Plant>& b) {
//                                            return a->getPlantVolume() < b->getPlantVolume();
//                                        });
//    std::shared_ptr<Plant> bestPlant = *bestPlantIt;
//    // Możemy także obliczyć indeks, jeśli potrzebny:
//    int bestPlantIndex = std::distance(plants.begin(), bestPlantIt);
//
//    // Krok 3: Dla każdego ślimaka ustaw nowe położenie bazujące na pozycji najlepszej rośliny
//    std::random_device rd;
//    std::mt19937 gen(rd());
//    std::uniform_int_distribution<int> distOffset(-30, 30);
//
//    for (auto &organism : aquarium.organisms()) {
//        if (auto snail = std::dynamic_pointer_cast<Snail>(organism)) {
//            snail->setNearbyPlantNumber(bestPlantIndex);
//            int offset = distOffset(gen);
//            int newX = bestPlant->x() + offset;
//            snail->setX(newX);
//        }
//    }
//}

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
            auto plant = plants[plantIndex];

            double normalizedAppetite = snail->getAppetite() * 0.01;
            double normalizedEatingFactor = snail->getCurrentSize() * snail->getAppetiteAgeCorrelation() * 0.01;
            double totalEatingFactor = 1.0 + normalizedAppetite + normalizedEatingFactor;

            int eatenAmount = static_cast<int>(snail->getBaseSnailEatingValue() * totalEatingFactor);

            plant->reduceSize(eatenAmount);

            std::cout << "Snail at x=" << snail->x()
                      << " eats plant at x=" << plant->x()
                      << ", reducing its size by " << eatenAmount << ".\n";
        }
    }
}