//
// Created by Krystian on 23.03.2025.
//

#ifndef SLIMAKS_SIMULATIONMANAGER_H
#define SLIMAKS_SIMULATIONMANAGER_H


#pragma once

#include "simulation/input/SimulationContext.h"
#include "model/Aquarium.h"

class SimulationManager {
public:
    void simulate(Aquarium &aquarium);

    bool isFinished(Aquarium &aquarium);

private:
    void simulateFeeding(Aquarium &aquarium);

    void updateSnailPositions(Aquarium &aquarium);
};


#endif //SLIMAKS_SIMULATIONMANAGER_H
