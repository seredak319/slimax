#ifndef SLIMAKS_SIMULATIONMANAGER_H
#define SLIMAKS_SIMULATIONMANAGER_H


#pragma once

#include "simulation/input/SimulationContext.h"
#include "simulation/SimulationStatus.h"
#include "model/Aquarium.h"

class SimulationManager {
public:
    void simulate(Aquarium &aquarium);

    SimulationStatus getCurrentSimulationStatus(Aquarium &aquarium);

private:
    void simulateFeeding(Aquarium &aquarium);

    void updateSnailPositions(Aquarium &aquarium);
};


#endif
