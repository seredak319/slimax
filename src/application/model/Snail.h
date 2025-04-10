#ifndef SLIMAKS_SNAIL_H
#define SLIMAKS_SNAIL_H

#include "model/base/Organism.h"

/**
 * @class Snail
 * @brief Reprezentuje ślimaka w symulacji.
 *
 * Ślimak ma wiek, apetyt oraz tempo wzrostu i żywi się roślinami.
 */
class Snail : public Organism {
public:
    /**
     * @brief Konstruktor ślimaka.
     * @param x Początkowa pozycja.
     * @param initialAge Początkowy wiek.
     * @param initialAppetite Początkowy apetyt.
     * @param initialGrowthRate Początkowe tempo wzrostu.
     * @param appetiteAgeCorrelation Korelacja między wiekiem a apetytem.
     */
    Snail(int x, int initialAge, int initialAppetite, int initialGrowthRate,
          int appetiteAgeCorrelation);

    /**
     * @brief Destruktor.
     */
    ~Snail() override = default;

    /**
     * @brief Symuluje jeden cykl życia (dzień) ślimaka.
     */
    void simulateDay() override;

    /**
     * @brief Zwraca aktualny rozmiar ślimaka.
     * @return Rozmiar ślimaka.
     */
    int getCurrentSize();

    /**
     * @brief Zwraca wartość apetytu.
     * @return Apetyt.
     */
    int getAppetite() const;

    /**
     * @brief Zwraca korelację między wiekiem a apetytem.
     * @return Korelacja wieku i apetytu.
     */
    int getAppetiteAgeCorrelation() const;

    /**
     * @brief Zwraca bazową wartość jedzenia.
     * @return Bazowa wartość zjadania.
     */
    int getBaseSnailEatingValue() const;

    /**
     * @brief Ustawia numer pobliskiej rośliny.
     * @param n Numer rośliny.
     */
    void setNearbyPlantNumber(int n);

    /**
     * @brief Zwraca numer pobliskiej rośliny.
     * @return Numer rośliny.
     */
    int getNearbyPlantNumber() const;

    /**
     * @brief Sprawdza, czy ślimak osiągnął maksymalny wiek.
     * @return true, jeśli osiągnięto maksymalny wiek; false w przeciwnym razie.
     */
    bool isMaximumAge() const;

private:
    int m_initialAppetite;     ///< Początkowy apetyt.
    int m_currentSize;         ///< Aktualny rozmiar.
    int m_snailVolume;         ///< Objętość ślimaka.
    int m_initialGrowthRate;   ///< Początkowe tempo wzrostu.
    int m_appetiteAgeCorrelation; ///< Korelacja między wiekiem a apetytem.
    int m_nearbyPlantNumber;   ///< Numer pobliskiej rośliny.

    static const int MAXIMAL_SNAIL_GROWTH_STATE;           ///< Maksymalny stan wzrostu.
    static const int BASE_SNAIL_GROWTH_VALUE;              ///< Bazowa wartość przyrostu.
    static const int BASE_SNAIL_EATING_VALUE;              ///< Podstawowa wartość zjadania.
    static const int SNAIL_GROWTH_THRESHOLD_LEVEL_VALUE;    ///< Próg wzrostu.
};

#endif
