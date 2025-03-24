#include "AquariumService.h"
#include <random>
#include <memory>
#include <algorithm>
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

    // Dodaj ślimaki
    for (int i = 0; i < numSnails; ++i) {
        int x, y, age, appetite, growthRate;
        if (!context.isRandomEnabled()) {
            x = (i + 1) * aquariumWidth / (numSnails + 1);
            y = 100;
            age = context.snailAge();
            appetite = context.snailAppetite();
            growthRate = context.snailGrowthRate();
        } else {
            std::uniform_int_distribution<int> distX(0, aquariumWidth);
            x = distX(gen);
            std::uniform_int_distribution<int> distYOffset(-10, 10);
            y = 100 + distYOffset(gen);

            int maxDev = (context.randomRate() * 11) / 100;
            std::uniform_int_distribution<int> distAge(-maxDev, maxDev);
            age = std::clamp(context.snailAge() + distAge(gen), 0, 11);

            appetite = context.snailAppetite();
            growthRate = context.snailGrowthRate();
        }
        int appetiteAgeCorrelation = 5;
        aquarium.addOrganism(std::make_shared<Snail>(x, y, age, appetite, growthRate, appetiteAgeCorrelation));
    }

    // Dodaj rośliny
    for (int i = 0; i < numPlants; ++i) {
        int x, y, size, growthRate;
        if (!context.isRandomEnabled()) {
            x = (i + 1) * aquariumWidth / (numPlants + 1);
            y = 300;
            size = context.plantVolume();
            growthRate = context.plantGrowthRate();
        } else {
            std::uniform_int_distribution<int> distX(0, aquariumWidth);
            x = distX(gen);
            std::uniform_int_distribution<int> distYOffset(-10, 10);
            y = 300 + distYOffset(gen);

            int maxDev = (context.randomRate() * 11) / 100;
            std::uniform_int_distribution<int> distSize(-maxDev, maxDev);
            size = std::clamp(context.plantVolume() + distSize(gen), 0, 11);

            growthRate = context.plantGrowthRate();
        }
        int sizeGrowthCorrelation = 5;
        aquarium.addOrganism(std::make_shared<Plant>(x, y, size, growthRate, sizeGrowthCorrelation));
    }

    return aquarium;
}
