#include "AquariumService.h"
#include <random>
#include <memory>
#include <algorithm>
#include <iostream>
#include "model/Aquarium.h"
#include "model/Snail.h"
#include "model/Plant.h"

Aquarium AquariumService::initAquariumBasedOnApplicationContext(const SimulationContext &context) {
    Aquarium aquarium{context.iterationCount()};

    int numSnails = context.numberOfSnails();
    int numPlants = context.numberOfPlants();
    int aquariumWidth = context.aquariumWidth();

    std::random_device rd;
    std::mt19937 gen(rd());

    //ślimaki
    for (int i = 0; i < numSnails; ++i) {
        int x, y, age, appetite, growthRate, appetiteAgeCorrelation;
        if (!context.isRandomEnabled()) {
            x = (i + 1) * aquariumWidth / (numSnails + 1);
            y = 500;
            age = context.snailAge();
            appetite = context.snailAppetite();
            growthRate = context.snailGrowthRate();
            appetiteAgeCorrelation = context.snailAppetiteAgeCorrelation();
        } else {
            const int margin = 70;
            std::uniform_int_distribution<int> distX(margin, aquariumWidth - margin);

            x = distX(gen);
            std::uniform_int_distribution<int> distYOffset(-10, 10);
            y = 100 + distYOffset(gen);

            std::uniform_int_distribution<int> distSize(-2, 2);
            std::cout << distSize(gen);
            age = std::clamp(context.snailAge() + distSize(gen), 0, 11);

            appetite = context.snailAppetite();
            growthRate = context.snailGrowthRate();
            appetiteAgeCorrelation = context.snailAppetiteAgeCorrelation();
        }
        aquarium.addOrganism(std::make_shared<Snail>(x, y, age, appetite, growthRate, appetiteAgeCorrelation));
    }

    // rośliny
    for (int i = 0; i < numPlants; ++i) {
        int x, y, size, growthRate, sizeGrowthCorrelation;
            x = (i + 1) * aquariumWidth / (numPlants + 2);
            y = 500;
            size = context.plantVolume();
            growthRate = context.plantGrowthRate();
            sizeGrowthCorrelation = context.plantSizeGrowthCorrelation();
        aquarium.addOrganism(std::make_shared<Plant>(x, y, size, growthRate, sizeGrowthCorrelation));
    }

    return aquarium;
}
