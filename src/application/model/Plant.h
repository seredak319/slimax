#ifndef SLIMAKS_PLANT_H
#define SLIMAKS_PLANT_H

#include "model/base/Organism.h"

class Plant : public Organism {
public:
    Plant(int x, int initialSize, int initialGrowthRate, int sizeGrowthCorrelation);

    ~Plant() override = default;

    void simulateDay() override;

    int getCurrentSize();

    int getPlantVolume() const;

    bool isPlantAlive() const;

    void reduceSize(int amount);

private:
    int m_currentSize;
    int m_plantVolume;
    int m_initialGrowthRate;
    int m_sizeGrowthCorrelation;
    bool m_isAlive;

    static const int MAXIMAL_PLANT_GROWTH_STATE;                // maksymalny stan wzrostu rośliny
    static const int BASE_PLANT_GROWTH_VALUE;                   // podstawowa wartość zjadania przez ślimaka
    static const int BASE_PLANT_GROWTH_THRESHOLD_LEVEL_VALUE;   // poziom zmiany stanu wzrostu rośliny

};

#endif
