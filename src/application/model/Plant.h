#ifndef SLIMAKS_PLANT_H
#define SLIMAKS_PLANT_H

#include "model/base/Organism.h"

/**
 * @class Plant
 * @brief Reprezentuje roślinę w symulacji.
 *
 * Klasa Plant, dziedzicząca po Organism, opisuje zachowanie rośliny – jej wzrost,
 * zmiany rozmiaru oraz stan życia.
 */
class Plant : public Organism {
public:
    /**
     * @brief Konstruktor rośliny.
     * @param x Początkowa pozycja rośliny na osi X.
     * @param initialSize Początkowy rozmiar rośliny.
     * @param initialGrowthRate Początkowa szybkość wzrostu.
     * @param sizeGrowthCorrelation Korelacja między rozmiarem a wzrostem.
     */
    Plant(int x, int initialSize, int initialGrowthRate, int sizeGrowthCorrelation);

    /**
     * @brief Destruktor.
     */
    ~Plant() override = default;

    /**
     * @brief Symuluje jeden cykl życia rośliny.
     */
    void simulateDay() override;

    /**
     * @brief Zwraca aktualny rozmiar rośliny.
     * @return Aktualny rozmiar.
     */
    int getCurrentSize();

    /**
     * @brief Zwraca objętość rośliny.
     * @return Objętość rośliny.
     */
    int getPlantVolume() const;

    /**
     * @brief Sprawdza, czy roślina jest żywa.
     * @return true, jeśli roślina jest żywa, false w przeciwnym razie.
     */
    bool isPlantAlive() const;

    /**
     * @brief Redukuje rozmiar rośliny.
     * @param amount Wartość, o którą zmniejszyć rozmiar.
     */
    void reduceSize(int amount);

private:
    int m_currentSize;          /**< Aktualny rozmiar rośliny. */
    int m_plantVolume;          /**< Objętość rośliny. */
    int m_initialGrowthRate;    /**< Początkowa szybkość wzrostu. */
    int m_sizeGrowthCorrelation;/**< Korelacja między rozmiarem a wzrostem. */
    bool m_isAlive;             /**< True, gdy roślina jest żywa; false, gdy martwa. */

    static const int MAXIMAL_PLANT_GROWTH_STATE;                /**< Maksymalny stan wzrostu rośliny. */
    static const int BASE_PLANT_GROWTH_VALUE;                   /**< Podstawowa wartość wzrostu. */
    static const int BASE_PLANT_GROWTH_THRESHOLD_LEVEL_VALUE;   /**< Próg zmiany stanu wzrostu rośliny. */
};

#endif
