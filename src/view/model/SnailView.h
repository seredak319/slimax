#pragma once

#include <QGraphicsPixmapItem>
#include <QPixmap>

/**
 * @class SnailView
 * @brief Graficzna reprezentacja ślimaka w symulacji.
 *
 * Klasa SnailView odpowiada za wyświetlanie ślimaka w akwarium i
 * umożliwia zmianę wyglądu w zależności od etapu wzrostu.
 */
class SnailView : public QGraphicsPixmapItem {
public:
    /**
     * @brief Konstruktor widoku ślimaka.
     * @param parent Wskaźnik na element nadrzędny, domyślnie nullptr.
     */
    explicit SnailView(QGraphicsItem *parent = nullptr);

    /**
     * @brief Ustawia etap wzrostu ślimaka.
     *
     * Na podstawie przekazanego etapu zmienia się wygląd ślimaka.
     *
     * @param stage Etap wzrostu.
     */
    void setGrowthStage(int stage);

private:
    QPixmap m_snailPixmap; ///< Obraz ślimaka.
    int m_currentStage;    ///< Aktualny etap wzrostu.
};
