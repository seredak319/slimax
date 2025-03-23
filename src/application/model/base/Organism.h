//
// Created by Krystian on 15.03.2025.
//

#ifndef SLIMAKS_ORGANISM_H
#define SLIMAKS_ORGANISM_H

/**
 * @class Organism
 * @brief Klasa bazowa dla wszystkich żywych organizmów w symulacji.
 *
 * Definiuje interfejs wspólny (polimorfizm), np. metodę simulateDay().
 */
class Organism {

public:
    Organism() = default;

    virtual ~Organism() = default;

    /**
     * @brief Metoda wywoływana co cykl symulacji, pozwala na wzrost, zmiany itp.
     */
    virtual void simulateDay() = 0;
};


#endif //SLIMAKS_ORGANISM_H
