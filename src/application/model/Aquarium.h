#ifndef SLIMAKS_AQUARIUM_H
#define SLIMAKS_AQUARIUM_H

#include <vector>
#include <memory>
#include "model/base/Organism.h"

/**
 * @struct SimulationState
 * @brief Stan symulacji.
 */
struct SimulationState {
    int currentIteration = 0; /**< Obecna iteracja symulacji. */
    int totalIterations = 0;    /**< Całkowita liczba iteracji. */
};

/**
 * @class Aquarium
 * @brief Reprezentuje akwarium zawierające organizmy.
 *
 * Klasa zarządza organizmami i steruje przebiegiem symulacji.
 */
class Aquarium {
public:
    /**
     * @brief Konstruktor ustawiający całkowitą liczbę iteracji.
     * @param totalIterations Całkowita liczba iteracji symulacji.
     */
    explicit Aquarium(int totalIterations);

    /**
     * @brief Destruktor.
     */
    ~Aquarium() = default;

    /**
     * @brief Dodaje organizm do akwarium.
     * @param organism Wskaźnik do organizmu.
     */
    void addOrganism(std::shared_ptr<Organism> organism);

    /**
     * @brief Zwraca listę organizmów w akwarium.
     * @return Referencja do wektora organizmów.
     */
    const std::vector<std::shared_ptr<Organism>> &organisms() const;

    /**
     * @brief Wykonuje jeden krok symulacji.
     */
    void simulateStep();

    /**
     * @brief Zwraca numer bieżącej iteracji.
     * @return Numer bieżącej iteracji.
     */
    int getCurrentIteration() const { return m_state.currentIteration; }

    /**
     * @brief Zwraca całkowitą liczbę iteracji.
     * @return Całkowita liczba iteracji.
     */
    int getTotalIterations() const { return m_state.totalIterations; }

    /**
     * @brief Zwiększa licznik iteracji o jeden.
     */
    void increaseIteration() { ++m_state.currentIteration; }

private:
    std::vector<std::shared_ptr<Organism>> m_organisms; /**< Lista organizmów w akwarium. */
    SimulationState m_state; /**< Stan symulacji. */
};

#endif
