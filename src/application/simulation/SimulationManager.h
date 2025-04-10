#ifndef SLIMAKS_SIMULATIONMANAGER_H
#define SLIMAKS_SIMULATIONMANAGER_H

#pragma once

#include "simulation/input/SimulationContext.h"
#include "simulation/SimulationStatus.h"
#include "model/Aquarium.h"

/**
 * @class SimulationManager
 * @brief Zarządza symulacją akwarium.
 *
 * Klasa SimulationManager przeprowadza symulację akwarium,
 * wykonując etapy takie jak karmienie i aktualizację pozycji ślimaków.
 * Dostarcza również metodę zwracającą bieżący status symulacji.
 */
class SimulationManager {
public:
    /**
     * @brief Przeprowadza symulację dla podanego akwarium.
     *
     * Wykonuje wszystkie etapy symulacji, takie jak karmienie organizmów
     * oraz aktualizację pozycji ślimaków.
     *
     * @param aquarium Odwołanie do obiektu akwarium.
     */
    void simulate(Aquarium &aquarium);

    /**
     * @brief Zwraca bieżący status symulacji.
     *
     * Określa aktualny status symulacji na podstawie stanu akwarium.
     *
     * @param aquarium Odwołanie do obiektu akwarium.
     * @return Aktualny status symulacji.
     */
    SimulationStatus getCurrentSimulationStatus(Aquarium &aquarium);

private:
    /**
     * @brief Przeprowadza symulację karmienia organizmów w akwarium.
     *
     * Aktualizuje stan organizmów pod kątem pobierania pokarmu.
     *
     * @param aquarium Odwołanie do obiektu akwarium.
     */
    void simulateFeeding(Aquarium &aquarium);

    /**
     * @brief Aktualizuje pozycje ślimaków w akwarium.
     *
     * Przesuwa ślimaki, np. w kierunku roślin, na podstawie danych z akwarium.
     *
     * @param aquarium Odwołanie do obiektu akwarium.
     */
    void updateSnailPositions(Aquarium &aquarium);
};

#endif
