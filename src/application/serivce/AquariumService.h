#ifndef SLIMAKS_AQUARIUMSERVICE_H
#define SLIMAKS_AQUARIUMSERVICE_H


#include "model/Aquarium.h"
#include "simulation/input/SimulationContext.h"

class AquariumService {

public:
    AquariumService() = default;

    Aquarium initAquariumBasedOnApplicationContext(const SimulationContext &context);
};

#endif
