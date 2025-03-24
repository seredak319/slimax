#pragma once

#include <QGraphicsPixmapItem>
#include <QPixmap>

class SnailView : public QGraphicsPixmapItem {
public:
    explicit SnailView(QGraphicsItem *parent = nullptr);

    // Ustawia poziom wzrostu (0..11) i przeskalowuje obrazek
    void setGrowthStage(int stage);

private:
    QPixmap m_snailPixmap;  // Oryginalny obrazek ślimaka
    int m_currentStage;     // Bieżący etap wzrostu (0..11)
};
