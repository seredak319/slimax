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

    Snail(int initialAge, double initialAppetite, double initialGrowthRate, double appetiteAgeCorrelation);

    ~Snail() override = default;

    void simulateDay() override {

    }

private:
    int m_initialAge;            ///< Wiek ślimaka
    double m_initialAppetite;    ///< Bieżąca żarłoczność
    double m_initialGrowthRate;  ///< Tempo wzrostu żarłoczności
};




#endif //SLIMAKS_SNAIL_H
