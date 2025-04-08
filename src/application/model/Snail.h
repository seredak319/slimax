//
// Created by Krystian on 15.03.2025.
//

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

    Snail(int x, int y, int initialAge, int initialAppetite, int initialGrowthRate,
          int appetiteAgeCorrelation);

    ~Snail() override = default;

    void simulateDay() override;

    int getCurrentSize();

    int getAppetite() const;

    int getAppetiteAgeCorrelation() const;


private:
    int m_initialAge;            ///< Wiek ślimaka
    int m_initialAppetite;    ///< Bieżąca żarłoczność
    int m_initialGrowthRate;  ///< Tempo wzrostu żarłoczności
    int m_appetiteAgeCorrelation;

    int m_currentSize;
};


#endif //SLIMAKS_SNAIL_H
