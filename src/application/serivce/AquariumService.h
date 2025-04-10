#ifndef SLIMAKS_AQUARIUMSERVICE_H
#define SLIMAKS_AQUARIUMSERVICE_H

#include "model/Aquarium.h"
#include "simulation/input/SimulationContext.h"

/**
 * @class AquariumService
 * @brief Usługa inicjalizująca akwarium na podstawie kontekstu symulacji.
 *
 * Klasa AquariumService tworzy i konfiguruje obiekt akwarium zgodnie z danymi wejściowymi.
 */
class AquariumService {
public:
    /**
     * @brief Konstruktor domyślny.
     */
    AquariumService() = default;

    /**
     * @brief Inicjalizuje akwarium na podstawie kontekstu symulacji.
     * @param context Obiekt SimulationContext zawierający parametry symulacji.
     * @return Skonfigurowany obiekt Aquarium.
     */
    Aquarium initAquariumBasedOnApplicationContext(const SimulationContext &context);
};

#endif
