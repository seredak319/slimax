#ifndef SLIMAKS_SIMULATIONCONTEXT_H
#define SLIMAKS_SIMULATIONCONTEXT_H

#pragma once

/**
 * @class SimulationContext
 * @brief Przechowuje ustawienia symulacji.
 *
 * Klasa ta zawiera wszystkie parametry wejściowe potrzebne do
 * zainicjalizowania symulacji, takie jak liczba ślimaków, roślin,
 * ich parametry wzrostu oraz ustawienia symulacji.
 */
class SimulationContext {
public:
    /**
     * @brief Konstruktor.
     *
     * @param numSnails Liczba ślimaków.
     * @param sAge Wiek ślimaka.
     * @param sAppetite Apetyt ślimaka.
     * @param sGrowthRate Tempo wzrostu ślimaka.
     * @param sAppetiteAgeCorrelation Korelacja między wiekiem a apetytem ślimaka.
     * @param numPlants Liczba roślin.
     * @param pVolume Objętość rośliny.
     * @param pGrowthRate Tempo wzrostu rośliny.
     * @param pSizeGrowthCorrelation Korelacja rozmiaru rośliny z jej wzrostem.
     * @param itCount Liczba iteracji symulacji.
     * @param aquariumWidth Szerokość akwarium.
     * @param isRandomEnabled true, jeśli losowość jest włączona.
     * @param randomRate Współczynnik losowości.
     */
    SimulationContext(int numSnails,
                      int sAge,
                      int sAppetite,
                      int sGrowthRate,
                      int sAppetiteAgeCorrelation,
                      int numPlants,
                      int pVolume,
                      int pGrowthRate,
                      int pSizeGrowthCorrelation,
                      int itCount,
                      int aquariumWidth,
                      bool isRandomEnabled,
                      int randomRate);

    /**
     * @brief Zwraca liczbę ślimaków.
     * @return Liczba ślimaków.
     */
    int numberOfSnails() const;

    /**
     * @brief Zwraca wiek ślimaka.
     * @return Wiek ślimaka.
     */
    int snailAge() const;

    /**
     * @brief Zwraca apetyt ślimaka.
     * @return Apetyt.
     */
    int snailAppetite() const;

    /**
     * @brief Zwraca tempo wzrostu ślimaka.
     * @return Tempo wzrostu.
     */
    int snailGrowthRate() const;

    /**
     * @brief Zwraca korelację między wiekiem a apetytem ślimaka.
     * @return Korelacja wieku i apetytu.
     */
    int snailAppetiteAgeCorrelation() const;

    /**
     * @brief Zwraca liczbę roślin.
     * @return Liczba roślin.
     */
    int numberOfPlants() const;

    /**
     * @brief Zwraca objętość rośliny.
     * @return Objętość rośliny.
     */
    int plantVolume() const;

    /**
     * @brief Zwraca tempo wzrostu rośliny.
     * @return Tempo wzrostu.
     */
    int plantGrowthRate() const;

    /**
     * @brief Zwraca korelację rozmiaru rośliny z jej wzrostem.
     * @return Korelacja.
     */
    int plantSizeGrowthCorrelation() const;

    /**
     * @brief Zwraca liczbę iteracji symulacji.
     * @return Liczba iteracji.
     */
    int iterationCount() const;

    /**
     * @brief Zwraca szerokość akwarium.
     * @return Szerokość akwarium.
     */
    int aquariumWidth() const;

    /**
     * @brief Sprawdza, czy losowość jest włączona.
     * @return true, jeśli losowość jest aktywna; false w przeciwnym razie.
     */
    bool isRandomEnabled() const;

    /**
     * @brief Zwraca współczynnik losowości.
     * @return Współczynnik losowości.
     */
    int randomRate() const;

private:
    int m_numberOfSnails;               ///< Liczba ślimaków.
    int m_snailAge;                     ///< Wiek ślimaka.
    int m_snailAppetite;                ///< Apetyt ślimaka.
    int m_snailGrowthRate;              ///< Tempo wzrostu ślimaka.
    int m_appetiteAgeCorrelation;       ///< Korelacja między wiekiem a apetytem.

    int m_numberOfPlants;               ///< Liczba roślin.
    int m_plantVolume;                  ///< Objętość rośliny.
    int m_plantGrowthRate;              ///< Tempo wzrostu rośliny.
    int m_plantSizeGrowthCorrelation;   ///< Korelacja rozmiaru rośliny z jej wzrostem.

    int m_iterationCount;               ///< Liczba iteracji symulacji.
    int m_aquariumWidth;                ///< Szerokość akwarium.

    int m_isRandomEnabled;              ///< Flaga losowości (true/false) - wpływa na początkowe ustawienia akwarium.
    int m_randomRate;                   ///< Współczynnik losowości.
};

#endif
