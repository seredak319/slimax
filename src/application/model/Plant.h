// Plant.h
#ifndef SLIMAKS_PLANT_H
#define SLIMAKS_PLANT_H

#include "model/base/Organism.h"

class Plant : public Organism {
public:
    Plant(int x, int y, int initialSize, int initialGrowthRate, int sizeGrowthCorrelation);

    ~Plant() override = default;

    void simulateDay() override;

    int getCurrentSize();

private:
    int m_initialSize;
    int m_initialGrowthRate;
    int m_sizeGrowthCorrelation;

    int m_currentSize;
};

#endif // SLIMAKS_PLANT_H
