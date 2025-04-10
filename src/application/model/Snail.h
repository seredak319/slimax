#ifndef SLIMAKS_SNAIL_H
#define SLIMAKS_SNAIL_H


#include "model/base/Organism.h"

/**
 * @class Snail
 * @brief Reprezentuje ślimaka w symulacji
 *
 * Ślimak ma wiek, apetyt, tempo wzrostu. Żywi się roślinami.
 */
class Snail : public Organism {

public:

    Snail(int x, int initialAge, int initialAppetite, int initialGrowthRate,
          int appetiteAgeCorrelation);

    ~Snail() override = default;

    void simulateDay() override;

    int getCurrentSize();

    int getAppetite() const;

    int getAppetiteAgeCorrelation() const;

    int getBaseSnailEatingValue() const;

    void setNearbyPlantNumber(int n);

    int getNearbyPlantNumber() const;

    bool isMaximumAge() const;

private:
    int m_initialAppetite;    ///< Bieżąca żarłoczność
    int m_currentSize;
    int m_snailVolume;
    int m_initialGrowthRate;  ///< Tempo wzrostu żarłoczności
    int m_appetiteAgeCorrelation;
    int m_nearbyPlantNumber;


    static const int MAXIMAL_SNAIL_GROWTH_STATE;           // maksymalny stan wzrostu (np. 11)
    static const int BASE_SNAIL_GROWTH_VALUE;              // bazowa wartość przyrostu "objętości" ślimaka
    static const int BASE_SNAIL_EATING_VALUE;              // podstawowa wartość zjadania przez ślimaka
    static const int SNAIL_GROWTH_THRESHOLD_LEVEL_VALUE;
};


#endif
