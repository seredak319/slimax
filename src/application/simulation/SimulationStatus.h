#ifndef SIMULATIONSTATE_H
#define SIMULATIONSTATE_H

/**
 * @enum SimulationStatus
 * @brief Określa stan symulacji.
 *
 * Enum SimulationStatus reprezentuje możliwe stany symulacji:
 * - Continue: symulacja trwa,
 * - IterationLimit: osiągnięto limit iteracji,
 * - AllPlantsDead: brak żywych roślin,
 * - AllSnailsAtMaxAge: wszystkie ślimaki osiągnęły maksymalny wiek.
 */
enum class SimulationStatus {
    Continue,
    IterationLimit,
    AllPlantsDead,
    AllSnailsAtMaxAge
};

#endif
