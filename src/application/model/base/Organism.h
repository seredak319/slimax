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

    Organism(int x, int y);

    virtual ~Organism() = default;

    /**
     * @brief Metoda wywoływana co cykl symulacji, pozwala na wzrost, zmiany itp.
     */
    virtual void simulateDay() = 0;

    int x() const;

    int y() const;

    void setX(int newX);

    void setY(int newY);

protected:
    int m_x;
    int m_y;
};


#endif //SLIMAKS_ORGANISM_H
