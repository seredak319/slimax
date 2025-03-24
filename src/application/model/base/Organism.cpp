#include "Organism.h"

Organism::Organism(int x, int y) : m_x(x), m_y(y) {}

int Organism::x() const {
    return m_x;
}

int Organism::y() const {
    return m_y;
}

void Organism::setX(int newX) {
    m_x = newX;
}

void Organism::setY(int newY) {
    m_y = newY;
}