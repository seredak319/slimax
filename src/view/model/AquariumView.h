#ifndef AQUARIUMVIEW_H
#define AQUARIUMVIEW_H

#include <QGraphicsView>
#include "model/Aquarium.h"
#include "PlantView.h"
#include "SnailView.h"

/**
 * @class AquariumView
 * @brief Widok akwarium symulacji.
 *
 * Klasa AquariumView dziedziczy po QGraphicsView i odpowiada za wizualizację akwarium.
 * Renderuje organizmy (rośliny i ślimaki) i obsługuje animacje ich ruchu.
 */
class AquariumView : public QGraphicsView {
Q_OBJECT

public:
    /**
     * @brief Konstruktor AquariumView.
     * @param parent Wskaźnik na widget rodzica (opcjonalnie).
     */
    AquariumView(QWidget *parent = nullptr);

    /**
     * @brief Aktualizuje widok akwarium.
     *
     * Rysuje organizmy znajdujące się w modelu akwarium. Jeśli isAnimated jest true,
     * ślimaki są animowane podczas zmiany pozycji.
     *
     * @param aquarium Referencja do modelu akwarium.
     * @param isAnimated Flaga wskazująca, czy użyć animacji.
     */
    void updateView(const Aquarium &aquarium, const bool isAnimated);

private:
    QGraphicsScene *m_scene;                 ///< Scena graficzna widoku.
    std::vector<PlantView *> m_plantViews;     ///< Widoki roślin.
    std::vector<SnailView *> m_snailViews;     ///< Widoki ślimaków.

    /**
     * @brief Animuje ruch ślimaka.
     *
     * Przesuwa widok ślimaka płynnie z pozycji startPos do endPos w kilku krokach.
     *
     * @param snailView Widok ślimaka.
     * @param startPos Początkowa pozycja.
     * @param endPos Docelowa pozycja.
     */
    void animateSnailMovement(SnailView *snailView, const QPointF &startPos, const QPointF &endPos);

    /**
     * @brief Przesuwa ślimaka bez animacji.
     *
     * Natychmiast ustawia widok ślimaka na docelowej pozycji.
     *
     * @param snailView Widok ślimaka.
     * @param targetPos Docelowa pozycja.
     */
    void moveWithoutAnimation(SnailView *snailView, const QPointF &targetPos);

    static const int BASE_ANIMATION_DELAY;       ///< Podstawowe opóźnienie animacji.
    static const int BASE_ANIMATION_STEPS_NUMBER;  ///< Liczba kroków animacji.
};

#endif
