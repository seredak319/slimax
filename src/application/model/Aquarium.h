#ifndef SLIMAKS_AQUARIUM_H
#define SLIMAKS_AQUARIUM_H

#include <vector>
#include <memory>
#include "model/base/Organism.h"

struct SimulationState {
    int currentIteration = 0;
    int totalIterations = 0;
};

class Aquarium {
public:
    explicit Aquarium(int totalIterations);
    ~Aquarium() = default;

    // Dodajemy shared_ptr zamiast surowego wskaźnika
    void addOrganism(std::shared_ptr<Organism> organism);

    // Zwracamy const referencję do wektora shared_ptr
    const std::vector<std::shared_ptr<Organism>>& organisms() const;

    void simulateStep();

    int getCurrentIteration() const { return m_state.currentIteration; }
    int getTotalIterations() const { return m_state.totalIterations; }
    void increaseIteration() { ++m_state.currentIteration; }

private:
    std::vector<std::shared_ptr<Organism>> m_organisms;
    SimulationState m_state;
};

#endif // SLIMAKS_AQUARIUM_H
