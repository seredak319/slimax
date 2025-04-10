#include "Organism.h"

Organism::Organism(int x) : m_x(x) {}

int Organism::x() const {
    return m_x;
}

void Organism::setX(int newX) {
    m_x = newX;
}