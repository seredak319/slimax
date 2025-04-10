#ifndef SLIMAKS_ORGANISM_H
#define SLIMAKS_ORGANISM_H

/**
 * @class Organism
 * @brief Bazowa klasa dla organizmów w symulacji.
 *
 * Definiuje interfejs (m.in. symulację dnia) dla wszystkich organizmów.
 */
class Organism {
public:
    /**
     * @brief Konstruktor ustawiający pozycję.
     * @param x Początkowa pozycja na osi X.
     */
    Organism(int x);

    /**
     * @brief Wirtualny destruktor.
     */
    virtual ~Organism() = default;

    /**
     * @brief Symuluje jeden cykl życia.
     */
    virtual void simulateDay() = 0;

    /**
     * @brief Zwraca pozycję na osi X.
     * @return Pozycja X.
     */
    int x() const;

    /**
     * @brief Ustawia pozycję na osi X.
     * @param newX Nowa pozycja.
     */
    void setX(int newX);

protected:
    int m_x; /**< Pozycja na osi X. */
};

#endif // SLIMAKS_ORGANISM_H
