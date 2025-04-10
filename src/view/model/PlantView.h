#pragma once

#include <QGraphicsPixmapItem>
#include <QVector>
#include <QPixmap>

/**
 * @class PlantView
 * @brief Widok rośliny w symulacji.
 *
 * Klasa PlantView służy do wyświetlania graficznej reprezentacji rośliny w akwarium.
 * Umożliwia zmianę wyglądu w zależności od etapu wzrostu.
 */
class PlantView : public QGraphicsPixmapItem {
public:
    /**
     * @brief Konstruktor widoku rośliny.
     * @param parent Wskaźnik na element nadrzędny, domyślnie nullptr.
     */
    explicit PlantView(QGraphicsItem *parent = nullptr);

    /**
     * @brief Ustawia etap wzrostu rośliny.
     *
     * W zależności od przekazanego etapu, wyświetlany obraz zostanie zmieniony.
     *
     * @param stage Etap wzrostu, który określa wybrany obraz z kolekcji.
     */
    void setGrowthStage(int stage);

private:
    QVector<QPixmap> m_pixmaps; ///< Kolekcja obrazów reprezentujących różne etapy wzrostu rośliny.
};
