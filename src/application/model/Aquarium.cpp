#include "Aquarium.h"

Aquarium::Aquarium(int totalIterations)
        : m_state{0, totalIterations}
{
}

void Aquarium::addOrganism(std::shared_ptr<Organism> organism) {
    m_organisms.push_back(std::move(organism));
}

const std::vector<std::shared_ptr<Organism>>& Aquarium::organisms() const {
    return m_organisms;
}

void Aquarium::simulateStep() {
    for (auto &organism : m_organisms) {
        organism->simulateDay();
    }
    ++m_state.currentIteration;
}
