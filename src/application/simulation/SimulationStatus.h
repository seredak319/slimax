#ifndef SIMULATIONSTATE_H
#define SIMULATIONSTATE_H

enum class SimulationStatus {
    Continue,
    IterationLimit,
    AllPlantsDead,
    AllSnailsAtMaxAge
};

#endif
